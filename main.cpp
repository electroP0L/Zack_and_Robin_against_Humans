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

  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  Texture tex;
  vector<Texture> texzombie;
  vector<Texture> texrobot;
  vector<Texture> texhuman;
  vector<Texture> texobs;
  vector<Texture> texbackground;

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



  //============== DÉCOR ==============
  for(int i = 1; i <= 9; i++){
    if(!tex.loadFromFile("sprites/BG" + to_string(i) + ".png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/BG" + to_string(i) + ".png");  }
    texbackground.push_back(tex);
  }

  //============== OBSTACLES ==============
  if(!tex.loadFromFile("sprites/tree.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/tree.png"); }
  texobs.push_back(tex);
  if(!tex.loadFromFile("sprites/rock.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/rock.png"); }
  texobs.push_back(tex);
  if(!tex.loadFromFile("sprites/fence.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/fence.png"); }
  texobs.push_back(tex);
  

  //================ CRÉATION DE LA MAP ET DU CONTEXTE =================

  Map map = Map(texbackground, texobs, texhuman);

  //============== CRÉATION DES OBJETS ==============
  Zombie zombie = Zombie(texzombie);
  Robot robot = Robot(texrobot);


  //============== GAME LOOP ==============
  Clock clock;
  const Time timePerFrame = seconds(1.f/60.f);

  vector<bool> change = {false, 1};
  map.loadRegion(zombie, robot, change[1]);
  Region currentreg = map.getCurrentRegion();
  Contexte ctxt = Contexte(currentreg.getObstacles(), currentreg.getHumansptr(), currentreg.getWaypoints());


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
    robot.bouger(ctxt);

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
      ctxt = Contexte(currentreg.getObstacles(), currentreg.getHumansptr(), currentreg.getWaypoints());
    }

    //============== AFFICHAGE ==============
    window.clear();

    window.draw(currentreg.getBackgroundSprite());

    for (int i = 0; i < currentreg.getHumans().size(); i++){
      window.draw(currentreg.getHumans()[i].getSprite());
    }

    window.draw(zombie.getSprite());
    window.draw(robot.getSprite());

    for (int i = 0; i < currentreg.getObstacles().size(); i++){
      window.draw(currentreg.getObstacles()[i].getSprite());
    }

    window.display();

    //============== DÉLAI ENTRE CHAQUE FRAME  ==============
    sleep(timePerFrame);
  }

  //============== FERMETURE DE LA FENÊTRE ==============
  window.close();

  return 0;
}