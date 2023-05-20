#include "living.hpp"

bool Living::checkCollision(vector<float>& mv, Contexte& ctxt) { //Traitement des obstacles

  //Constantes
  const Vector2f pos = sprite.getPosition(); //La position du sprite living
  Vector2f newpos = pos + Vector2f(mv[0], mv[1]); //On calcule la position du living après déplacement

  //Traitement des bords de l'écran 
  //TODO : LES PNJ PEUVENT CHANGER LA REGION - A PATCHER PLUS TARD
  const FloatRect bounds = sprite.getGlobalBounds(); //La hitbox du sprite living


  const float screen_width = SCREEN_WIDTH - bounds.width; 
  const float screen_height = SCREEN_HEIGHT - bounds.height;

  map<String, vector<float>> waypoints = ctxt.getWaypoints();
  if(newpos.x < 0) { //Si le living sort de l'écran par la gauche
    if((waypoints.count("Left")) && (pos.y >= waypoints["Left"][0])&&(pos.y <= waypoints["Left"][1])){  //Si on peut sortir de la région par la gauche et que le sprite est compris dans la zone de changement
      ctxt.setChangeRegion(true, waypoints["Left"][2]);
    }
    else{
      newpos.x = pos.x; 
      mv[0] = 0; //On annule le déplacement
    }
  }
  else if(newpos.x > screen_width) { //Si le living sort de l'écran par la droite
    if((waypoints.count("Right")) && (pos.y >= waypoints["Right"][0])&&(pos.y <= waypoints["Right"][1])){ //Si on peut sortir de la région par la droite et que le sprite est compris dans la zone de changement
      ctxt.setChangeRegion(true, waypoints["Right"][2]);
    }
    else{
      newpos.x = pos.x;
      mv[0] = 0; //On annule le déplacement
    } 
  }
  if(newpos.y < 0) { //Si le living sort de l'écran par le haut
    if ((waypoints.count("Top")) && (pos.x >= waypoints["Top"][0])&&(pos.x+bounds.width) <= waypoints["Top"][1]){  //Si on peut sortir de la région par le haut et que le sprite est compris dans la zone de changement
      ctxt.setChangeRegion(true, waypoints["Top"][2]);
    }
    else {
      newpos.y = pos.y; 
      mv[1] = 0; //On annule le déplacement
    }
  }
  else if(newpos.y > screen_height) { //Si le living sort de l'écran par le bas
    if((waypoints.count("Bottom")) && (pos.x >= waypoints["Bottom"][0])&&(pos.x+bounds.width) <= waypoints["Bottom"][1]){  //Si on peut sortir de la région par le bas et que le sprite est compris dans la zone de changement
      ctxt.setChangeRegion(true, waypoints["Bottom"][2]);
    }
    else {
      newpos.y = pos.y; 
      mv[1] = 0; //On annule le déplacement
    }
    newpos.y = pos.y; 
    mv[1] = 0; //On annule le déplacement
  }
  
  //Traitement des obstacles
  const FloatRect newbounds = FloatRect(newpos.x, newpos.y, bounds.width, bounds.height); //On déclare une hitbox de déplacement
  
  vector<Obstacle>& obstacles = ctxt.getObstacles(); //Référence à la variable existante

  for (int i = 0; i < obstacles.size(); ++i) { //Pour chaque obstacle dans le vecteur d'obstacles
    const FloatRect obstacleBounds = obstacles[i].getHitbox(); //On récupère la hitbox de l'obstacle

    if (obstacleBounds.intersects(newbounds)) { //Si le living et l'obstacle se chevauchent
      FloatRect intersection; //On déclare un rectangle d'intersection
      obstacleBounds.intersects(newbounds, intersection);  //On calcule l'intersection

      if (intersection.width < intersection.height) { //Si l'intersection est plus longue que large, on déplace uniquement le living sur l'axe des X
        mv[0] = (intersection.left == newbounds.left) ? intersection.width/2 : -intersection.width/2; //Si l'intersection est à gauche du living, on le déplace vers la droite, sinon on le déplace vers la gauche
      }
      else { //Si l'intersection est plus large que longue, on déplace le living sur l'axe des Y
        mv[1] = (intersection.top == newbounds.top) ? intersection.height/2 : -intersection.height/2; //Si l'intersection est au dessus du living, on le déplace vers le bas, sinon on le déplace vers le haut
      }
      return true;
    }
  }
  return false;
}

void Living::changeHP(int damage){
  if(invincTimer.getElapsedTime()>invincTime){
    HP += damage;
    invincTimer.restart();
    if (HP <= 0) {HP = 0;}
  }
}

void Living::changeTexture(vector<float>& mv){
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
    if (currentTextureIndex <= halftexSize) { //Si on est dans la première moitié des textures
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