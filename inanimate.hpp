#ifndef INANIMATE_HPP
#define INANIMATE_HPP

#include "entity.hpp"

class Inanimate : public Entity
{
  protected:
    Sprite sprite;
  public:
    Inanimate(){}; //Constructeur par défaut
    Sprite getSprite() {return sprite;}
    void setpos(int& x, int& y) {sprite.setPosition(x, y);}
};

#endif