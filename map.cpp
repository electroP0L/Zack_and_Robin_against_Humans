#include "map.hpp"

Map::Map(vector<Texture>& texbackground, vector<Texture>& texobs, vector<Texture>& texhumans){
  vector<Obstacle> obs;

  //============== RÉGION 1 ==============
  //POSITIONNEMENT DES OBSTACLES
  obs.push_back(Tree(texobs[0], 50, 333));
  obs.push_back(Tree(texobs[0], 750, 233));
  obs.push_back(Tree(texobs[0], 600, 725));

  obs.push_back(Rock(texobs[1], 200, 800));
  obs.push_back(Rock(texobs[1], 650, 383));
  obs.push_back(Rock(texobs[1], 850, 700));  

  for (int i = 0; i < 10; i++){
    if((i != 4) && (i != 5) && (i != 6)){  obs.push_back(Fence(texobs[2], 100 * i, 10)); } 
  }

  //POSITIONNEMENT DES HUMAINS
  vector<Human> humans;
  //humans.push_back(Human(texhumans, {500, 250}));


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  map<String, vector<float>> waypoints;
  waypoints["Top"] = {400, 700, 1}; //Sortie
  waypoints["Bottom"] = {-1, -1, 0}; //Entrée (vide)

  //POSITIONNEMENT DES POINTS DE SPAWN
  vector<vector<float>> spawn = {{500, 500} /*entrée*/, {500, 10}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[0], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 2 ==============
  //POSITIONNEMENT DES OBSTACLES

  //obs.push_back(Spaceship(texobs[3], 500, 500));

  //obs.push_back(Bus(texobs[5], 500, 500));

  //obs.push_back(Car(texobs[6], 500, 500));

  //obs.push_back(Building(texobs[7], 500, 200));

  //obs.push_back(Building(texobs[8], 500, 200));

  //obs.push_back(JungleTree(texobs[9], 500, 500));

  //obs.push_back(Head(texobs[10],500, 500));

  //obs.push_back(Temple(texobs[11], 300, 200));

  //obs.push_back(Fence(texobs[4], 700, 200));




  //POSITIONNEMENT DES HUMAINS
  humans.push_back(Human(texhumans, {500, 250}));

  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Left"] = {300, 500, 1};
  waypoints["Bottom"] = {400, 700, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{500, 900} /*entrée*/, {50, 300}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[1], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 3 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)
    
  
  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Bottom"] = {500, 700, 1};
  waypoints["Right"] = {300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{900, 300} /*entrée*/, {550, 890}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[2], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 4 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Left"] = {300, 500, 1};
  waypoints["Top"] = {500, 700, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{550, 10} /*entrée*/, {100, 350}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[3], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();
  
  //============== RÉGION 5 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Top"] = {300, 500, 1};
  waypoints["Right"] = {300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{900, 300} /*entrée*/, {400, 10}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[4], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 6 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Top"] = {300, 500, 1};
  waypoints["Bottom"] = {300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{400, 900} /*entrée*/, {400, 10}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[5], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 7 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Right"] = {400, 600, 1};
  waypoints["Bottom"] = {300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{400, 900} /*entrée*/, {900, 450}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[6], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 8 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Right"] = {600, 800, 1};
  waypoints["Left"] = {400, 600, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{100, 450} /*entrée*/, {900, 650}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[7], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 9 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Top"] = {-1, -1, 1};
  waypoints["Left"] = {600, 800, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {{100, 650} /*entrée*/, {500, 500}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(Region(texbackground[8], obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== Initialisation ==============
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
