#ifndef BUS_HPP
#define BUS_HPP

#include "obstacle.hpp"

class Bus : public Obstacle
{
  private:
    float scale = 1.0f/3.5f;
    
  public:
    Bus(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      float scale = 1.0f;
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2.0f;
      hitbox.top += hitbox.height;
    }
};  

#endif