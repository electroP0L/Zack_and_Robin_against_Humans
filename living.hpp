#ifndef LIVING_HPP
#define LIVING_HPP

#include "entity.hpp"
#include "contexte.hpp"

class Living : public Entity
{
  protected:
    vector<Texture> textures;
    int currentTextureIndex;
    Sprite sprite;
    vector<float> previousMovements = {0.0f, 0.0f};

    
    int size;
    int halfsize;
  public:
    Sprite getSprite() {return sprite;}
    virtual void bouger(Contexte& ctxt) = 0;
    bool checkCollision(float& dx, float& dy, Contexte& ctxt);
    virtual void changeTexture(float& dx, float& dy) = 0;
    //virtual void attaquer() = 0;
};  


#endif