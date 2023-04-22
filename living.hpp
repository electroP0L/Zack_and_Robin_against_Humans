#ifndef LIVING_HPP
#define LIVING_HPP

#include "entity.hpp"
#include "command.hpp"

class Living : public Entity
{
  protected:
    vector<Texture> textures;
    Sprite sprite;
  public:
    Sprite getSprite() {return sprite;}
    virtual void bouger(Command& cmd) = 0;
    void checkCollision(float& dx, float& dy, Command& cmd);
    virtual void changeTexture(Command& cmd) = 0;
    //virtual void attaquer() = 0;
};  


#endif