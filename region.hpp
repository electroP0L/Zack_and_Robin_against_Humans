#ifndef REGION_HPP
#define REGION_HPP

#include "obstacle.hpp"
#include "vector"
#include "map"
//#include "entity.hpp" ?


class Region
{

  private:
    Sprite background;
    int nb_obstacles;
    vector<Obstacle> obstacles;
    //vector<Human> humans;

    vector<vector<float>> spawn;  //spawn[0] = spawnpoint en avant //spawn[1] = spawnpoint en arrière
    map<String, vector<float>> waypoints;

  public:
    Region(Texture& texbackground, vector<Obstacle> obstacles, vector<vector<float>> spawn, map<String, vector<float>> waypoints){
      background.setTexture(texbackground);
      this->obstacles = obstacles;
      this->nb_obstacles = obstacles.size();
      this->spawn = spawn;
      this->waypoints = waypoints;
    }

    Sprite getBackgroundSprite() {return background;}
    vector<Obstacle> getObstacles() {return obstacles;}
    //vector<Human> getHumans() {return humans;}

    map<String, vector<float>> getWaypoints() {return waypoints;}

    vector<float> getspawnpoint(int i) {return spawn[i];}

    
    
  
};

#endif
