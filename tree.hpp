#ifndef TREE_HPP
#define TREE_HPP

#include "obstacle.hpp"

class Tree : public Obstacle
{
  private:
    
  public:
    Tree(SDL_Texture* texture, int x, int y){
      this->texture = texture;
      SDL_QueryTexture(texture, NULL, NULL, &this->rect.w, &this->rect.h);
      rect.w /= 6;
      rect.h /= 6;
      setpos(x, y);
      hitbox = rect;
      hitbox.h /=3;
      hitbox.w /=3;
      hitbox.y += 2*hitbox.h;
      hitbox.x += hitbox.w;
    }
};  

#endif