#include "zombie.hpp"

Zombie::Zombie(vector<Texture>& textures){
  this->textures = textures;
  sprite.setTexture(textures[2]);
  currentTextureIndex = 2;
  sprite.scale(scale, scale);
  sprite.move(0 + 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
  hitbox = sprite.getGlobalBounds();
  size = textures.size()-1;
  halfsize = textures.size()/2 -1;
}

void Zombie::bouger(Contexte& ctxt){
  //Déplacement : On bouge le zombie en fonction des touches appuyées
  float dx = 0.0f;
  float dy = 0.0f;
  if (Keyboard::isKeyPressed(Keyboard::Z)) {dy = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::S)) {dy = speed;}
  if (Keyboard::isKeyPressed(Keyboard::Q)) {dx = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::D)) {dx = speed;}

  if(checkCollision(dx, dy, ctxt)) { //Si on détecte une collision, le zombie va reculer pour l'éviter
    if(ctxt.getElapsedTime() > 500){ // Si le chronomètre indique une demi seconde
      dx -= dx; //On inverse temporairement la direction du zombie
      ctxt.restartClock();  //On le remet à zéro
      changeTexture(dx, dy); //On change la texture du zombie
      dx -= dx; //On remet la direction du zombie à sa valeur initiale
    }
  }
  else {
    if(ctxt.getElapsedTime() > 500 || previousMovements[0] != dx ){ // Si le chronomètre indique une demi seconde, ou le zombie a changé de direction
      ctxt.restartClock();  //On le remet à zéro
      changeTexture(dx, dy); //On change la texture du zombie
    }
  }
  sprite.move(dx, dy); //On déplace le zombie
  ctxt.updateZombieHitbox(hitbox); //On met à jour la hitbox du zombie dans le contexte
  previousMovements[0] = dx;
  previousMovements[1] = dy;
}

void Zombie::changeTexture(float& dx, float& dy){
  int sign = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0); //On récupère le signe de dx
  
  int newTextureIndex;
  switch (sign) {
  case -1: // moving left
    newTextureIndex = (currentTextureIndex != 2) ? 2 : 3; //Si on est à la première texture, on passe à la deuxième, sinon on passe à la première
    break;
  case 1: // moving right
    newTextureIndex = (currentTextureIndex != 6) ? 6 : 7; //Si on est à la troisième texture, on passe à la quatrième, sinon on passe à la troisième
    break;
  default: 
    if (currentTextureIndex <= halfsize) { //Si on est dans la première moitié des textures
      if (dy == 0){ //Si on ne bouge pas sur l'axe y
        newTextureIndex = (currentTextureIndex == 0) ? 1 : 0; //Si on est à la première texture, on passe à la deuxième, sinon on passe à la première
      }
      else { //Si on bouge sur l'axe y
        newTextureIndex = (currentTextureIndex != 2) ? 2 : 3; //Si on est à la première texture, on passe à la deuxième, sinon on passe à la première
      }
    } else { //Si on est dans la deuxième moitié des textures
      if (dy == 0){ //Si on ne bouge pas sur l'axe y
        newTextureIndex = (currentTextureIndex == 4) ? 5 : 4; //Si on est à la cinquième texture, on passe à la sixième, sinon on passe à la cinquième
      }
      else { //Si on bouge sur l'axe y
        newTextureIndex = (currentTextureIndex != 6) ? 6 : 7; //Si on est à la troisième texture, on passe à la quatrième, sinon on passe à la troisième
      }
    }
    break;
  }

  currentTextureIndex = newTextureIndex;
  sprite.setTexture(textures[newTextureIndex]);
}