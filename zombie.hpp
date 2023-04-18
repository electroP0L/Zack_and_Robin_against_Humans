#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"

class Zombie : public Living
{
  private:
    int nb_membres;
    const float scale = 1.0f/15.0f;

    float acceleration = 20.0f;
  public:
    Zombie(Texture& texture);
    void bouger(Command& cmd) override;
    //void attaquer();
};  

#endif