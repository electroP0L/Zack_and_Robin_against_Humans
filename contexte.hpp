#ifndef COMMAND_HPP
#define COMMAND_HPP
 
#include "region.hpp"
#include "obstacle.hpp"
#include <vector>

class Contexte {
  private:
    Clock clock;
    vector<Obstacle> obstacles;
    //vector<Human> humans; //vecteurs d'observers

    map<String, vector<float>> waypoints;
    vector<bool> changeRegion = {false, false}; //changeRegion[0] = doit-on changer de région ? //changeRegion[1] = en avant ou en arrière ?
    

    
  public:
    Contexte(Region& region){obstacles = region.getObstacles(); waypoints = region.getWaypoints();}
    
    vector<Obstacle>& getObstacles() {return this->obstacles;}
    //vector<Human>& getHumans() {return this->humans;}

    map<String, vector<float>>& getWaypoints() {return this->waypoints;}
    vector<bool> getChangeRegion() {return this->changeRegion;}
    void setChangeRegion(bool change, int direction) {changeRegion.clear(); changeRegion.push_back(change); changeRegion.push_back(direction);}

    float getElapsedTime() {return this->clock.getElapsedTime().asMilliseconds();}
    void restartClock() {this->clock.restart();}
};

#endif