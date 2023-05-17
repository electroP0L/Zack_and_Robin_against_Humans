#ifndef REGION_HPP
#define REGION_HPP

#include "human.hpp"

#include "tree.hpp"
#include "rock.hpp"
#include "fence.hpp"
#include "spaceship.hpp"
#include "bus.hpp"
#include "car.hpp"
#include "building.hpp"
#include "jungle_tree.hpp"
#include "head.hpp"
#include "temple.hpp"

#include "vector"
#include "map"


class Region
{

  private:
    Sprite background;
    vector<Obstacle> obstacles;
    vector<Human> humans;

    vector<vector<float>> spawn;  //spawn[0] = spawnpoint en avant //spawn[1] = spawnpoint en arrière
    map<String, vector<float>> waypoints;

  public:
    Region(Texture& texbackground, vector<Obstacle> obstacles, vector<Human> humans, vector<vector<float>> spawn, map<String, vector<float>> waypoints){
      background.setTexture(texbackground);
      this->obstacles = obstacles;
      this->humans = humans;
      this->spawn = spawn;
      this->waypoints = waypoints;
    }

    Sprite getBackgroundSprite() {return background;}
    vector<Obstacle>& getObstacles() {return obstacles;}
    vector<Human>* getHumansptr() {return &humans;}
    vector<Human>& getHumans() {return humans;}

    map<String, vector<float>> getWaypoints() {return waypoints;}

    vector<float> getspawnpoint(int i) {return spawn[i];}

    
    
  
};

#endif
