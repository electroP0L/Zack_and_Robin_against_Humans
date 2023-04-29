#ifndef REGION_HPP
#define REGION_HPP

#include "obstacle.hpp"
#include "vector"
//#include "entity.hpp" ?

class Region
{

  private:
    Sprite background;
    int nb_obstacles;
    vector<Obstacle> obstacles;
    //vector<Human> humans;

  public:
    Region(Texture& texbackground, std::vector<Obstacle> obstacles){
      background.setTexture(texbackground);
      this->obstacles = obstacles;
      this->nb_obstacles = obstacles.size();
    }
    Sprite getBackgroundSprite() {return background;}
    vector<Obstacle> getObstacles() {return obstacles;}
    //vector<Human> getHumans() {return humans;}

    
    
  
};

#endif
