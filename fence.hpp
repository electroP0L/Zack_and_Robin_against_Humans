#ifndef FENCE_HPP
#define FENCE_HPP

#include "obstacle.hpp"

class Fence : public Obstacle
{
  private:
    float scale = 1.0f / 10.0f;
    
  public:
    Fence(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2.0f;
      hitbox.top += hitbox.height;
    }
};

#endif