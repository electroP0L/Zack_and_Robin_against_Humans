#include "map.hpp"

Map::Map(vector<Texture>& texbackground, vector<Texture>& texobs){
  vector<Obstacle> obs;

  //============== RÉGION 1 ==============
  //POSITIONNEMENT DES OBSTACLES
  obs.push_back(Tree(texobs[0], SCREEN_WIDTH/20, SCREEN_HEIGHT/3));
  obs.push_back(Tree(texobs[0], 15*SCREEN_WIDTH/20, SCREEN_HEIGHT/3 - 100));
  obs.push_back(Tree(texobs[0], 6*SCREEN_HEIGHT/10, 3*SCREEN_WIDTH/4));

  obs.push_back(Rock(texobs[1], 2*SCREEN_WIDTH/10, 8*SCREEN_HEIGHT/10));
  obs.push_back(Rock(texobs[1], 13*SCREEN_WIDTH/20, SCREEN_HEIGHT/3 + 50));
  obs.push_back(Rock(texobs[1], 17*SCREEN_WIDTH/20, 7*SCREEN_HEIGHT/10));  

  for (int i = 0; i < 10; i++){
    if((i != 4) && (i != 5) && (i != 6)){  obs.push_back(Fence(texobs[2], 100 * i, 10)); } 
  }

  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  map<String, vector<float>> waypoints;
  waypoints["Top"] = {4*SCREEN_WIDTH/10, 7*SCREEN_HEIGHT/10, 1}; //Sortie
  waypoints["Bottom"] = {-1, -1, 0}; //Entrée (vide)

  //POSITIONNEMENT DES POINTS DE SPAWN
  vector<vector<float>> spawn = {{SCREEN_WIDTH/2, SCREEN_HEIGHT/2} /*entrée*/, {SCREEN_WIDTH/2, 0}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[0], obs, spawn, waypoints));

  obs.clear();
  waypoints.clear();
  spawn.clear();

  //============== AUTRES RÉGIONS ==============

  for (int i = 1; i < 9; i++){
    for (int i = 0; i < 5; i++){  obs.push_back(Tree(texobs[0], rand() % (SCREEN_WIDTH - 175), rand() % (SCREEN_HEIGHT - 195)));  }
    for (int i = 0; i < 3; i++){  obs.push_back(Rock(texobs[1], rand() % (SCREEN_WIDTH - 84), rand() % (SCREEN_HEIGHT - 53)));  }
    for (int i = 0; i < 10; i++){  obs.push_back(Fence(texobs[2], rand() % (SCREEN_WIDTH - 175), rand() % (SCREEN_HEIGHT - 195)));  }

    waypoints["Top"] = {4*SCREEN_WIDTH/10, 7*SCREEN_HEIGHT/10, 1};
    waypoints["Bottom"] = {4*SCREEN_WIDTH/10, 7*SCREEN_HEIGHT/10, 0};

    spawn = {{SCREEN_WIDTH/2, SCREEN_HEIGHT/2} /*entrée*/, {SCREEN_WIDTH/2, 0}} /*sortie*/;


    regions.push_back(Region(texbackground[i], obs, spawn, waypoints));
    obs.clear();
    waypoints.clear();
  }
  
  currentRegionIndex = -1;
  previousRegionIndex = -2;
}

void Map::loadRegion(Zombie& zombie, Robot& robot, int direction){
  float z_dx = zombie.getSprite().getGlobalBounds().width/2;
  float r_dx = robot.getSprite().getGlobalBounds().width/2;
  if (direction == 1){ // Going to the next region
    currentRegionIndex++;
    previousRegionIndex++;
    currentRegion = &regions[currentRegionIndex];
    zombie.setposition(currentRegion->getspawnpoint(0)[0] - z_dx, currentRegion->getspawnpoint(0)[1]);
    robot.setposition(currentRegion->getspawnpoint(0)[0] + r_dx, currentRegion->getspawnpoint(0)[1]);
  }
  else if (direction == 0){ // Going to the previous region
    currentRegionIndex--;
    previousRegionIndex--;
    currentRegion = &regions[currentRegionIndex];
    zombie.setposition(currentRegion->getspawnpoint(1)[0] - z_dx, currentRegion->getspawnpoint(1)[1]);
    robot.setposition(currentRegion->getspawnpoint(1)[0] + r_dx, currentRegion->getspawnpoint(1)[1]);
  }

}