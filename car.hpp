#ifndef CAR_HPP
#define CAR_HPP

#include "obstacle.hpp"

class Car : public Obstacle
{
  private:
    float scale = 1.0f / 5.0f;

  public:
    Car(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2;
      hitbox.top += hitbox.height;
    }
};  

#endif