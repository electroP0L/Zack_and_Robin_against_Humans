#include "texturemanager.hpp"
#include <iostream>



TextureManager::TextureManager(String& path)
{
  loadZombieTextures(path);
  loadRobotTextures(path);
  loadHumanTextures(path);
  loadObstaclesTextures(path);
  loadBackgroundTextures(path);
  loadAttacksTextures(path);
  loadOtherTextures(path);
  loadFonts(path);
}

void TextureManager::loadZombieTextures(String& path)
{

  //============== ZOMBIE ==============
  Texture tex;
  //GAUCHE
  //Immobile
  if(!tex.loadFromFile("sprites/zombie1.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1.png"); }
  texZombie.push_back(tex); //index 0
  if(!tex.loadFromFile("sprites/zombie1_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1_2.png"); }
  texZombie.push_back(tex); //index 1
  //Marche
  if(!tex.loadFromFile("sprites/zombie1_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1_3.png"); }
  texZombie.push_back(tex); //index 2
  if(!tex.loadFromFile("sprites/zombie1_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie1_4.png"); }
  texZombie.push_back(tex); //index 3
  //DROITE
  //Immobile
  if(!tex.loadFromFile("sprites/zombie2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2.png");  }
  texZombie.push_back(tex); //index 4
  if(!tex.loadFromFile("sprites/zombie2_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2_2.png");  }
  texZombie.push_back(tex); //index 5
  //Marche
  if(!tex.loadFromFile("sprites/zombie2_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2_3.png");  }
  texZombie.push_back(tex); //index 6
  if(!tex.loadFromFile("sprites/zombie2_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/zombie2_4.png");  }
  texZombie.push_back(tex); //index 7
}

void TextureManager::loadRobotTextures(String& path)
{
  //============== ROBOT ==============
  Texture tex;
  if(!tex.loadFromFile("sprites/robot1.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/robot1.png");  }
  texRobot.push_back(tex);
  if(!tex.loadFromFile("sprites/robot2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/robot2.png");  }
  texRobot.push_back(tex);
}

