#ifndef CONTEXTE_HPP
#define CONTEXTE_HPP
 
//#include "region.hpp"
//#include "human.hpp"
#include "obstacle.hpp"
class Human;

#include <vector>

class Contexte {
  private:
    Clock clock;
    vector<Obstacle> obstacles;
    vector<Human>* humans; //vecteurs de pointeurs vers les observers (humans)
    FloatRect zombiePos;

    map<String, vector<float>> waypoints;
    vector<bool> changeRegion = {false, false}; //changeRegion[0] = doit-on changer de région ? //changeRegion[1] = en avant ou en arrière ?
    

    
  public:
    Contexte(vector<Obstacle> obstacles, vector<Human>* humans, map<String, vector<float>> waypoints){
      //On vide tous les vecteurs au préalable
      this->obstacles.clear(); this->waypoints.clear();
      this->obstacles = obstacles; this->humans = humans; this->waypoints = waypoints;
    }
    
    vector<Obstacle>& getObstacles() {return this->obstacles;}
    vector<Human>& getHumans() {return *humans;}

    map<String, vector<float>>& getWaypoints() {return this->waypoints;}
    vector<bool> getChangeRegion() {return this->changeRegion;}
    void setChangeRegion(bool change, int direction) {changeRegion.clear(); changeRegion.push_back(change); changeRegion.push_back(direction);}
    void setZombiePos(FloatRect& zombieHitbox)  {  zombiePos = zombieHitbox;}
    FloatRect& getZombiePos() {return this->zombiePos;}

    float getElapsedTime() {return this->clock.getElapsedTime().asMilliseconds();}
    void restartClock() {this->clock.restart();}
};

#endif