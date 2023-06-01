#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "obstacle.hpp"

class House : public Obstacle
{
  private:
    
  public:
    House(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      float scale = 1.0f / 3.0f;
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2;
      hitbox.top += hitbox.height;
    }
};  

#endif
