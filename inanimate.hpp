#ifndef INANIMATE_HPP
#define INANIMATE_HPP

#include "entity.hpp"

class Inanimate : public Entity
{
  protected:
    Sprite sprite;
  public:
    //Inanimate(){}; //Constructeur par défaut
    //~Inanimate(){}; //Destructeur
    virtual Sprite getSprite(){return sprite;}
    void setpos(float x, float y) {sprite.setPosition(x, y);}
};

#endif