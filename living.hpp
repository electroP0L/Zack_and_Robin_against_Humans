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
    vector<float> previousmv = {0.0f, 0.0f};

    
    int size;
    int halfsize;
  public:
    Sprite getSprite() {return sprite;}
    vector <float> getPreviousmv() {return previousmv;}
    void setposition(float x, float y) {sprite.setPosition(x, y);}

    virtual void bouger(Contexte& ctxt) = 0;
    bool checkCollision(vector<float>& mv, Contexte& ctxt);
    virtual void changeTexture(vector<float>& mv) = 0;
    //virtual void attaquer() = 0;
};  


#endif