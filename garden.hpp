#ifndef GARDEN_HPP
#define GARDEN_HPP

#include "obstacle.hpp"

class Garden : public Obstacle
{
  private:
    
  public:
    Garden(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      float scale = 1.0f / 9.0f;
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2;
      hitbox.top += hitbox.height;
    }
};  

#endif
