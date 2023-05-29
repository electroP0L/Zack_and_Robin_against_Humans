#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class TextureManager {
  private:
    Image icon;
    Texture texLimb;
    vector<Texture> texZombie;
		vector<Texture> texRobot;
		vector<Texture> texHuman;
		vector<Texture> texObstacles;
		vector<Texture> texBackground;
		vector<vector<vector<Texture>>> texAttacks;

    vector<Font> fonts;

  public:
    TextureManager(){}; //Constructeur par défaut
    ~TextureManager() {
      for (int i = 0; i < texZombie.size(); i++) {
        texZombie[i].~Texture();
      }
      for (int i = 0; i < texRobot.size(); i++) {
        texRobot[i].~Texture();
      }
      for (int i = 0; i < texHuman.size(); i++) {
        texHuman[i].~Texture();
      }
      for (int i = 0; i < texObstacles.size(); i++) {
        texObstacles[i].~Texture();
      }
      for (int i = 0; i < texBackground.size(); i++) {
        texBackground[i].~Texture();
      }
      for (int i = 0; i < texAttacks.size(); i++) {
        for (int j = 0; j < texAttacks[i].size(); j++) {
          for (int k = 0; k < texAttacks[i][j].size(); k++) {
            texAttacks[i][j][k].~Texture();
          }
        }
      }
    }
    
    TextureManager(String& path);
    void loadZombieTextures(String& path);
    void loadRobotTextures(String& path);
    void loadHumanTextures(String& path);
    void loadObstaclesTextures(String& path);
    void loadBackgroundTextures(String& path);
    void loadAttacksTextures(String& path);
    void loadOtherTextures(String& path);
    void loadFonts(String& path);

    Image* getIcon() {return &icon;}
    Texture* getTexLimb() {return &texLimb;}
    vector<Texture>* getTexZombie(){return &texZombie;}
    vector<Texture>* getTexRobot() {return &texRobot;}
    vector<Texture>* getTexHuman() {return &texHuman;}
    vector<Texture>* getTexObstacles() {return &texObstacles;}
    vector<Texture>* getTexBackground() {return &texBackground;}
    vector<vector<vector<Texture>>>* getTexAttacks() {return &texAttacks;}   

    vector<Font>* getFonts() {return &fonts;}
};  

#endif