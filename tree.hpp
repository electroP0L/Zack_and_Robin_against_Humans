#ifndef TREE_HPP
#define TREE_HPP

#include "obstacle.hpp"

class Tree : public Obstacle
{
  private:
    
  public:
    Tree(Texture& texture, int x, int y){
      sprite.setTexture(texture);
      float scale = 1.0f / 6.0f;
      sprite.scale(scale, scale);
      setpos(x, y);
      hitbox = sprite.getGlobalBounds();
      hitbox.height /=3;
      hitbox.width /=3;
      hitbox.top += 2*hitbox.height;
      hitbox.left += hitbox.width;
    }
};  

#endif