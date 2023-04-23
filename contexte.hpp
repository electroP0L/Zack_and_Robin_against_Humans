#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "obstacle.hpp"
#include <vector>

class Contexte {
  private:
    //Keyboard keyboard_state;
    vector<Obstacle> obstacles;
    Clock clock;

    FloatRect* zombiehitbox; 
    // Ajouter les vecteurs de Contexte au fur et à mesure
    
  public:
    Contexte(std::vector<Obstacle>& obstacles, FloatRect hitbox){this->obstacles = obstacles; this->zombiehitbox = &hitbox;}
    std::vector<Obstacle>& getObstacles() {return this->obstacles;}
    float getElapsedTime() {return this->clock.getElapsedTime().asMilliseconds();}
    void restartClock() {this->clock.restart();}
    void updateZombieHitbox(FloatRect hitbox) {this->zombiehitbox = &hitbox;}
};

#endif