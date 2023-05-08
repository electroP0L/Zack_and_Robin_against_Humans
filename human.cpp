#include "human.hpp"
#include <cmath>

Human::Human(){}

Human::Human(vector<Texture>& textures, vector<float> pos){
  this->textures = textures;
  if(pos[0] < SCREEN_WIDTH/2){  sprite.setTexture(textures[4]); }
  else{   sprite.setTexture(textures[0]); }
  currentTextureIndex = 0;
  sprite.scale(scale, scale);

  texSize = textures.size()-1;
  halftexSize = textures.size()/2 -1;

  setposition(pos[0], pos[1]);
  hitbox = sprite.getGlobalBounds();
  speed = 1.0f;

  HP = 5;
  attackDamage = 2;
  attaqueTime = milliseconds(1500);
}


void Human::bouger(Contexte& ctxt){
  FloatRect& zombiePos = ctxt.getZombiePos();

  //Déplacement : L'Humain doit se rapprocher de la hitbox du zombie ;
  //Pour cela, on va bouger son sprite vers la hitbox du zombie :
  //On récupère la position du zombie :
  vector<float> zpos = {zombiePos.left + zombiePos.width/2, zombiePos.top + zombiePos.height/2};

  //On récupère la position de l'humain :
  FloatRect posRect = sprite.getGlobalBounds(); 
  vector<float> mv = {posRect.left + posRect.width/2, posRect.top + posRect.height/2};

  //On calcule le vecteur directeur du déplacement :
  mv[0] = zpos[0] - mv[0];
  mv[1] = zpos[1] - mv[1];

  //On calcule la norme du vecteur directeur :
  float norme = sqrt(mv[0]*mv[0] + mv[1]*mv[1]);

  if (norme <= 100) {
    // L'humain est dans le rayon d'action du zombie, on ne bouge pas l'humain
    mv[0] = 0;
    mv[1] = 0;
    //attaquer(ctxt, previousmv);
  }
  else{
    //On normalise le vecteur directeur :
    if (norme < 1) {mv[0] = 0; mv[1] = 0;}
    else {mv[0] /= norme; mv[1] /= norme;}
  }

  //On calcule le déplacement :
  mv[0] *= speed;
  mv[1] *= speed;

  if(checkCollision(mv, ctxt)) { //Si on détecte une collision, l'humain va reculer pour l'éviter
    if(ctxt.getElapsedTime() > 500){ // Si le chronomètre indique une demi seconde
      mv[0] -= mv[0]; //On inverse temporairement la direction de l'humain
      changeTexture(mv); //On change la texture de l'humain
      mv[0] -= mv[0]; //On remet la direction de l'humain à sa valeur initiale
    }
  }
  else {
    int signmv = (mv[0] >= 0) ? 1 : ((mv[0] < 0) ? -1 : 0); //On récupère le signe de mv[0]
    int signprevmv = (previousmv[0] > 0) ? 1 : ((previousmv[0] < 0) ? -1 : 0); //On récupère le signe de previousmv[0]

    bool hasElapsed = ctxt.getElapsedTime() > 500;
    bool hasChangedDirection = signprevmv != signmv && (previousmv[0] != 0 || mv[0] != 0);

    if(hasElapsed || hasChangedDirection){ // Si le chronomètre indique une demi seconde, ou le zombie a changé de direction
      changeTexture(mv); //On change la texture de l'humain
    }
  }

  //On bouge le sprite :
  sprite.move(mv[0], mv[1]);

  previousmv = mv;
}

void Human::attaquer(Contexte& ctxt, vector<float> direction){
  if (attaqueTimer.getElapsedTime() > attaqueTime) {
    attaqueTimer.restart();
    Attack attack;
    if (direction[0] > 0) { //Si on va vers la droite
      attack = Attack(ctxt.getAttackTextures(2, 2), attackDamage, "Zombie");
    }
    else if (direction[0] < 0) { //Si on va vers la gauche
      attack = Attack(ctxt.getAttackTextures(2, 3), attackDamage, "Zombie");
    }
    else if (direction[0] == 0) { //Si on va vers le haut ou le bas
      if (direction[1] < 0) { //Si on va vers le haut
        attack = Attack(ctxt.getAttackTextures(2, 0), attackDamage, "Zombie");
      }
      else if (direction[1] > 0) { //Si on va vers le bas
        attack = Attack(ctxt.getAttackTextures(2, 1), attackDamage, "Zombie");
      }
      else { //Si on ne bouge pas
        if(currentTextureIndex < halftexSize){ //Si on est dans la deuxième moitié des textures
          attack = Attack(ctxt.getAttackTextures(2, 1), attackDamage,"Zombie");
        }
        else{ //Si on est dans la première moitié des textures
          attack = Attack(ctxt.getAttackTextures(2, 0), attackDamage,"Zombie");
        }
      }
    }
    hitbox = sprite.getGlobalBounds();
    attack.computepos(hitbox, direction);
    ctxt.addAttack(attack);
  }
  else{
    return;
  }
}