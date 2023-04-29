#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"

class Zombie : public Living
{
  private:
    int nb_membres;
    const float scale = 1.0f/10.0f;
    float speed = 1.5f;
    
  public:
    Zombie(vector<Texture>& textures);
    void bouger(Contexte& ctxt) override;
    //void attaquer();
    void changeTexture(vector<float>& mv) override;
    //void notifymovement(Contexte& ctxt);
};  

#endif