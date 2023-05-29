#include "map.hpp"

Map::Map(vector<Texture>* texbackground, vector<Texture>* texobs, vector<Texture>* texhumans){
  
  vector<Obstacle*> obs;

  //============== RÉGION 1 ==============
  //POSITIONNEMENT DES OBSTACLES
  obs.push_back(new Tree(texobs->at(0), 50, 333));
  obs.push_back(new Tree(texobs->at(0), 750, 233));
  obs.push_back(new Tree(texobs->at(0), 600, 725));

  obs.push_back(new Rock(texobs->at(1), 200, 800));
  obs.push_back(new Rock(texobs->at(1), 650, 383));
  obs.push_back(new Rock(texobs->at(1), 850, 700));  

  for (int i = 0; i < 10; i++){
    if((i != 4) && (i != 5) && (i != 6)){  obs.push_back(new Fence(texobs->at(2), 100 * i, 10)); } 
  }

  //POSITIONNEMENT DES HUMAINS
  vector<Human*> humans;


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  map<String, vector<float>*> waypoints;
  waypoints["Top"] = new vector<float>{400, 700, 1}; //Sortie
  waypoints["Bottom"] = new vector<float>{-1, -1, 0}; //Entrée (vide)

  //POSITIONNEMENT DES POINTS DE SPAWN
  vector<vector<float>*> spawn = {new vector<float>{500, 500} /*entrée*/, new vector<float>{500, 10}}; /*sortie*/


  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(0), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 2 ==============
  //POSITIONNEMENT DES OBSTACLES


  //POSITIONNEMENT DES HUMAINS
  humans.push_back(new Human(texhumans, 500, 250));

  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Left"] = new vector<float>{300, 500, 1};
  waypoints["Bottom"] = new vector<float>{400, 700, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{500, 900} /*entrée*/, new vector<float>{50, 300}}; /*sortie*/

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(1), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 3 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)
    
  
  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Bottom"] = new vector<float>{500, 700, 1};
  waypoints["Right"] = new vector<float>{300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{900, 300} /*entrée*/, new vector<float>{550, 890}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(2), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 4 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Left"] = new vector<float>{300, 500, 1};
  waypoints["Top"] = new vector<float>{500, 700, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{550, 10} /*entrée*/, new vector<float>{100, 350}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(3), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();
  
  //============== RÉGION 5 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Top"] = new vector<float>{300, 500, 1};
  waypoints["Right"] = new vector<float>{300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{900, 300} /*entrée*/, new vector<float>{400, 10}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(4), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 6 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Top"] = new vector<float>{300, 500, 1};
  waypoints["Bottom"] = new vector<float>{300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{400, 900} /*entrée*/, new vector<float>{400, 10}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(5), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 7 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Right"] = new vector<float>{400, 600, 1};
  waypoints["Bottom"] = new vector<float>{300, 500, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{400, 900} /*entrée*/, new vector<float>{900, 450}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(6), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 8 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Right"] = new vector<float>{600, 800, 1};
  waypoints["Left"] = new vector<float>{400, 600, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{100, 450} /*entrée*/, new vector<float>{900, 650}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(7), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  spawn.clear();

  //============== RÉGION 9 ==============
  //POSITIONNEMENT DES OBSTACLES (pour l'instant vide)


  //POSITIONNEMENT DES WAYPOINTS (ENTRÉES/SORTIES)
  waypoints["Top"] = new vector<float>{-1, -1, 1};
  waypoints["Left"] = new vector<float>{600, 800, 0};

  //POSITIONNEMENT DES POINTS DE SPAWN
  spawn = {new vector<float>{100, 650} /*entrée*/, new vector<float>{500, 500}} /*sortie*/;

  //CRÉATION DE LA RÉGION
  regions.push_back(new Region(&texbackground->at(8), obs, humans, spawn, waypoints));

  obs.clear();
  humans.clear();
  waypoints.clear();
  //spawn.clear();

  //============== Initialisation ==============
  currentRegionIndex = -1;
  previousRegionIndex = -2;
}

void Map::loadRegion(Zombie* zombie, Robot* robot, int direction){
  float z_dx = zombie->getSprite()->getGlobalBounds().width/2;
  float r_dx = robot->getSprite()->getGlobalBounds().width/2;
  if (direction == 1){ // Going to the next region
    currentRegionIndex++;
    previousRegionIndex++;
    setCurrentRegion(regions[currentRegionIndex]);
    zombie->setposition(currentRegion->getspawnpoint(0)->at(0) - z_dx, currentRegion->getspawnpoint(0)->at(1));
    robot->setposition(currentRegion->getspawnpoint(0)->at(0) + r_dx, currentRegion->getspawnpoint(0)->at(1));
  }
  else if (direction == 0){ // Going to the previous region
    currentRegionIndex--;
    previousRegionIndex--;
    setCurrentRegion(regions[currentRegionIndex]);
    zombie->setposition(currentRegion->getspawnpoint(1)->at(0) - z_dx, currentRegion->getspawnpoint(1)->at(1));
    robot->setposition(currentRegion->getspawnpoint(1)->at(0) + r_dx, currentRegion->getspawnpoint(1)->at(1));
  }
}
