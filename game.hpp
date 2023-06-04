#ifndef GAME_HPP
#define GAME_HPP

#include "texturemanager.hpp"
#include "gameoverscreen.hpp"

#include "zombie.hpp"
#include "robot.hpp"
#include "map.hpp"

class Game {
  private:
    RenderWindow window;
    const Time timePerFrame = seconds(1.f/60.f);

    String* path;
    TextureManager* textureManager;
    GameOverScreen* gameOverScreen;
    Map* map;
    Zombie* zombie;
    Robot* robot;
    Contexte ctxt;

    vector<bool>* changeRegion;
    Region* currentRegion;
    vector<Limb*>* missingLimbs;
    vector<Attack*>* attacks;
    
    Text HPtext;

  public:
    Game(String& path);
    
    ~Game(){
      delete robot;
      delete zombie; 
      delete map; 
      delete gameOverScreen; 
      delete textureManager; 
    }
    
    
    void run();
    void manageRegionChange();
    void display();
    void manageAttacks();
}; 

#endif