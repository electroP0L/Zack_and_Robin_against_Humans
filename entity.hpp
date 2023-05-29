#ifndef ENTITY_HPP
#define ENTITY_HPP

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Entity
{

  protected:
    FloatRect hitbox;
  
  public:
    virtual FloatRect getHitbox() {return hitbox;}
};

#endif
