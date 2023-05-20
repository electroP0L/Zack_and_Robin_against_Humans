#include "zombie.hpp"
#include "robot.hpp"
#include "map.hpp"

String path = "Bureau/Informatique/"; // Chemin vers le dossier contenant le projet

int main(int argc, char** argv)
{
  srand(time(NULL));

	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zack & Robin VS. Humans");
  Image icon;

  if(!icon.loadFromFile("application/icon.png")){  icon.loadFromFile(path + "Zack_and_Robin_against_Humans/application/icon.png"); }
  window.setIcon(48, 48, icon.getPixelsPtr());

  Texture iconTexture;
  iconTexture.loadFromImage(icon);

  //============== CHARGEMENT DU GAME OVER ==============
  Font font;
  if(!font.loadFromFile("fonts/gooddog.ttf")){  font.loadFromFile(path + "Zack_and_Robin_against_Humans/fonts/gooddog.ttf"); }
  Text gameOverText;
  gameOverText.setFont(font);
  gameOverText.setString("GAME OVER");
  gameOverText.setCharacterSize(185);
  gameOverText.setOutlineColor(Color::Black);
  gameOverText.setFillColor(Color(200, 0, 0));
  gameOverText.setPosition(sf::Vector2f(5, 50));

  Text ZaRaHText;
  if(!font.loadFromFile("fonts/Branda-yolq.ttf")){  font.loadFromFile(path + "Zack_and_Robin_against_Humans/fonts/Branda-yolq.ttf"); }  
  ZaRaHText.setFont(font);
  ZaRaHText.setString("Zack & Robin against Humans");
  ZaRaHText.setCharacterSize(75);
  ZaRaHText.setFillColor(Color::Black);
  ZaRaHText.setPosition(sf::Vector2f(13, 800));

  Sprite iconSprite;
  iconSprite.setTexture(iconTexture);
  iconSprite.setScale(10, 10);
  iconSprite.setPosition(300 , 300);

  //============== GESTION DE LA FENÊTRE ET ALLOCATION DES TEXTURES ==============

  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  Texture tex, texlimb;
  vector<Texture> texzombie;
  vector<Texture> texrobot;
  vector<Texture> texhuman;
  vector<Texture> texobs;
  vector<Texture> texbackground;
  vector<Texture> texattackperdirection;
  vector<vector<Texture>> texattackspercaracter;
  vector<vector<vector<Texture>>> texattacks;



  //============== ZOMBIE ==============
  //GAUCHE
  //Immobile
  if(!tex.loadFromFile("sprites/zombie1.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1.png"); }
  texzombie.push_back(tex); //index 0
  if(!tex.loadFromFile("sprites/zombie1_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1_2.png"); }
  texzombie.push_back(tex); //index 1
  //Marche
  if(!tex.loadFromFile("sprites/zombie1_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1_3.png"); }
  texzombie.push_back(tex); //index 2
  if(!tex.loadFromFile("sprites/zombie1_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1_4.png"); }
  texzombie.push_back(tex); //index 3
  //DROITE
  //Immobile
  if(!tex.loadFromFile("sprites/zombie2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2.png");  }
  texzombie.push_back(tex); //index 4
  if(!tex.loadFromFile("sprites/zombie2_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2_2.png");  }
  texzombie.push_back(tex); //index 5
  //Marche
  if(!tex.loadFromFile("sprites/zombie2_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2_3.png");  }
  texzombie.push_back(tex); //index 6
  if(!tex.loadFromFile("sprites/zombie2_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2_4.png");  }
  texzombie.push_back(tex); //index 7
  

  //============== ROBOT ==============
  if(!tex.loadFromFile("sprites/robot1.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/robot1.png");  }
  texrobot.push_back(tex);
  if(!tex.loadFromFile("sprites/robot2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/robot2.png");  }
  texrobot.push_back(tex);

  //============== HUMAIN ==============
  //GAUCHE
  //Immobile
  if(!tex.loadFromFile("sprites/human1.png")){  if(!tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1.png"));  }
  texhuman.push_back(tex); //index 0
  if(!tex.loadFromFile("sprites/human1_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1_2.png");  }
  texhuman.push_back(tex); //index 1
  //Marche
  if(!tex.loadFromFile("sprites/human1_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1_3.png");  }
  texhuman.push_back(tex); //index 2
  if(!tex.loadFromFile("sprites/human1_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1_4.png");  }
  texhuman.push_back(tex); //index 3
  //DROITE
  //Immobile
  if(!tex.loadFromFile("sprites/human2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2.png");  }
  texhuman.push_back(tex); //index 4
  if(!tex.loadFromFile("sprites/human2_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2_2.png");  }
  texhuman.push_back(tex); //index 5
  //Marche
  if(!tex.loadFromFile("sprites/human2_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2_3.png");  }
  texhuman.push_back(tex); //index 6
  if(!tex.loadFromFile("sprites/human2_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2_4.png");  }
  texhuman.push_back(tex); //index 7

  //============== ATTAQUES ==============
  //Zombie
  if(!tex.loadFromFile("sprites/Zattack1R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack1R.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Zattack2R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack2R.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Zattack1L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack1L.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Zattack2L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack2L.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  texattacks.push_back(texattackspercaracter);
  texattackspercaracter.clear();

  //Robot
  if(!tex.loadFromFile("sprites/Rattack1T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1T.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2T.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Rattack1B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1B.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2B.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Rattack1R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1R.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2R.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Rattack1L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1L.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2L.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  texattacks.push_back(texattackspercaracter);
  texattackspercaracter.clear();

  //Human
  if(!tex.loadFromFile("sprites/Hattack1T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1T.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2T.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Hattack1B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1B.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2B.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Hattack1R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1R.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2R.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Hattack1L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1L.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2L.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  texattacks.push_back(texattackspercaracter);
  texattackspercaracter.clear();
  

  //============== BACKGROUNDS ==============
  for(int i = 1; i <= 9; i++){
    if(!tex.loadFromFile("sprites/BG" + to_string(i) + ".png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/BG" + to_string(i) + ".png");  }
    texbackground.push_back(tex);
  }

  //============== OBSTACLES ==============
  if(!tex.loadFromFile("sprites/tree.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/tree.png"); }
  texobs.push_back(tex); //Index 0
  if(!tex.loadFromFile("sprites/rock.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/rock.png"); }
  texobs.push_back(tex); //Index 1
  if(!tex.loadFromFile("sprites/fence.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/fence.png"); }
  texobs.push_back(tex); //Index 2
  if(!tex.loadFromFile("sprites/spaceship.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/spaceship.png"); }
  texobs.push_back(tex); //Index 3
  if(!tex.loadFromFile("sprites/fence2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/fence2.png"); }
  texobs.push_back(tex); //Index 4
  if(!tex.loadFromFile("sprites/bus.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/bus.png"); }
  texobs.push_back(tex); //Index 5
  if(!tex.loadFromFile("sprites/car.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/car.png"); }
  texobs.push_back(tex); //Index 6
  if(!tex.loadFromFile("sprites/building1.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/building1.png"); }
  texobs.push_back(tex); //Index 7
  if(!tex.loadFromFile("sprites/building2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/building2.png"); }
  texobs.push_back(tex); //Index 8
  if(!tex.loadFromFile("sprites/jungle_tree.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/jungle_tree.png"); }
  texobs.push_back(tex); //Index 9
  if(!tex.loadFromFile("sprites/head.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/head.png"); }
  texobs.push_back(tex); //Index 10
  if(!tex.loadFromFile("sprites/temple.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/temple.png"); }
  texobs.push_back(tex); //Index 11

  if(!texlimb.loadFromFile("sprites/limb.png")){  texlimb.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/limb.png"); }

  

  //================ CRÉATION DE LA MAP ET DU CONTEXTE =================

  Map map = Map(texbackground, texobs, texhuman);

  //============== CRÉATION DES OBJETS ==============
  Zombie zombie = Zombie(texzombie, texlimb);
  Robot robot = Robot(texrobot);


  //============== GAME LOOP ==============
  Clock clock;
  const Time timePerFrame = seconds(1.f/60.f);

  vector<bool> change = {false, 1};


  map.loadRegion(zombie, robot, change[1]);
  Region currentreg = map.getCurrentRegion();
  vector<Limb>& missingLimbs = zombie.getMissingLimbs();
  Contexte ctxt = Contexte(currentreg.getObstacles(), currentreg.getHumansptr(), currentreg.getWaypoints(), texattacks, missingLimbs);
  
  vector<Attack>& attacks = ctxt.getAttacks();


  while(window.isOpen()){
    
    //============== FERMETURE DE LA FENÊTRE ==============
    Event event;
    while(window.pollEvent(event)){
      if(event.type == Event::Closed){
        window.close();
      }
    }

    //============== GESTION DES ENTRÉES - MOUVEMENT DES SPRITES ==============
    
    zombie.bouger(ctxt);
    if (Keyboard::isKeyPressed(Keyboard::E)){zombie.attaquer(ctxt, zombie.getPreviousmv());}
    robot.bouger(ctxt);
    if (Keyboard::isKeyPressed(Keyboard::O)){robot.attaquer(ctxt, robot.getPreviousmv());}
    //============== GESTION DU TIMER D'ANIMATION ==============
    if(ctxt.getElapsedTime() > 500){
      ctxt.restartClock();
    }


    //============== GESTION DU CHANGEMENT DE RÉGION ==============
    change = ctxt.getChangeRegion();
    if(change[0]){
      map.loadRegion(zombie, robot, change[1]);
      currentreg = map.getCurrentRegion();
      ctxt.setChangeRegion(false, 0);
      ctxt = Contexte(currentreg.getObstacles(), currentreg.getHumansptr(), currentreg.getWaypoints(), texattacks, missingLimbs);
    }

    //============== AFFICHAGE ==============
    window.clear();
    window.draw(currentreg.getBackgroundSprite());

    //============== AFFICHAGE DES MEMBRES ==============
    zombie.updateLimbs(ctxt);
    missingLimbs = zombie.getMissingLimbs();
    if(missingLimbs.size() > 0){
      for (int i = 0; i < missingLimbs.size(); i++){
        window.draw(missingLimbs[i].getSprite());
        missingLimbs[i].updatepos();
      }
    }


    //============== AFFICHAGE DES VIVANTS ==============

    for (int i = 0; i < currentreg.getHumans().size(); i++){
      window.draw(currentreg.getHumans()[i].getSprite());
    }

    window.draw(zombie.getSprite());
    window.draw(robot.getSprite());

    //============== AFFICHAGE ET GESTION DES ATTAQUES ==============
    if(attacks.size() > 0){
      FloatRect zombieHitbox = zombie.getSprite().getGlobalBounds();
      FloatRect humanHitbox;
      for(int i = 0; i < attacks.size(); i++){ //Pour chaque attaque
        //cout << "Attack " << i << endl;
        if(attacks[i].getAttackTime().asMilliseconds() > 500){ //Si son temps est écoulé
          if(attacks[i].getTarget() == "Human"){  //Si elle vise un humain
          vector <Human>& humans = currentreg.getHumans();
            for (int j = 0; j < humans.size(); j++){
              humanHitbox = humans[j].getHitbox();
              if(attacks[i].hit(humanHitbox)){ //Et qu'elle touche
                humans[j].changeHP(-attacks[i].getDamage()); //On inflige des dégâts
                if (humans[j].getHP() <= 0){ //Si l'humain est mort
                  humans.erase(humans.begin() + j); //On le supprime
                }
              }
            }
          }
          if(attacks[i].getTarget() == "Zombie"){
            if(attacks[i].hit(zombieHitbox)){
              zombie.changeHP(-attacks[i].getDamage(), ctxt);
              if (zombie.getHP() <= 0){
                
                //On rend plus sombre la texture du background :
                Sprite gameoversprite = currentreg.getBackgroundSprite();
                gameoversprite.setColor(Color(100, 100, 100));

                //On affiche le Game Over :
                window.draw(gameoversprite);
                window.draw(gameOverText);
                window.draw(ZaRaHText);
                window.draw(iconSprite);
                window.display();

                sf::sleep(seconds(5));

                window.close();
                return 0;
              }
            }
          }

          //On supprime l'attaque du vecteur
          attacks.erase(attacks.begin() + i);
        }
        else{
          attacks[i].changeTexture();
          window.draw(attacks[i].getSprite());
        }
      }
    }

    //============== AFFICHAGE DES OBSTACLES ==============

    for (int i = 0; i < currentreg.getObstacles().size(); i++){
      window.draw(currentreg.getObstacles()[i].getSprite());
    }

    //============== RROVISOIRE : AFFICHAGE DES HP DU ZOMBIE EN HAUT À GAUCHE DE L'ÉCRAN ==============
    Text hp;
    hp.setFont(font);
    hp.setString("HP : " + to_string(zombie.getHP()));
    hp.setCharacterSize(50);
    //Couleur : rouge foncé
    hp.setFillColor(Color(200, 0, 0));
    hp.setPosition(sf::Vector2f(10, 110));
    window.draw(hp);

    window.display();

    //============== DÉLAI ENTRE CHAQUE FRAME  ==============
    sf::sleep(timePerFrame);
  }

  //============== FERMETURE DE LA FENÊTRE ==============
  window.close();

  return 0;
}