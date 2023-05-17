#ifndef HEAD_HPP
#define HEAD_HPP

#include "obstacle.hpp"

class Head : public Obstacle
{
  private:
    float scale = 1.0f / 6.0f;

  public:
    Head(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2;
      hitbox.top += hitbox.height;
    }
};  

#endif