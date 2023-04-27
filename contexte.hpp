#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "obstacle.hpp"
#include <vector>

class Contexte {
  private:
    Clock clock;
    vector<Obstacle> obstacles;
    //vector<Human> humans; //vecteurs d'observers
    

    
  public:
    Contexte(vector<Obstacle>& obstacles){this->obstacles = obstacles;}
    
    vector<Obstacle>& getObstacles() {return this->obstacles;}
    //vector<Human>& getHumans() {return this->humans;}

    float getElapsedTime() {return this->clock.getElapsedTime().asMilliseconds();}
    void restartClock() {this->clock.restart();}
};

#endif