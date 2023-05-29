#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class GameOverScreen {
  private:
    Text GOtext;
    Text ZaRaHtext;
    Texture iconTexture;
    Sprite iconSprite;

  public:
    GameOverScreen(){}; //Constructeur par défaut
    ~GameOverScreen(){delete &GOtext; delete &ZaRaHtext; delete &iconSprite;};
    GameOverScreen(vector<Font>* fonts, Image* icon);
    void displayGameOver(RenderWindow* window, Sprite* backgroundSprite);
    
};  

#endif