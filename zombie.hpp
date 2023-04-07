#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "living.hpp"

class Zombie : public Living
{
  private:
    int nb_membres;
  public:
    Zombie(SDL_Texture* texture, SDL_Renderer* renderer);
    void bouger(Command cmd) override;
    //void attaquer();
};  

#endif