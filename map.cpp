#include "map.hpp"

Map::Map(vector<Texture>* texbackground, vector<Texture>* texobs, vector<Texture>* texhumans){
  
  vector<Obstacle*> obs;
  //RAPPEL INDICES OBSTACLES :
  //0 : tree
  //1 : rock
  //2 : fence
  //3 : spaceship
  //4 : fence2
  //5 : bus
  //6 : car
  //7 : building1
  //8 : building2
  //9 : jungle_tree
  //10 : head
  //11 : temple

  //============== RÉGION 1 ==============
  //POSITIONNEMENT DES OBSTACLES
  for (int i = 0; i < 10; i++){
    if((i != 4) && (i != 5) && (i != 6)){  obs.push_back(new Fence(texobs->at(2), 100 * i, 10)); } 
  }

  obs.push_back(new Rock(texobs->at(1), 200, 800));
  obs.push_back(new Rock(texobs->at(1), 650, 383));
  obs.push_back(new Rock(texobs->at(1), 850, 700));  

  obs.push_back(new Tree(texobs->at(0), 50, 333));
  obs.push_back(new Tree(texobs->at(0), 750, 233));
  obs.push_back(new Tree(texobs->at(0), 600, 725));

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
    for (int i = 7; i < 10; i++){
    obs.push_back(new Fence(texobs->at(2), 100 * i, 10));
  }
  for (int i = 7; i < 10; i++){
    obs.push_back(new Fence(texobs->at(2), 100 * i, 300));
  }

  obs.push_back(new Rock(texobs->at(1), 485, 600));
  obs.push_back(new Rock(texobs->at(1), 350, 70));
  obs.push_back(new Rock(texobs->at(1), 850, 650));
  obs.push_back(new Rock(texobs->at(1), 200, 800));

  obs.push_back(new Car(texobs->at(6), 700, 50));

  obs.push_back(new Tree(texobs->at(0), 75, 350));
  obs.push_back(new Tree(texobs->at(0), 525, 170));
  obs.push_back(new Tree(texobs->at(0), 750, 700));
  obs.push_back(new Tree(texobs->at(0), 0, 50));

  //POSITIONNEMENT DES HUMAINS
  humans.push_back(new Human(texhumans, 300, 600));
  humans.push_back(new Human(texhumans, 825, 425));
  humans.push_back(new Human(texhumans, 900, 130));
  humans.push_back(new Human(texhumans, 800, 140));

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
  for (int i = 0; i < 4; i++){
    obs.push_back(new Fence(texobs->at(4), 25 + 100 * i, 300)); 
  }
  for (int i = 0; i < 3; i++){
    obs.push_back(new Fence(texobs->at(4), 50 + 100 * i, 600)); 
  }
  for (int i = 6; i < 8; i++){
    obs.push_back(new Fence(texobs->at(4), 75 + 100 * i - 50, 415)); 
  }
  obs.push_back(new Fence(texobs->at(2), 700, 700)); 
  obs.push_back(new Fence(texobs->at(2), 900, 700));

  obs.push_back(new Spaceship(texobs->at(3), 5, 400));

  obs.push_back(new Rock(texobs->at(1), 355, 600));
  obs.push_back(new Rock(texobs->at(1), 650, 500));
  obs.push_back(new Rock(texobs->at(1), 800, 200));

  obs.push_back(new Tree(texobs->at(0), 50, 700));
  obs.push_back(new Tree(texobs->at(0), 550, 100));

  //POSITIONNEMENT DES HUMAINS

  humans.push_back(new Human(texhumans, 50, 50));
  humans.push_back(new Human(texhumans, 400, 170));
  humans.push_back(new Human(texhumans, 50, 200));
  humans.push_back(new Human(texhumans, 450, 70));
  humans.push_back(new Human(texhumans, 900, 875));
  humans.push_back(new Human(texhumans, 700, 875));
  humans.push_back(new Human(texhumans, 800, 775));


  
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
  //POSITIONNEMENT DES OBSTACLES
  obs.push_back(new Rock(texobs->at(1),350,350));

  obs.push_back(new Fence(texobs->at(2),0,930));
  obs.push_back(new Fence(texobs->at(2),100,930));
  obs.push_back(new Fence(texobs->at(2),0,740));
  obs.push_back(new Fence(texobs->at(2),100,740));
  obs.push_back(new Fence(texobs->at(4),0,300));
  obs.push_back(new Fence(texobs->at(4),0,500));
  obs.push_back(new Fence(texobs->at(4),430,0));
  obs.push_back(new Fence(texobs->at(4),630,0));

  obs.push_back(new Car(texobs->at(6), 5, 780));
  obs.push_back(new Car(texobs->at(6), 5, 830));
  obs.push_back(new Car(texobs->at(6), 800, 580));
  obs.push_back(new Car(texobs->at(6), 600, 580));

  obs.push_back(new Bus(texobs->at(5),10, 580 ));

  obs.push_back(new Tree(texobs->at(0),100,100));
  obs.push_back(new Tree(texobs->at(0),650,50));
  obs.push_back(new Tree(texobs->at(0),150,750));

  obs.push_back(new Building(texobs->at(7), 570, 300));
  obs.push_back(new Building(texobs->at(7), 755, 300));


  //POSITIONNEMENT DES HUMAINS 
  humans.push_back(new Human(texhumans, 300, 600));
  humans.push_back(new Human(texhumans, 450, 450));
  humans.push_back(new Human(texhumans, 600, 700));
  humans.push_back(new Human(texhumans, 750, 700));
  humans.push_back(new Human(texhumans, 900, 700));
  humans.push_back(new Human(texhumans, 600, 880));
  humans.push_back(new Human(texhumans, 750, 880));
  humans.push_back(new Human(texhumans, 900, 880));


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
  //POSITIONNEMENT DES OBSTACLES

  for (int i = 3; i < 8; i++){
    if(i!=5){obs.push_back(new Fence(texobs->at(2), 100 * i - 50, 700));}
  }

  obs.push_back(new Rock(texobs->at(1),450,850));

  obs.push_back(new Car(texobs->at(6), 120, 350));
  obs.push_back(new Car(texobs->at(6), 830, 700));

  obs.push_back(new Bus(texobs->at(5),650,450));

  obs.push_back(new Tree(texobs->at(0),150,400));
  obs.push_back(new Tree(texobs->at(0),750,75));
  obs.push_back(new Tree(texobs->at(0),680,720));

  obs.push_back(new Building(texobs->at(8),500,50));
  obs.push_back(new Building(texobs->at(8),50,50));
  obs.push_back(new Building(texobs->at(7),20,700));

  //POSITIONNEMENT DES HUMAINS
  humans.push_back(new Human(texhumans, 500, 450));
  humans.push_back(new Human(texhumans, 75, 550));
  humans.push_back(new Human(texhumans, 350, 800));
  humans.push_back(new Human(texhumans, 600, 800));
  humans.push_back(new Human(texhumans, 300, 850));
  humans.push_back(new Human(texhumans, 650, 850));


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
  //POSITIONNEMENT DES OBSTACLES
  obs.push_back(new Tree(texobs->at(8),0,700));
  obs.push_back(new Tree(texobs->at(8),800,700));
  obs.push_back(new Tree(texobs->at(8),600,100));
  obs.push_back(new Tree(texobs->at(8),800,100));
  obs.push_back(new Tree(texobs->at(8),0,300));

  obs.push_back(new Rock(texobs->at(1),300,500));
  obs.push_back(new Car(texobs->at(6),600,500));
  obs.push_back(new Car(texobs->at(6),800,500));
  obs.push_back(new Bus(texobs->at(5),0,50));
  obs.push_back(new Fence(texobs->at(2),500,800));
  obs.push_back(new Fence(texobs->at(2),250,800));
  obs.push_back(new Fence(texobs->at(2),600,800));
  obs.push_back(new Fence(texobs->at(2),700,800));

  //POSITIONNEMENT DES HUMAINS
  humans.push_back(new Human(texhumans,600,0));
  humans.push_back(new Human(texhumans,350,0));
  humans.push_back(new Human(texhumans,500,400));
  humans.push_back(new Human(texhumans,700,600));
  humans.push_back(new Human(texhumans,300,650));
  humans.push_back(new Human(texhumans,500,650));


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
  //POSITIONNEMENT DES OBSTACLES  
  obs.push_back(new JungleTree(texobs->at(9), 350, 70));
  obs.push_back(new JungleTree(texobs->at(9), 550, 170));
  obs.push_back(new Head(texobs->at(10), 200, 275));
  obs.push_back(new JungleTree(texobs->at(9), 75, 350));
  obs.push_back(new JungleTree(texobs->at(9), 485, 600));
  obs.push_back(new JungleTree(texobs->at(9), 150, 700));
  obs.push_back(new JungleTree(texobs->at(9), 850, 550));

  //POSITIONNEMENT DES HUMAINS
  humans.push_back(new Human(texhumans, 400, 400));
  humans.push_back(new Human(texhumans, 400, 350));
  humans.push_back(new Human(texhumans, 825, 425));
  humans.push_back(new Human(texhumans, 900, 130));
  humans.push_back(new Human(texhumans, 800, 140));

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
   //POSITIONNEMENT DES OBSTACLES
  obs.push_back(new Temple(texobs->at(11), 680, 60));
  obs.push_back(new JungleTree(texobs->at(9), 485, 600));
  obs.push_back(new JungleTree(texobs->at(9), 350, 70));
  obs.push_back(new JungleTree(texobs->at(9), 750, 250));
  obs.push_back(new JungleTree(texobs->at(9), 150, 700));
  obs.push_back(new JungleTree(texobs->at(9), 75, 450));
  obs.push_back(new JungleTree(texobs->at(9), 525, 170));

  //POSITIONNEMENT DES HUMAINS
  humans.push_back(new Human(texhumans, 650, 250));
  humans.push_back(new Human(texhumans, 650, 280));
  humans.push_back(new Human(texhumans, 825, 625));
  humans.push_back(new Human(texhumans, 900, 730));
  humans.push_back(new Human(texhumans, 800, 850));

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
  //POSITIONNEMENT DES OBSTACLES
  obs.push_back(new Temple(texobs->at(11), 340, 100));

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
  spawn.clear();

  //============== Initialisation ==============
  currentRegionIndex = -1;
  previousRegionIndex = -2;
}

Map::~Map() {
  // Release memory for regions
  for (Region* region : regions) {
    delete region;
  }
  
  // Clear the vector of regions
  regions.clear();
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
