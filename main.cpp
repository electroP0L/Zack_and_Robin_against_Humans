#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "zombie.hpp"
#include "region.hpp"
#include "tree.hpp"
#include "rock.hpp"
#include "command.hpp"



int main(int argc, char** argv)
{
  srand(time(NULL));

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return 0;
	}

	SDL_Window* win = SDL_CreateWindow("Zack and Robin against Humans", // creates a window
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);


  SDL_Surface *surfacezombie, *surfacebackground, *surfacetree, *surfacerock;
  surfacezombie = IMG_Load("zombie.png");
  surfacebackground = IMG_Load("BG.jpg");
  surfacetree = IMG_Load("tree.png");
  surfacerock = IMG_Load("rock.png");

  SDL_Texture *texzombie, *texbackground, *textree, *texrock;
  texzombie = SDL_CreateTextureFromSurface(rend, surfacezombie);
  texbackground = SDL_CreateTextureFromSurface(rend, surfacebackground);
  textree = SDL_CreateTextureFromSurface(rend, surfacetree);
  texrock = SDL_CreateTextureFromSurface(rend, surfacerock);

  SDL_FreeSurface(surfacezombie);
  SDL_FreeSurface(surfacebackground);
  SDL_FreeSurface(surfacetree);
  SDL_FreeSurface(surfacerock);

  Zombie zombie = Zombie(texzombie);

  std::vector<Obstacle> obstacles;
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Rock(texrock, rand() % (SCREEN_WIDTH - 61), rand() % (SCREEN_HEIGHT - 60)));
  }
  for (int i = 0; i < 5; i++){
    obstacles.push_back(Tree(textree, rand() % (SCREEN_WIDTH - 115), rand() % (SCREEN_HEIGHT - 127)));
  }


  Command cmd = Command(obstacles);
  Region region = Region(texbackground, rend, obstacles);


  //Game loop
  int close = 0;

  while(!close){
    SDL_Event event;

    const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
		// Events management
		while (SDL_PollEvent(&event)) { //Tant qu'il y a des évènements à traiter
      switch (event.type) {

        case SDL_QUIT: // handling of close button  
        {
          close = 1;
          break;
          //std::cout << "quit" << std::endl;
        }
 
        case SDL_KEYDOWN: //Si une touche est enfoncée
        {
          //std::cout << "keydown" << std::endl;
          cmd.SetKeyboardState(keyboard_state);
          zombie.bouger(cmd);
        }
        
        default:
          //std::cout << "default" << std::endl;
          break;
      }
    }

    SDL_RenderClear(rend);
    
    SDL_RenderCopy(region.getRenderer(), region.getTexBackground(), NULL, NULL);
    
    SDL_Rect rectz = zombie.getRect();
    SDL_RenderCopy(rend, texzombie, NULL, &rectz);

    for (int i = 0; i < region.getObstacles().size(); i++){
      SDL_Rect rect = region.getObstacles()[i].getRect();
      SDL_RenderCopy(rend, region.getObstacles()[i].getTexture(), NULL, &rect);
    }


    SDL_RenderPresent(rend);

    SDL_Delay(1000/60);
  }

  SDL_DestroyTexture(texzombie);
  SDL_DestroyTexture(texbackground);
  SDL_DestroyTexture(textree);
  SDL_DestroyTexture(texrock);

  SDL_DestroyRenderer(rend);

  SDL_DestroyWindow(win);

  SDL_Quit();

  return 0;
}