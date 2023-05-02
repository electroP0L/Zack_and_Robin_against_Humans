#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"
#include "human.hpp"

class Zombie : public Living
{
  private:
    int nb_membres;
    const float scale = 1.0f/10.0f;
    
  public:
    Zombie(vector<Texture>& textures);
    void bouger(Contexte& ctxt) override;
    //void attaquer();
    void notifymovement(Contexte& ctxt);
};  

#endif