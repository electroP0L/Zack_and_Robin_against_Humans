#include "gameoverscreen.hpp"
#include <iostream>

GameOverScreen::GameOverScreen(vector<Font>* fonts, Image* icon)
{
  Font font;
  GOtext.setFont(fonts->at(0));
  GOtext.setString("GAME OVER");
  GOtext.setCharacterSize(185);
  GOtext.setOutlineColor(Color::Black);
  GOtext.setOutlineThickness(2);
  GOtext.setFillColor(Color(200, 0, 0));
  GOtext.setPosition(sf::Vector2f(500-(GOtext.getGlobalBounds().width)/2, 50));

  ZaRaHtext.setFont(fonts->at(1));
  ZaRaHtext.setString("Zack & Robin against Humans");
  ZaRaHtext.setCharacterSize(75);
  ZaRaHtext.setFillColor(Color::Black);
  ZaRaHtext.setPosition(sf::Vector2f(500-(ZaRaHtext.getGlobalBounds().width)/2, 800));

  iconTexture.loadFromImage(*icon);
  
  iconSprite.setTexture(iconTexture);
  iconSprite.setScale(10, 10);
  iconSprite.setPosition(500-(iconSprite.getGlobalBounds().width)/2 , 300);
}

void GameOverScreen::displayGameOver(RenderWindow* window, Sprite* backgroundSprite)
{
  window->clear();

  //On rend plus sombre la texture du background :
  backgroundSprite->setColor(Color(100, 100, 100));

  //On affiche le Game Over :
  window->draw(*backgroundSprite);
  window->draw(GOtext);
  window->draw(ZaRaHtext);
  window->draw(iconSprite);
  window->display();

  sf::sleep(seconds(5));

  window->close();
}