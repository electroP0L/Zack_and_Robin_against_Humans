#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "obstacle.hpp"

class Building : public Obstacle
{
  private:
    float scale = 1.0f / 2.5f;

  public:
    Building(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2;
      hitbox.top += hitbox.height;
    }
};  

#endif