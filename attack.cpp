#include "attack.hpp"
#include <cmath>

Attack::Attack(vector<Texture>* attackTextures, int attackDamage, String target)
{
  this->attackTextures = attackTextures;

  sprite.setTexture(attackTextures->at(0));
  sprite.scale(1.0f/10.0f, 1.0f/10.0f);

  this->attackDamage = attackDamage;

  this->target = target;
}

void Attack::changeTexture()
{
  if(attackTimer.getElapsedTime() > seconds(0.25))
  {
    sprite.setTexture(attackTextures->at(1));
  }
}

void Attack::computepos(FloatRect& casterHitbox, vector<float>* direction)
{
  if(direction->at(0) > 0){ //Si on va vers la droite
    sprite.setPosition((casterHitbox).left + (casterHitbox).width, (casterHitbox).top);
  }
  else if(direction->at(0) < 0){ //Si on va vers la gauche
    sprite.setPosition((casterHitbox).left - sprite.getGlobalBounds().width, (casterHitbox).top);
  }
  else if(direction->at(0) == 0){ //Si on va vers le haut ou le bas
    if(direction->at(1) < 0){ //Si on va vers le haut
      sprite.setPosition((casterHitbox).left, (casterHitbox).top - sprite.getGlobalBounds().height);
    }
    else if(direction->at(1) > 0){ //Si on va vers le bas
      sprite.setPosition((casterHitbox).left, (casterHitbox).top + (casterHitbox).height);
    }
    else{ //Si on ne bouge pas
      cout << "Erreur : direction nulle" << endl;
      //TODO : Gérer le cas où on ne bouge pas
    }
  }
  
  
  //sprite.setPosition(500, 500);
}

bool Attack::hit(FloatRect* hitbox)
{
  return sprite.getGlobalBounds().intersects(*hitbox);
}

