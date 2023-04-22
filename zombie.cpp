#include "zombie.hpp"

Zombie::Zombie(vector<Texture>& textures){
  this->textures = textures;
  sprite.setTexture(textures[1]);
  sprite.scale(scale, scale);
  //texzombie.push_back(texzombie1);sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
  sprite.move(0 + 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
  hitbox = sprite.getGlobalBounds();
}

void Zombie::bouger(Command& cmd){
  //Déplacement : On bouge le zombie en fonction des touches appuyées
  float dx = 0.0f;
  float dy = 0.0f;
  float speed = 4.0f;
  if (Keyboard::isKeyPressed(Keyboard::Z)) {dy = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::S)) {dy = speed;}
  if (Keyboard::isKeyPressed(Keyboard::Q)) {dx = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::D)) {dx = speed;}

  checkCollision(dx, dy, cmd); //On vérifie les collisions
  sprite.move(dx, dy); //On déplace le zombie
  changeTexture(cmd); //On change la texture du zombie
}

void Zombie::changeTexture(Command& cmd){
  if (Keyboard::isKeyPressed(Keyboard::Q)) {sprite.setTexture(textures[0]);}
  if (Keyboard::isKeyPressed(Keyboard::D)) {sprite.setTexture(textures[1]);}
}