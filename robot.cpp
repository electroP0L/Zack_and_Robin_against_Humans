#include "robot.hpp"

Robot::Robot(vector<Texture>& textures){
  this->textures = textures;
  sprite.setTexture(textures[0]);
  currentTextureIndex = 0;
  sprite.setScale(scale, scale);
  //sprite.move(0 + 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
  //sprite.move(SCREEN_WIDTH/2 + sprite.getGlobalBounds().width/2, SCREEN_HEIGHT/2);
  sprite.move(0,0);
  hitbox = sprite.getGlobalBounds();
  size = textures.size()-1;
  halfsize = textures.size()/2 -1;
}

void Robot::bouger(Contexte& ctxt){
  vector<float> mv = {0.0f, 0.0f};
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){mv[1] -= speed;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){mv[1] += speed;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){mv[0] -= speed;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){mv[0] += speed;}
  
  checkCollision(mv, ctxt);
  sprite.move(mv[0], mv[1]);
  if (ctxt.getElapsedTime() > 500){
    changeTexture(mv);
  }

  previousmv = mv;
}

void Robot::changeTexture(vector<float>& mv){
  int nextTextureIndex;

  if (currentTextureIndex == 0){nextTextureIndex = 1;} 
  else {nextTextureIndex = 0;}

  currentTextureIndex = nextTextureIndex;
  sprite.setTexture(textures[currentTextureIndex]);
}