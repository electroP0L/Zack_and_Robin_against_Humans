#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "obstacle.hpp"
#include <vector>

class Command {
  private:
    const Uint8 *keyboard_state;
    std::vector<Obstacle> obstacles;
    // Ajouter les vecteurs de commande au fur et à mesure
    
  public:
    Command(std::vector<Obstacle> obstacles){this->obstacles = obstacles;}
    void SetKeyboardState(const Uint8 *keyboard_state) {this->keyboard_state = keyboard_state;}
    const Uint8* getKeyboardState() {return this->keyboard_state;}
    std::vector<Obstacle> getObstacles() {return this->obstacles;}
};

#endif