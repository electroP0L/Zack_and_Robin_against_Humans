#ifndef ROCK_HPP
#define ROCK_HPP

#include "obstacle.hpp"

class Rock : public Obstacle
{
  private:
    
  public:
    Rock(Texture& texture, int x, int y){
      sprite.setTexture(texture);
      float scale = 1.0f / 20.0f;
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
    }
};  

#endif