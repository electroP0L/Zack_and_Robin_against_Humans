#include "zombie.hpp"

Zombie::Zombie(vector<Texture>& textures){
  this->textures = textures;
  sprite.setTexture(textures[4]);
  currentTextureIndex = 4;
  sprite.scale(scale, scale);
  //sprite.move(0 + 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
  //sprite.move(SCREEN_WIDTH/2 - sprite.getGlobalBounds().width/2 , SCREEN_HEIGHT/2);
  sprite.move(0,0);
  hitbox = sprite.getGlobalBounds();
  size = textures.size()-1;
  halfsize = textures.size()/2 -1;
}

void Zombie::bouger(Contexte& ctxt){
  //Déplacement : On bouge le zombie en fonction des touches appuyées
  vector<float> mv = {0.0f, 0.0f};
  if (Keyboard::isKeyPressed(Keyboard::Z)) {mv[1] = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::S)) {mv[1] = speed;}
  if (Keyboard::isKeyPressed(Keyboard::Q)) {mv[0] = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::D)) {mv[0] = speed;}

  if(checkCollision(mv, ctxt)) { //Si on détecte une collision, le zombie va reculer pour l'éviter
    if(ctxt.getElapsedTime() > 500){ // Si le chronomètre indique une demi seconde
      mv[0] -= mv[0]; //On inverse temporairement la direction du zombie
      changeTexture(mv); //On change la texture du zombie
      mv[0] -= mv[0]; //On remet la direction du zombie à sa valeur initiale
    }
  }
  else {
    if(ctxt.getElapsedTime() > 500 || previousmv[0] != mv[0] ){ // Si le chronomètre indique une demi seconde, ou le zombie a changé de direction
      changeTexture(mv); //On change la texture du zombie
    }
  }

  sprite.move(mv[0], mv[1]); //On déplace le zombie
  //On notifie les observateurs humains du déplacement du zombie
  //notifymovement(ctxt);
  previousmv = mv;
}

void Zombie::changeTexture(vector<float>& mv){
  int sign = (mv[0] > 0) ? 1 : ((mv[0] < 0) ? -1 : 0); //On récupère le signe de mv[0]
  
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
      if (mv[1] == 0){ //Si on ne bouge pas sur l'axe y
        newTextureIndex = (currentTextureIndex == 0) ? 1 : 0; //Si on est à la première texture, on passe à la deuxième, sinon on passe à la première
      }
      else { //Si on bouge sur l'axe y
        newTextureIndex = (currentTextureIndex != 2) ? 2 : 3; //Si on est à la première texture, on passe à la deuxième, sinon on passe à la première
      }
    } else { //Si on est dans la deuxième moitié des textures
      if (mv[1] == 0){ //Si on ne bouge pas sur l'axe y
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

/*void Zombie::notifymovement(Contexte& ctxt){
  vector<Human>& humans = ctxt.getHumans(); //Référence à la variable existante
  for (int i = 0; i < humans.size(); ++i) {
    humans[i]->update(this);
  }
}*/