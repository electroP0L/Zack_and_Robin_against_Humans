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
  tex.loadFromFile("sprites/zombie1.png");
  texzombie.push_back(tex); //index 0
  tex.loadFromFile("sprites/zombie1_2.png");
  texzombie.push_back(tex); //index 1
  //Marche
  tex.loadFromFile("sprites/zombie1_3.png");
  texzombie.push_back(tex); //index 2
  tex.loadFromFile("sprites/zombie1_4.png");
  texzombie.push_back(tex); //index 3
  //DROITE
  //Immobile
  tex.loadFromFile("sprites/zombie2.png");
  texzombie.push_back(tex); //index 4
  tex.loadFromFile("sprites/zombie2_2.png");
  texzombie.push_back(tex); //index 5
  //Marche
  tex.loadFromFile("sprites/zombie2_3.png");
  texzombie.push_back(tex); //index 6
  tex.loadFromFile("sprites/zombie2_4.png");
  texzombie.push_back(tex); //index 7
  

  //============== ROBOT ==============
  tex.loadFromFile("sprites/robot1.png");
  texrobot.push_back(tex);
  tex.loadFromFile("sprites/robot2.png");
  texrobot.push_back(tex);


  //============== DÉCOR ==============
  texbackground.loadFromFile("sprites/BG1.png");
  textree.loadFromFile("sprites/tree.png");
  texrock.loadFromFile("sprites/rock.png");
  //cout << "Textures loaded" << endl;






  Zombie zombie = Zombie(texzombie);
  Robot robot = Robot(texrobot);

  vector<Obstacle> obstacles;
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Rock(texrock, rand() % (SCREEN_WIDTH - 84), rand() % (SCREEN_HEIGHT - 53)));
  }
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Tree(textree, rand() % (SCREEN_WIDTH - 175), rand() % (SCREEN_HEIGHT - 195)));
  }

  //cout << "Obstacles created" << endl;


  Contexte ctxt = Contexte(obstacles); //idéalement, le contexte devrait être construit à partir d'une région
  Region region = Region(texbackground, obstacles);


  //Game loop
  window.setFramerateLimit(60);
  Clock clock;
  const Time timePerFrame = seconds(1.f/60.f);

  while(window.isOpen()){
    
    //Gestion de la fermeture de la fenêtre
    Event event;
    while(window.pollEvent(event)){
      if(event.type == Event::Closed){
        window.close();
      }
    }

    //Gestion des entrées - Mouvement des sprites
    zombie.bouger(ctxt);
    robot.bouger(ctxt);

    //Gestion du timer d'animation
    if(ctxt.getElapsedTime() > 500){
      ctxt.restartClock();
    }

    //Effacement de la fenêtre
    window.clear();

    //Affichage des sprites
    window.draw(region.getBackgroundSprite());

    window.draw(zombie.getSprite());
    window.draw(robot.getSprite());
    for (int i = 0; i < region.getObstacles().size(); i++){
      window.draw(region.getObstacles()[i].getSprite());
    }

    window.display();

    //Pause pour respecter le délai entre chaque frame
    sleep(timePerFrame);
  }

  //On détruit tous les objets :
  window.close();

  return 0;
}