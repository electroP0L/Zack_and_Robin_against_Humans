#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"

class Zombie : public Living
{
  private:
    int nb_membres;
    const float scale = 1.0f/10.0f;
    float speed = 4.0f;
    
  public:
    Zombie(vector<Texture>& textures);
    void bouger(Contexte& ctxt) override;
    void changeTexture(float& dx, float& dy) override;
    //void attaquer();
};  

#endif