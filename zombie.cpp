#include "zombie.hpp"

Zombie::Zombie(vector<Texture>* textures, Texture* texlimb){
  this->texlimb = texlimb;
  
  this->textures = textures;
  sprite.setTexture(textures->at(4));
  currentTextureIndex = 4;
  sprite.scale(scale, scale);
  
  texSize = textures->size()-1;
  halftexSize = textures->size()/2 -1;

  setposition(0,0);
  hitbox = sprite.getGlobalBounds();
  speed = 2.5f;
  //speed = 10.0f;

  HP = 6;
  attackDamage = 3;
  attackTime = milliseconds(1000);
  invincTime = milliseconds(500);
}


Zombie::~Zombie() {
  for (Limb* limb : missingLimbs) {
    delete limb;
  }
  missingLimbs.clear();
}


void Zombie::bouger(Contexte* ctxt){
  //Déplacement : On bouge le zombie en fonction des touches appuyées
  vector<float> mv = {0.0f, 0.0f};
  if (Keyboard::isKeyPressed(Keyboard::Z)) {mv[1] = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::S)) {mv[1] = speed;}
  if (Keyboard::isKeyPressed(Keyboard::Q)) {mv[0] = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::D)) {mv[0] = speed;}


  bool collision = checkCollision(&mv, ctxt);

  if(collision) { //Si on détecte une collision, le zombie va reculer pour l'éviter
    if(ctxt->getElapsedTime() > 500){ // Si le chronomètre indique une demi seconde
      mv[0] -= mv[0]; //On inverse temporairement la direction du zombie
      changeTexture(&mv); //On change la texture du zombie
      mv[0] -= mv[0]; //On remet la direction du zombie à sa valeur initiale
    }
  }
  else {
    if(ctxt->getElapsedTime() > 500 || previousmv[0] != mv[0] ){ // Si le chronomètre indique une demi seconde, ou le zombie a changé de direction
      changeTexture(&mv); //On change la texture du zombie
    }
  }

  sprite.move(mv[0], mv[1]); //On déplace le zombie
  //On notifie les observateurs humains du déplacement du zombie
  if(collision){
    previousmv[0] = -mv[0];
    previousmv[1] = -mv[1];
  }
  else{ previousmv = mv; }


  FloatRect zombieHitbox = sprite.getGlobalBounds();
  ctxt->setZombiePos(zombieHitbox);
  notifymovement(ctxt);
}

void Zombie::notifymovement(Contexte* ctxt){
  vector<Human*>* humans = ctxt->getHumans(); //Référence à la variable existante
  for (Human* human : *humans) { //Pour chaque humain dans le vecteur d'humains
    human->bouger(ctxt); //La nouvelle hitbox du zombie se trouve dans le contexte
  }
}

void Zombie::attaquer(Contexte* ctxt, vector<float>* direction){
  if(attackTimer.getElapsedTime() > attackTime){
    attackTimer.restart();
    Attack* attack;
    if(direction->at(0) == 0 && direction->at(1) == 0){ //Si on ne bouge pas
        vector<float> still;
        if(currentTextureIndex < halftexSize){ //Si on est dans la deuxième moitié des textures
          attack = new Attack(ctxt->getAttackTextures(0, 1), attackDamage,"Human");
          still = {-1.0f, 0.0f};
        }
        else{ //Si on est dans la première moitié des textures
          attack = new Attack(ctxt->getAttackTextures(0, 0), attackDamage,"Human");
          still = {1.0f, 0.0f};
        }
        FloatRect casterHitbox = sprite.getGlobalBounds();
        attack->computepos(casterHitbox, &still);
        ctxt->addAttack(attack);
        return;
    }
    else if(direction->at(0) > 0){ //Si on va vers la droite
      attack = new Attack(ctxt->getAttackTextures(0, 0), attackDamage, "Human");
    }
    else if(direction->at(0) < 0){ //Si on va vers la gauche
      attack = new Attack(ctxt->getAttackTextures(0, 1), attackDamage,"Human");
    }
    else if(direction->at(0) == 0){ //Si on va vers le haut ou le bas
      if(direction->at(1) < 0){ //Si on va vers le haut
        attack = new Attack(ctxt->getAttackTextures(0, 0), attackDamage,"Human");
      }
      else if(direction->at(1) > 0){ //Si on va vers le bas
        attack = new Attack(ctxt->getAttackTextures(0, 1), attackDamage,"Human");
      }
    }
    FloatRect casterHitbox = sprite.getGlobalBounds();
    attack->computepos(casterHitbox, direction);
    ctxt->addAttack(attack);
  }
  else{
    return;
  }
}

void Zombie::changeHP(int damage, Contexte* ctxt){
  if(damage<0 && invincTimer.getElapsedTime()>invincTime){
    HP += damage;
    invincTimer.restart();
    missingLimbs.push_back(new Limb(*texlimb, ctxt));

    ctxt->setLimbs(getMissingLimbs());
    if (HP <= 0) {HP = 0;}
  }
  else if(damage>0 && invincTimer.getElapsedTime()>invincTime){
    HP += damage;
  }
}

void Zombie::updateLimbs(Contexte* ctxt){
  vector<int>* limbStatus = ctxt->getLimbStatus();
  if (limbStatus->at(0) == 1){
    delete missingLimbs.at(limbStatus->at(1));
    missingLimbs.erase(missingLimbs.begin() + limbStatus->at(1));
    ctxt->setLimbStatus(0, 0);
  }
  else if (limbStatus->at(0) == 2){
    changeHP(1, ctxt);
    ctxt->setLimbStatus(0, 0);
  }
}