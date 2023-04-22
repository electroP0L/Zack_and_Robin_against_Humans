#ifndef LIVING_HPP
#define LIVING_HPP

#include "entity.hpp"
#include "command.hpp"

class Living : public Entity
{
  protected:
    //vector<Sprite> sprites;
    Sprite sprite;
  public:
    //Sprite getSprite(int i) {return sprites[i];}
    Sprite getSprite() {return sprite;}
    virtual void bouger(Command& cmd) = 0;
    void setpos(int x, int y) {sprite.setPosition(x, y);}
    //virtual void attaquer() = 0;
};  


#endif