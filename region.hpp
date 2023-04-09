#ifndef REGION_HPP
#define REGION_HPP

#include "obstacle.hpp"
#include "vector"
//#include "entity.hpp" ?

class Region
{

  private:
    SDL_Texture* texbackground;
    SDL_Renderer* renderer;
    int nb_obstacles;
    //int nb_entities; ?
    std::vector<Obstacle> obstacles;
    //std::vector<Entity> entities; ?

  public:
    Region(SDL_Texture* texbackground, SDL_Renderer* renderer, std::vector<Obstacle> obstacles){
      this->texbackground = texbackground;
      this->renderer = renderer;
      this->obstacles = obstacles;
      this->nb_obstacles = obstacles.size();
    }
    SDL_Texture* getTexBackground() {return texbackground;}
    SDL_Renderer* getRenderer() {return renderer;}
    std::vector<Obstacle> getObstacles() {return obstacles;}

    
    
  
};

#endif
