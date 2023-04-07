#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "obstacle.hpp"

class Command {
  private:
    const Uint8 *keyboard_state;
    // Ajouter les vecteurs de commande au fur et à mesure
    
  public:
    Command(const Uint8 *keyboard_state) {
      this->keyboard_state = keyboard_state;
    }
    const Uint8* getKeyboardState() {return this->keyboard_state;}
};

#endif;