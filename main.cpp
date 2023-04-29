#include "zombie.hpp"
#include "robot.hpp"
#include "region.hpp"
#include "tree.hpp"
#include "rock.hpp"
#include "fence.hpp"
#include "contexte.hpp"

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

  Texture texbackground, textree, texrock, texfence;
  
  Texture tex;
  vector<Texture> texzombie;
  vector<Texture> texrobot;
  //vector<Texture> texhuman;

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


  //============== DÉCOR ==============
  if(!texbackground.loadFromFile("sprites/BG1.png")){ texbackground.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/BG1.png");  }
  if(!textree.loadFromFile("sprites/tree.png")){  textree.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/tree.png"); }
  if(!texrock.loadFromFile("sprites/rock.png")){  texrock.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/rock.png"); }
  if(!texfence.loadFromFile("sprites/fence.png")){  texfence.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/fence.png"); }
  


  //============== CRÉATION DES OBJETS ==============
  Zombie zombie = Zombie(texzombie);
  Robot robot = Robot(texrobot);

  vector<Obstacle> obstacles;
  for (int i = 0; i < 3; i++){  obstacles.push_back(Rock(texrock, rand() % (SCREEN_WIDTH - 84), rand() % (SCREEN_HEIGHT - 53)));  }
  for (int i = 0; i < 3; i++){  obstacles.push_back(Tree(textree, rand() % (SCREEN_WIDTH - 175), rand() % (SCREEN_HEIGHT - 195)));  }
  for (int i = 0; i < 10; i++){  obstacles.push_back(Fence(texfence, rand() % (SCREEN_WIDTH - 175), rand() % (SCREEN_HEIGHT - 195)));  }

  Region region1 = Region(texbackground, obstacles);
  Contexte ctxt = Contexte(region1);


  //============== GAME LOOP ==============
  Clock clock;
  const Time timePerFrame = seconds(1.f/60.f);

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

    //============== AFFICHAGE ==============
    window.clear();

    window.draw(region1.getBackgroundSprite());

    window.draw(zombie.getSprite());
    window.draw(robot.getSprite());

    for (int i = 0; i < region1.getObstacles().size(); i++){
      window.draw(region1.getObstacles()[i].getSprite());
    }

    window.display();

    //============== DÉLAI ENTRE CHAQUE FRAME  ==============
    sleep(timePerFrame);
  }

  //============== FERMETURE DE LA FENÊTRE ==============
  window.close();

  return 0;
}