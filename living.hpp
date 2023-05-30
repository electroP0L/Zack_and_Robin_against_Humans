#ifndef LIVING_HPP
#define LIVING_HPP

#include "entity.hpp"
#include "attack.hpp"
#include "contexte.hpp"

class Living : public Entity
{
  protected:
    vector<Texture>* textures;
    int currentTextureIndex;
    Sprite sprite;
    int texSize;
    int halftexSize;

    float speed;
    vector<float> previousmv = {0.0f, 0.0f};

    Clock invincTimer;
    Time invincTime;
    Clock attackTimer;
    Time attackTime;
    int HP;
    int attackDamage;

  public:

    Sprite* getSprite() {return &sprite;}
    vector<float>* getPreviousmv() {return &previousmv;}
    void setposition(float x, float y) {sprite.setPosition(x, y);}

    virtual void bouger(Contexte* ctxt) = 0;
    bool checkCollision(vector<float>* mv, Contexte* ctxt);

    int getHP() {return HP;}
    FloatRect getHitbox() override {return sprite.getGlobalBounds();}
    void changeHP(int damage);
    virtual void attaquer(Contexte* ctxt, vector<float>* direction) = 0;

    virtual void changeTexture(vector<float>* mv);
};  

#endif