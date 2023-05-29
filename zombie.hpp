#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"
#include "human.hpp"
#include "limb.hpp"

class Zombie : public Living
{
  private:
    const float scale = 1.0f/10.0f;

    Texture* texlimb;
    vector<Limb*> missingLimbs; 
    
  public:
    Zombie(){}; //Constructeur par défaut
    Zombie(vector<Texture>* textures, Texture* texlimb);

    void bouger(Contexte* ctxt) override;
    void attaquer(Contexte* ctxt, vector<float>* direction) override;
    void notifymovement(Contexte* ctxt);

    void changeHP(int damage, Contexte* ctxt);
    vector<Limb*>* getMissingLimbs() {return &missingLimbs;}
    void updateLimbs(Contexte* ctxt);
};  

#endif