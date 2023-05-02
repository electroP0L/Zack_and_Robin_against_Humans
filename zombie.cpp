#include "zombie.hpp"

Zombie::Zombie(vector<Texture>& textures){
  this->textures = textures;
  sprite.setTexture(textures[4]);
  currentTextureIndex = 4;
  sprite.scale(scale, scale);
  //sprite.move(0 + 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
  //sprite.move(SCREEN_WIDTH/2 - sprite.getGlobalBounds().width/2 , SCREEN_HEIGHT/2);
  setposition(0,0);
  hitbox = sprite.getGlobalBounds();
  size = textures.size()-1;
  halfsize = textures.size()/2 -1;

  speed = 1.5f;
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
  previousmv = mv;

  FloatRect zombieHitbox = sprite.getGlobalBounds();
  ctxt.setZombiePos(zombieHitbox);
  notifymovement(ctxt);
}

void Zombie::notifymovement(Contexte& ctxt){
  vector<Human>& humans = ctxt.getHumans(); //Référence à la variable existante
  for (int i = 0; i < humans.size(); ++i) {
    humans[i].bouger(ctxt); //La nouvelle hitbox du zombie se trouve dans le contexte
  }
}
