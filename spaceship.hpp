#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "obstacle.hpp"

class Spaceship : public Obstacle
{
  private:
    float scale = 1.0f/2.0f;
    
  public:
    Spaceship(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2.5f;
      hitbox.top += hitbox.height;
    }
};  

#endif