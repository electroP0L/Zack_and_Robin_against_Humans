#include "zombie.hpp"

Zombie::Zombie(Texture& texture){
  sprite.setTexture(texture);
  sprite.scale(scale, scale);
  //sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
  setpos(0 + 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
  hitbox = sprite.getGlobalBounds();
}

void Zombie::bouger(Command& cmd){
  //Déplacement : On bouge le zombie en fonction des touches appuyées
  float dx = 0;
  float dy = 0;
  float speed = 4.0f;
  if (Keyboard::isKeyPressed(Keyboard::Z)) {dy = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::S)) {dy = speed;}
  if (Keyboard::isKeyPressed(Keyboard::Q)) {dx = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::D)) {dx = speed;}

  //Constantes
  const sf::Vector2f pos = sprite.getPosition(); //La position du sprite zombie
  sf::Vector2f newpos = pos + sf::Vector2f(dx, dy); //On calcule la position du zombie après déplacement

  //Traitement des bords de l'écran
  const sf::FloatRect bounds = sprite.getGlobalBounds(); //La hitbox du sprite zombie


  const float screen_width = SCREEN_WIDTH - bounds.width; 
  const float screen_height = SCREEN_HEIGHT - bounds.height;
  if(newpos.x < 0) { //Si le zombie sort de l'écran par la gauche
    newpos.x = pos.x; 
    dx = 0; //On annule le déplacement
  }
  else if(newpos.x > screen_width) { //Si le zombie sort de l'écran par la droite
    newpos.x = pos.x;
    dx = 0; //On annule le déplacement 
  }
  if(newpos.y < 0) { //Si le zombie sort de l'écran par le haut
    newpos.y = pos.y; 
    dy = 0; //On annule le déplacement
  }
  else if(newpos.y > screen_height) { //Si le zombie sort de l'écran par le bas
    newpos.y = pos.y; 
    dy = 0; //On annule le déplacement
  }
  
  //Traitement des obstacles
  sf::FloatRect newbounds = sf::FloatRect(newpos.x, newpos.y, bounds.width, bounds.height); //On déclare une hitbox de déplacement
  
  std::vector<Obstacle>& obstacles = cmd.getObstacles(); //Référence à la variable existante

  for (int i = 0; i < obstacles.size(); ++i) { //Pour chaque obstacle dans le vecteur d'obstacles
    const sf::FloatRect obstacleBounds = obstacles[i].getHitbox(); //On récupère la hitbox de l'obstacle

    if (obstacleBounds.intersects(newbounds)) { //Si le zombie et l'obstacle se chevauchent
      sf::FloatRect intersection; //On déclare un rectangle d'intersection
      obstacleBounds.intersects(newbounds, intersection);  //On calcule l'intersection

      if (intersection.width < intersection.height) { //Si l'intersection est plus longue que large, on déplace uniquement le zombie sur l'axe des X
        dx = (intersection.left == newbounds.left) ? intersection.width/2 : -intersection.width/2; //Si l'intersection est à gauche du zombie, on le déplace vers la droite, sinon on le déplace vers la gauche
      }
      else { //Si l'intersection est plus large que longue, on déplace le zombie sur l'axe des Y
        dy = (intersection.top == newbounds.top) ? intersection.height/2 : -intersection.height/2; //Si l'intersection est au dessus du zombie, on le déplace vers le bas, sinon on le déplace vers le haut
      }
    }
  }
  sprite.move(dx, dy); //On déplace le zombie
}
