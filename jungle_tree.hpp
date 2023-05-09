#ifndef JUNGLETREE_HPP
#define JUNGLETREE_HPP

#include "obstacle.hpp"

class JungleTree : public Obstacle
{
  private:
    float scale = 1.0f / 4.0f;
    
  public:
    JungleTree(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=5;
      hitbox.width /=8;
      hitbox.top += 4*hitbox.height;
      hitbox.left += 3.0f*hitbox.width;
    }
};  

#endif
