#ifndef ENTITY_HPP
#define ENTITY_HPP

#define SCREEN_WIDTH 1000  //ÇA DEVRAIT ALLER DANS REGION_HPP
#define SCREEN_HEIGHT 1000

#include <stdlib.h>
#include <time.h>
#include <iostream>

#include <SFML/Graphics.hpp>
using namespace sf;

class Entity
{

  protected:
    Sprite sprite;

    FloatRect hitbox;
  
  public:
    Sprite getSprite() {return sprite;}
    FloatRect getHitbox() {return hitbox;}
    
    void setpos(int x, int y) {sprite.setPosition(x, y);}
};

#endif
