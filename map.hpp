#ifndef MAP_HPP
#define MAP_HPP

#include "region.hpp"
#include "zombie.hpp"
#include "robot.hpp"
//#include "human.hpp"
#include "tree.hpp"
#include "rock.hpp"
#include "fence.hpp"

class Map {
  private:
    vector<Region> regions;
    Region* currentRegion;
    int currentRegionIndex;
    int previousRegionIndex;

  public:
    Map(vector<Texture>& texbackground, vector<Texture>& texobs);

    void setCurrentRegion(Region& region) {currentRegion = &region;}
    Region& getCurrentRegion() {return *currentRegion;}

    void loadRegion(Zombie& zombie, Robot& Robot, int direction);
};

#endif