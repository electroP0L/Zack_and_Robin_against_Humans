#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"

class Zombie : public Living
{
  private:
    int nb_membres;
    const float scale = 1.0f/12.5f;
    
  public:
    Zombie(vector<Texture>& textures);
    void bouger(Command& cmd) override;
    void changeTexture(Command& cmd) override;
    //void attaquer();
};  

#endif