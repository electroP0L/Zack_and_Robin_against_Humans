#ifndef ENTITY_HPP
#define ENTITY_HPP

#define SCREEN_WIDTH 851  //ÇA DEVRAIT ALLER DANS REGION_HPP
#define SCREEN_HEIGHT 666

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class Entity
{

  protected:
    SDL_Rect rect;
    SDL_Rect hitbox;
    SDL_Texture* texture;
  
  public:
    SDL_Rect getRect() {return rect;}
    SDL_Rect getHitbox() {return hitbox;}
    SDL_Texture* getTexture() {return texture;}
    
    void setpos(int x, int y) {rect.x = x; rect.y = y;}
};

#endif