void TextureManager::loadHumanTextures(String& path)
{
  //============== HUMAIN ==============
  Texture tex;
  //GAUCHE
  //Immobile
  if(!tex.loadFromFile("sprites/human1.png")){  if(!tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1.png"));  }
  texHuman.push_back(tex); //index 0
  if(!tex.loadFromFile("sprites/human1_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1_2.png");  }
  texHuman.push_back(tex); //index 1
  //Marche
  if(!tex.loadFromFile("sprites/human1_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1_3.png");  }
  texHuman.push_back(tex); //index 2
  if(!tex.loadFromFile("sprites/human1_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human1_4.png");  }
  texHuman.push_back(tex); //index 3
  //DROITE
  //Immobile
  if(!tex.loadFromFile("sprites/human2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2.png");  }
  texHuman.push_back(tex); //index 4
  if(!tex.loadFromFile("sprites/human2_2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2_2.png");  }
  texHuman.push_back(tex); //index 5
  //Marche
  if(!tex.loadFromFile("sprites/human2_3.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2_3.png");  }
  texHuman.push_back(tex); //index 6
  if(!tex.loadFromFile("sprites/human2_4.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/human2_4.png");  }
  texHuman.push_back(tex); //index 7
}

void TextureManager::loadAttacksTextures(String& path)
{
//============== ATTAQUES ==============
  Texture tex;
  vector<Texture> texattackperdirection;
  vector<vector<Texture>> texattackspercaracter;
  //Zombie
  if(!tex.loadFromFile("sprites/Zattack1R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack1R.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Zattack2R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack2R.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Zattack1L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack1L.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Zattack2L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Zattack2L.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  texAttacks.push_back(texattackspercaracter);
  texattackspercaracter.clear();

  //Robot
  if(!tex.loadFromFile("sprites/Rattack1T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1T.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2T.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Rattack1B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1B.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2B.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Rattack1R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1R.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2R.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Rattack1L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack1L.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Rattack2L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Rattack2L.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  texAttacks.push_back(texattackspercaracter);
  texattackspercaracter.clear();

  //Human
  if(!tex.loadFromFile("sprites/Hattack1T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1T.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2T.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2T.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Hattack1B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1B.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2B.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2B.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Hattack1R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1R.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2R.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2R.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  if(!tex.loadFromFile("sprites/Hattack1L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack1L.png");  }
  texattackperdirection.push_back(tex);
  if(!tex.loadFromFile("sprites/Hattack2L.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/Hattack2L.png");  }
  texattackperdirection.push_back(tex);
  texattackspercaracter.push_back(texattackperdirection);
  texattackperdirection.clear();

  texAttacks.push_back(texattackspercaracter);
  texattackspercaracter.clear();
}

void TextureManager::loadObstaclesTextures(String& path)
{
  Texture tex;
  //============== OBSTACLES ==============
  if(!tex.loadFromFile("sprites/tree.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/tree.png"); }
  texObstacles.push_back(tex); //Index 0
  if(!tex.loadFromFile("sprites/rock.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/rock.png"); }
  texObstacles.push_back(tex); //Index 1
  if(!tex.loadFromFile("sprites/fence.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/fence.png"); }
  texObstacles.push_back(tex); //Index 2
  if(!tex.loadFromFile("sprites/spaceship.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/spaceship.png"); }
  texObstacles.push_back(tex); //Index 3
  if(!tex.loadFromFile("sprites/fence2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/fence2.png"); }
  texObstacles.push_back(tex); //Index 4
  if(!tex.loadFromFile("sprites/bus.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/bus.png"); }
  texObstacles.push_back(tex); //Index 5
  if(!tex.loadFromFile("sprites/car.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/car.png"); }
  texObstacles.push_back(tex); //Index 6
  if(!tex.loadFromFile("sprites/building1.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/building1.png"); }
  texObstacles.push_back(tex); //Index 7
  if(!tex.loadFromFile("sprites/building2.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/building2.png"); }
  texObstacles.push_back(tex); //Index 8
  if(!tex.loadFromFile("sprites/jungle_tree.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/jungle_tree.png"); }
  texObstacles.push_back(tex); //Index 9
  if(!tex.loadFromFile("sprites/head.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/head.png"); }
  texObstacles.push_back(tex); //Index 10
  if(!tex.loadFromFile("sprites/temple.png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/temple.png"); }
  texObstacles.push_back(tex); //Index 11
}

void TextureManager::loadBackgroundTextures(String& path)
{
  //============== BACKGROUNDS ==============
  Texture tex;
  for(int i = 1; i <= 9; i++){
    if(!tex.loadFromFile("sprites/BG" + to_string(i) + ".png")){  tex.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/BG" + to_string(i) + ".png");  }
    texBackground.push_back(tex);
  }
}

void TextureManager::loadOtherTextures(String& path)
{
  //============== AUTRES ==============
  if(!texLimb.loadFromFile("sprites/limb.png")){  texLimb.loadFromFile(path + "Zack_and_Robin_against_Humans/sprites/limb.png");  }
  if(!icon.loadFromFile("application/icon.png")){  icon.loadFromFile(path + "Zack_and_Robin_against_Humans/application/icon.png");  }
}

void TextureManager::loadFonts(String& path)
{
  Font font;
  if(!font.loadFromFile("fonts/gooddog.ttf")){  if(!font.loadFromFile(path + "Zack_and_Robin_against_Humans/fonts/gooddog.ttf")){cout << "Erreur du chargement des polices" << endl;} }
  fonts.push_back(font);
  if(!font.loadFromFile("fonts/Branda-yolq.ttf")){  if(!font.loadFromFile(path + "Zack_and_Robin_against_Humans/fonts/Branda-yolq.ttf")){cout << "Erreur du chargement des polices" << endl;} }
  fonts.push_back(font);
}