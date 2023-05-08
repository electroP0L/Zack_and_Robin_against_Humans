#ifndef TREE_HPP
#define TREE_HPP

#include "obstacle.hpp"

class Tree : public Obstacle
{
  private:
    
  public:
    Tree(Texture& texture, float x, float y){
      sprite.setTexture(texture);
      float scale = 1.0f / 4.0f;
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=5;
      hitbox.width /=6;
      hitbox.top += 4*hitbox.height;
      hitbox.left += 2.5f*hitbox.width;
    }
};  

#endif