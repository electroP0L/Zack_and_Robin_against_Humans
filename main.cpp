#include "zombie.hpp"
#include "robot.hpp"
#include "region.hpp"
#include "tree.hpp"
#include "rock.hpp"
#include "contexte.hpp"

vector<float> z = {0.0f, 0.0f}; //À SUPPRIMER SI ON TROUVE UN MEILLEUR MOYEN DE MODIFIER LES SPRITES DES LIVING IMMOBILES

int main(int argc, char** argv)
{
  srand(time(NULL));

	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zack & Robin VS. Humans");


  Texture texbackground, textree, texrock;
  
  Texture tex;
  vector<Texture> texzombie;
  vector<Texture> texrobot;
  //vector<Texture> texhuman;

  //============== ZOMBIE ==============
  //GAUCHE
  //Immobile
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie1.png");
  texzombie.push_back(tex); //index 0
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie1_2.png");
  texzombie.push_back(tex); //index 1
  //Marche
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie1_3.png");
  texzombie.push_back(tex); //index 2
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie1_4.png");
  texzombie.push_back(tex); //index 3
  //DROITE
  //Immobile
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie2.png");
  texzombie.push_back(tex); //index 4
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie2_2.png");
  texzombie.push_back(tex); //index 5
  //Marche
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie2_3.png");
  texzombie.push_back(tex); //index 6
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/zombie2_4.png");
  texzombie.push_back(tex); //index 7
  

  //============== ROBOT ==============
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/robot1.png");
  texrobot.push_back(tex);
  tex.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/robot2.png");
  texrobot.push_back(tex);


  //============== DÉCOR ==============
  texbackground.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/BG1.png");
  textree.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/tree.png");
  texrock.loadFromFile("Bureau/Informatique/Zack_and_Robin_against_Humans/sprites/rock.png");
  //cout << "Textures loaded" << endl;


  //============== CRÉATION DES OBJETS ==============
  Zombie zombie = Zombie(texzombie);
  Robot robot = Robot(texrobot);

  vector<Obstacle> obstacles;
  for (int i = 0; i < 5; i++){  obstacles.push_back(Rock(texrock, rand() % (SCREEN_WIDTH - 84), rand() % (SCREEN_HEIGHT - 53)));  }
  for (int i = 0; i < 5; i++){  obstacles.push_back(Tree(textree, rand() % (SCREEN_WIDTH - 175), rand() % (SCREEN_HEIGHT - 195)));  }

  Region region1 = Region(texbackground, obstacles);
  Contexte ctxt = Contexte(region1);


  //============== GAME LOOP ==============
  window.setFramerateLimit(60);
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