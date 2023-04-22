#include "zombie.hpp"
#include "region.hpp"
#include "tree.hpp"
#include "rock.hpp"
#include "command.hpp"


int main(int argc, char** argv)
{
  srand(time(NULL));

	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zack & Robin VS. Humans");


  Texture texbackground, textree, texrock;
  
  Texture texzombie1, texzombie2;
  vector<Texture> texzombie;

  
  texzombie1.loadFromFile("full_zombie1.png");
  texzombie.push_back(texzombie1);
  texzombie2.loadFromFile("full_zombie2.png");
  texzombie.push_back(texzombie2);
  
  texbackground.loadFromFile("BG1.png");
  textree.loadFromFile("tree1.png");
  texrock.loadFromFile("rock3.png");
  //cout << "Textures loaded" << endl;


  Zombie zombie = Zombie(texzombie);

  vector<Obstacle> obstacles;
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Rock(texrock, rand() % (SCREEN_WIDTH - 61), rand() % (SCREEN_HEIGHT - 60)));
  }
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Tree(textree, rand() % (SCREEN_WIDTH - 115), rand() % (SCREEN_HEIGHT - 127)));
  }

  //cout << "Obstacles created" << endl;


  Command cmd = Command(obstacles);
  Region region = Region(texbackground, obstacles);


  //Game loop
  window.setFramerateLimit(60);

  while(window.isOpen()){

    Event event;

		// Events management
    if (window.pollEvent(event)) { //Tant qu'il y a des évènements à traiter
      
      switch (event.type) {

        case Event::Closed : // handling of close button  
        {
          window.close();
          break;
          //cout << "quit" << endl;
        }
 
        case Event::KeyPressed : //Si une touche est enfoncée
        {
          //cout << "keydown" << endl;
          zombie.bouger(cmd);
        }
        
        default:
          //cout << "default" << endl;
          break;
      }
    }
    //Effement de la fenêtre
    window.clear();

    //Affichage des sprites
    // Le background rempli toute la fenêtre
    window.draw(region.getBackgroundSprite());
      
    window.draw(zombie.getSprite());
    for (int i = 0; i < region.getObstacles().size(); i++){
      window.draw(region.getObstacles()[i].getSprite());
    }

    window.display();
  }

  //On détruit tous les objets :

  window.close();

  return 0;
}