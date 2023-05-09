#include "robot.hpp"

Robot::Robot(vector<Texture>& textures){
  this->textures = textures;
  sprite.setTexture(textures[0]);
  currentTextureIndex = 0;
  sprite.setScale(scale, scale);

  texSize = textures.size()-1;
  halftexSize = textures.size()/2 -1;

  setposition(0,0);
  hitbox = sprite.getGlobalBounds();
  speed = 1.0f;

  HP = 5;
  attackDamage = 1;
  attaqueTime = milliseconds(2000);

  previousmv = {1.0f, 0.0f}; //On initialise le vecteur de déplacement précédent à {1, 0} pour que le robot regarde vers la droite au début 
}


void Robot::bouger(Contexte& ctxt){
  vector<float> mv = {0.0f, 0.0f};
  if (Keyboard::isKeyPressed(Keyboard::I)){mv[1] -= speed;}
  if (Keyboard::isKeyPressed(Keyboard::K)){mv[1] += speed;}
  if (Keyboard::isKeyPressed(Keyboard::J)){mv[0] -= speed;}
  if (Keyboard::isKeyPressed(Keyboard::L)){mv[0] += speed;}
  
  bool collision = checkCollision(mv, ctxt);
  sprite.move(mv[0], mv[1]);
  if (ctxt.getElapsedTime() > 500){
    changeTexture(mv);
  }

  if(mv[0] == 0 && mv[1] == 0){
    return;
  }
  else if(collision){
    previousmv[0] = -mv[0];
    previousmv[1] = -mv[1];
  }
  else{
    previousmv = mv;
  }
}

void Robot::attaquer(Contexte& ctxt, vector<float> direction){
  if(attaqueTimer.getElapsedTime() > attaqueTime){
    attaqueTimer.restart();
    Attack attack;
    if(direction[0] > 0){ //Si on va vers la droite
      attack = Attack(ctxt.getAttackTextures(1, 2), attackDamage, "Human");
    }
    else if(direction[0] < 0){ //Si on va vers la gauche
      attack = Attack(ctxt.getAttackTextures(1, 3), attackDamage, "Human");
    }
    else if(direction[0] == 0){ //Si on va vers le haut ou le bas
      if(direction[1] < 0){ //Si on va vers le haut
        attack = Attack(ctxt.getAttackTextures(1, 0), attackDamage, "Human");
      }
      else if(direction[1] > 0){ //Si on va vers le bas
        attack = Attack(ctxt.getAttackTextures(1, 1), attackDamage, "Human");
      }
      else{ //Si on ne bouge pas
        cout << "previousmv : " << previousmv[0] << " " << previousmv[1] << endl;
        attaquer(ctxt, previousmv);
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


void Robot::changeTexture(vector<float>& mv){
  int nextTextureIndex;

  if (currentTextureIndex == 0){nextTextureIndex = 1;} 
  else {nextTextureIndex = 0;}

  currentTextureIndex = nextTextureIndex;
  sprite.setTexture(textures[currentTextureIndex]);
}