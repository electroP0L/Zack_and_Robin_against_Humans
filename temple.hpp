#ifndef TEMPLE_HPP
#define TEMPLE_HPP

#include "obstacle.hpp"

class Temple : public Obstacle
{
  private:
    float scale = 1.0f / 3.0f;
    
  public:
    Temple(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2;
      hitbox.top += hitbox.height;
    }
};  

#endif
