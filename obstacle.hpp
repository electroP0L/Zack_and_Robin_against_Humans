#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "entity.hpp"

class Obstacle : public Entity
{
  protected:
    Sprite sprite;
  public:
    Obstacle(){}; //Constructeur par défaut
    Sprite getSprite() {return sprite;}
    void setpos(int& x, int& y) {sprite.setPosition(x, y);}
};  


#endif