#include "game.hpp"



Game::Game(String& path)
{
  srand(time(NULL));
  this->path = &path; 

  textureManager = new TextureManager(path);
  gameOverScreen = new GameOverScreen(textureManager->getFonts(), textureManager->getIcon());

  window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zack & Robin VS. Humans");

  window.setIcon(48, 48, textureManager->getIcon()->getPixelsPtr());
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  HPtext.setFont(textureManager->getFonts()->at(0));
  HPtext.setCharacterSize(75);
  HPtext.setOutlineColor(Color::Black);
  HPtext.setOutlineThickness(1);
  HPtext.setFillColor(Color(200, 0, 0));
  HPtext.setPosition(sf::Vector2f(10, 110));

  map = new Map(textureManager->getTexBackground(), textureManager->getTexObstacles(), textureManager->getTexHuman());

  zombie = new Zombie(textureManager->getTexZombie(), textureManager->getTexLimb());
  robot = new Robot(textureManager->getTexRobot());
  map->loadRegion(zombie, robot, 1);
  currentRegion = map->getCurrentRegion();

  ctxt = Contexte(currentRegion->getObstacles(), currentRegion->getHumans(), currentRegion->getWaypoints(), textureManager->getTexAttacks(), zombie->getMissingLimbs());

  attacks = ctxt.getAttacks();

  /*
  cout << "Taille tableau regions de la map : " << map->getRegions().size() << endl;

  cout << "Taille tableau humans de la region : " << map->getRegion(1)->getHumans()->size() << endl;
  cout << "Taille tableau obstacles de la region : " << map->getRegion(1)->getObstacles()->size() << endl;
  cout << "Taille tableau waypoints de la region : " << map->getRegion(1)->getWaypoints()->size() << endl;
  cout << "Taille tableau spawnpoints de la region : " << map->getRegion(1)->getSpawn()->size() << endl;
  */

}

void Game::run()
{
  while(window.isOpen()){
    //============== FERMETURE DE LA FENÊTRE ==============
    Event event;
    while(window.pollEvent(event)){
      if(event.type == Event::Closed){
        window.close();
        ctxt.~Contexte();
        return;
      }
    }

    //============== GESTION DES ENTRÉES - MOUVEMENT DES SPRITES ==============
    zombie->bouger(&ctxt);
    if (Keyboard::isKeyPressed(Keyboard::E)){zombie->attaquer(&ctxt, zombie->getPreviousmv());}

    robot->bouger(&ctxt);
    if (Keyboard::isKeyPressed(Keyboard::O)){robot->attaquer(&ctxt, robot->getPreviousmv());}

    //============== GESTION DU TIMER D'ANIMATION ==============
    if(ctxt.getElapsedTime() > 500){
      ctxt.restartClock();
    }

    //============== GESTION DU CHANGEMENT DE RÉGION ==============
    changeRegion = ctxt.getChangeRegion();
    if(changeRegion->at(0)){
      map->loadRegion(zombie, robot, changeRegion->at(1));
      currentRegion = map->getCurrentRegion();
      ctxt.setChangeRegion(false, 0);
      ctxt = Contexte(currentRegion->getObstacles(), currentRegion->getHumans(), currentRegion->getWaypoints(), textureManager->getTexAttacks(), missingLimbs);
    }

    //============== AFFICHAGE ==============
    display();

    //============== DÉLAI ENTRE CHAQUE FRAME  ==============
    sf::sleep(timePerFrame);
  }

  window.close();

  //MANAGEMENT DE LA MÉMOIRE :

  return;
}

void Game::manageRegionChange()
{
  changeRegion = ctxt.getChangeRegion();
  if(changeRegion->at(0)){
    map->loadRegion(zombie, robot, changeRegion->at(1));
    currentRegion = map->getCurrentRegion();
    ctxt.setChangeRegion(false, 0);
    ctxt = Contexte(currentRegion->getObstacles(), currentRegion->getHumans(), currentRegion->getWaypoints(), textureManager->getTexAttacks(), missingLimbs);
  }
}

void Game::display()
{
  //============== AFFICHAGE ==============
  window.clear();

  window.draw(*currentRegion->getBackgroundSprite());

  //============== AFFICHAGE DES MEMBRES ==============
  zombie->updateLimbs(&ctxt);
  missingLimbs = zombie->getMissingLimbs();
  if(missingLimbs->size() > 0){
    for(int i = 0; i < missingLimbs->size(); i++){
      window.draw(missingLimbs->at(i)->getSprite());
      missingLimbs->at(i)->updatepos();
    }
  }

  //============== AFFICHAGE DES VIVANTS ==============
  vector<Human*>* humans = currentRegion->getHumans();

  for(int i = 0; i < humans->size(); i++){
    window.draw(*humans->at(i)->getSprite());
  }

  window.draw(*zombie->getSprite());
  window.draw(*robot->getSprite());

  //============== TRAITEMENT ET AFFICHAGE DES ATTAQUES ==============
  if(attacks->size()>0){
    manageAttacks();
  }

  //============== AFFICHAGE DES OBSTACLES ==============
  for (int i = 0; i < currentRegion->getObstacles()->size(); i++){
    window.draw(currentRegion->getObstacles()->at(i)->getSprite());
  }

  //============== AFFICHAGE DES HP ==============
  HPtext.setString("HP : " + to_string(zombie->getHP()));
  window.draw(HPtext);

  window.display();
}

void Game::manageAttacks()
{
  if(attacks->size() > 0){
    FloatRect zombieHitbox = zombie->getSprite()->getGlobalBounds();
    FloatRect humanHitbox;

    for(int i = 0; i < attacks->size(); i++){ //Pour chaque attaque
      if(attacks->at(i)->getAttackTime().asMilliseconds() > 500){ //Si son temps est écoulé
        if(attacks->at(i)->getTarget() == "Human"){  //Si elle vise un humain
        vector <Human*>* humans = currentRegion->getHumans();
          for (int j = 0; j < humans->size(); j++){
            humanHitbox = humans->at(j)->getHitbox();
            if(attacks->at(i)->hit(&humanHitbox)){ //Et qu'elle touche
              humans->at(j)->changeHP(-attacks->at(i)->getDamage()); //On inflige des dégâts
              if (humans->at(j)->getHP() <= 0){ //Si l'humain est mort
                //On le delete
                delete humans->at(j);
                humans->erase(humans->begin() + j);
              }
            }
          }
        }
        if(attacks->at(i)->getTarget() == "Zombie"){
          if(attacks->at(i)->hit(&zombieHitbox)){
            zombie->changeHP(-attacks->at(i)->getDamage(), &ctxt);
            if (zombie->getHP() <= 0){
              
              Sprite* backgroundSprite = currentRegion->getBackgroundSprite();
              gameOverScreen->displayGameOver(&window, backgroundSprite);

              ctxt.~Contexte();
              return;
            }
          }
        }

        //On supprime l'attaque du vecteur
        delete attacks->at(i);
        attacks->erase(attacks->begin() + i);
      }
      else{
        attacks->at(i)->changeTexture();
        window.draw(attacks->at(i)->getSprite());
      }
    }
  }
}
