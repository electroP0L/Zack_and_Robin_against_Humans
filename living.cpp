#include "living.hpp"

bool Living::checkCollision(vector<float>& mv, Contexte& ctxt) { //Traitement des obstacles

  //Constantes
  const Vector2f pos = sprite.getPosition(); //La position du sprite living
  Vector2f newpos = pos + Vector2f(mv[0], mv[1]); //On calcule la position du living après déplacement

  //Traitement des bords de l'écran
  const FloatRect bounds = sprite.getGlobalBounds(); //La hitbox du sprite living


  const float screen_width = SCREEN_WIDTH - bounds.width; 
  const float screen_height = SCREEN_HEIGHT - bounds.height;
  if(newpos.x < 0) { //Si le living sort de l'écran par la gauche
    newpos.x = pos.x; 
    mv[0] = 0; //On annule le déplacement
  }
  else if(newpos.x > screen_width) { //Si le living sort de l'écran par la droite
    newpos.x = pos.x;
    mv[0] = 0; //On annule le déplacement 
  }
  if(newpos.y < 0) { //Si le living sort de l'écran par le haut
    newpos.y = pos.y; 
    mv[1] = 0; //On annule le déplacement
  }
  else if(newpos.y > screen_height) { //Si le living sort de l'écran par le bas
    newpos.y = pos.y; 
    mv[1] = 0; //On annule le déplacement
  }
  
  //Traitement des obstacles
  FloatRect newbounds = FloatRect(newpos.x, newpos.y, bounds.width, bounds.height); //On déclare une hitbox de déplacement
  
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