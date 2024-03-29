#ifndef ROCK_HPP
#define ROCK_HPP

#include "obstacle.hpp"

class Rock : public Obstacle
{
  private:
    float scale = 1.0f / 12.0f;

  public:
    Rock(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=2;
      hitbox.top += hitbox.height;
    }
};  

#endif