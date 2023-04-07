#include <stdlib.h>
#include <time.h>

#include "zombie.hpp"
#include "region.hpp"
#include "tree.hpp"
#include "rock.hpp"
#include "command.hpp"



int main(int argc, char** argv)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return 0;
	}

	SDL_Window* win = SDL_CreateWindow("Zack and Robin against Humans", // creates a window
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  SDL_Renderer* movingrend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Renderer* staticrend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

  SDL_Surface *surfacezombie, *surfacebackground, *surfacetree, *surfacerock;
  surfacezombie = IMG_Load("zombie.png");
  surfacebackground = IMG_Load("BG.png");
  surfacetree = IMG_Load("tree.png");
  surfacerock = IMG_Load("rock.png");

  SDL_Texture *texzombie, *texbackground, *textree, *texrock;
  texzombie = SDL_CreateTextureFromSurface(movingrend, surfacezombie);
  texbackground = SDL_CreateTextureFromSurface(staticrend, surfacebackground);
  textree = SDL_CreateTextureFromSurface(staticrend, surfacetree);
  texrock = SDL_CreateTextureFromSurface(staticrend, surfacerock);

  SDL_FreeSurface(surfacezombie);
  SDL_FreeSurface(surfacebackground);
  SDL_FreeSurface(surfacetree);
  SDL_FreeSurface(surfacerock);

  Zombie zombie = Zombie(texzombie, movingrend);

  std::vector<Obstacle> obstacles;
  for (int i = 0; i < 10; i++){
    if (i % 2 == 0){
      obstacles.push_back(Tree(texrock, staticrend, 100 + i * 100, 100 + i * 100));
    }
    else{
      obstacles.push_back(Rock(textree, staticrend, 100 + i * 100, 100 + i * 100));
    }
  }

  Region region = Region(texbackground, staticrend, obstacles);


  //Game loop
  int close = 0;
  SDL_RenderClear(staticrend);
  SDL_RenderCopy(region.getRenderer(), region.getBackground(), NULL, NULL);

  SDL_RenderPresent(staticrend);
  

  while(!close){
    SDL_Event event;

    const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
		// Events management
		while (SDL_PollEvent(&event)) { //Tant qu'il y a des évènements à traiter
      switch (event.type) {

        case SDL_QUIT:
          // handling of close button
            close = 1;
            break;
 
        case SDL_KEYDOWN: //Si une touche est enfoncée
          Command cmd = Command(keyboard_state);
          zombie.bouger(cmd);
        
        default:
          break;
      }
    }
    SDL_RenderClear(movingrend);

    SDL_RenderCopy(zombie.getRenderer(), zombie.getTexture(), NULL, &zombie.getHitbox());

    SDL_RenderPresent(movingrend);

    SDL_Delay(1000/60);
  }

  SDL_DestroyTexture(texzombie);
  SDL_DestroyTexture(texbackground);
  SDL_DestroyTexture(textree);
  SDL_DestroyTexture(texrock);

  SDL_DestroyRenderer(movingrend);
  SDL_DestroyRenderer(staticrend);

  SDL_DestroyWindow(win);

  SDL_Quit();
}