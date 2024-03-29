#ifndef MAP_HPP
#define MAP_HPP


#include "region.hpp"
#include "zombie.hpp"
#include "robot.hpp"

class Map {
  private:
    vector<Region*> regions;
    Region* currentRegion;
    int currentRegionIndex;
    int previousRegionIndex;

  public:
    Map(vector<Texture>* texbackground, vector<Texture>* texobs, vector<Texture>* texhumans);
    ~Map();

    void setCurrentRegion(Region* region) {currentRegion = region;}
    Region* getCurrentRegion() {return currentRegion;}
    int getCurrentRegionIndex() {return currentRegionIndex;}
    Region* getRegion(int index) {return regions[index];}

    void loadRegion(Zombie* zombie, Robot* Robot, int direction);


    vector<Region*> getRegions() {return regions;}
};

#endif