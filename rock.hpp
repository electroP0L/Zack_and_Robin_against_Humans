#ifndef ROCK_HPP
#define ROCK_HPP

#include "obstacle.hpp"

class Rock : public Obstacle
{
  private:
    
  public:
    Rock(SDL_Texture* texture, int x, int y){
      this->texture = texture;
      SDL_QueryTexture(texture, NULL, NULL, &this->rect.w, &this->rect.h);
      rect.w /= 20;
      rect.h /= 20;
      setpos(x, y);
      hitbox = rect;
    }
};  

#endif