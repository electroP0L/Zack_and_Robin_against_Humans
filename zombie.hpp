#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"
#include "human.hpp"
#include "limb.hpp"

class Zombie : public Living
{
  private:
    const float scale = 1.0f/10.0f;
    Texture texlimb;
    
  public:
    Zombie(vector<Texture>& textures, Texture& texlimb);

    void bouger(Contexte& ctxt) override;
    void attaquer(Contexte& ctxt, vector<float> direction) override;
    void notifymovement(Contexte& ctxt);
};  

#endif