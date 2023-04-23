#include "zombie.hpp"
#include "region.hpp"
#include "tree.hpp"
#include "rock.hpp"
#include "contexte.hpp"

float z = 0.0f; //À SUPPRIMER SI ON TROUVE UN MEILLEUR MOYEN DE MODIFIER LES SPRITES DES LIVING IMMOBILES

int main(int argc, char** argv)
{
  srand(time(NULL));

	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zack & Robin VS. Humans");


  Texture texbackground, textree, texrock;
  
  Texture texz;
  vector<Texture> texzombie;

  //GAUCHE
  texz.loadFromFile("zombie1.png");
  texzombie.push_back(texz); //index 0
  texz.loadFromFile("zombie1_2.png");
  texzombie.push_back(texz); //index 1
  //DROITE
  texz.loadFromFile("zombie2.png");
  texzombie.push_back(texz); //index 2
  texz.loadFromFile("zombie2_2.png");
  texzombie.push_back(texz); //index 3
  
  texbackground.loadFromFile("BG.png");
  textree.loadFromFile("tree.png");
  texrock.loadFromFile("rock.png");
  //cout << "Textures loaded" << endl;


  Zombie zombie = Zombie(texzombie);

  vector<Obstacle> obstacles;
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Rock(texrock, rand() % (SCREEN_WIDTH - 84), rand() % (SCREEN_HEIGHT - 53)));
  }
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Tree(textree, rand() % (SCREEN_WIDTH - 175), rand() % (SCREEN_HEIGHT - 195)));
  }

  //cout << "Obstacles created" << endl;


  Contexte ctxt = Contexte(obstacles, zombie.getHitbox());
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
          zombie.bouger(ctxt);
        }
        
        default:
          //cout << "default" << endl;
          break;
      }
    }
    else {
      if(ctxt.getElapsedTime() > 500){
        ctxt.restartClock();
        zombie.changeTexture(z);
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