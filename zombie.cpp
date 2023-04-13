#include "zombie.hpp"

Zombie::Zombie(Texture& texture){
  sprite.setTexture(texture);
  float scale = 1.0f / 6.0f;
  sprite.scale(scale, scale);
  setpos(0 + 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
  hitbox = sprite.getGlobalBounds();
}

void Zombie::bouger(Command& cmd){
  //Déplacement : On bouge le zombie en fonction des touches appuyées
  float speed = 300.0f/70;
  if (Keyboard::isKeyPressed(Keyboard::Z)) {this->sprite.move(0, -speed);}
  if (Keyboard::isKeyPressed(Keyboard::S)) {this->sprite.move(0, speed);}
  if (Keyboard::isKeyPressed(Keyboard::Q)) {this->sprite.move(-speed, 0);}
  if (Keyboard::isKeyPressed(Keyboard::D)) {this->sprite.move(speed, 0);}

  //Constantes
  const sf::Vector2f pos = sprite.getPosition(); //La position du sprite zombie
  const sf::FloatRect bounds = sprite.getGlobalBounds(); //La hitbox du sprite zombie

  //Traitement des bords de l'écran
  const float screen_width = SCREEN_WIDTH - bounds.width; 
  const float screen_height = SCREEN_HEIGHT - bounds.height;
  if(pos.x < 0) {sprite.setPosition(0, pos.y);} //Si le zombie sort de l'écran à gauche, on le replace 
  if(pos.x > screen_width) {sprite.setPosition(screen_width, pos.y);} //Si le zombie sort de l'écran à droite, on le replace
  if(pos.y < 0) {sprite.setPosition(pos.x, 0);} //Si le zombie sort de l'écran en haut, on le replace
  if(pos.y > screen_height) {sprite.setPosition(pos.x, screen_height);} //Si le zombie sort de l'écran en bas, on le replace

  //Traitement des obstacles
  std::vector<Obstacle>& obstacles = cmd.getObstacles(); //Référence à la variable existante

  for (int i = 0; i < obstacles.size(); ++i) {
    const sf::FloatRect obstacleBounds = obstacles[i].getHitbox(); //On récupère la hitbox de l'obstacle
    const sf::Vector2f obstaclePos(obstacleBounds.left, obstacleBounds.top); //Ses coordonnées
    const sf::Vector2f obstacleSize(obstacleBounds.width, obstacleBounds.height); //Ses dimensions

    const bool overlaps = bounds.intersects(obstacleBounds); //Si le zombie et l'obstacle se chevauchent

    if (overlaps) {
      const float overlapX = std::min(pos.x + bounds.width, obstaclePos.x + obstacleSize.x) - std::max(pos.x, obstaclePos.x); //On calcule la longueur de l'intersection
      const float overlapY = std::min(pos.y + bounds.height, obstaclePos.y + obstacleSize.y) - std::max(pos.y, obstaclePos.y); //On calcule la largeur de l'intersection

      if (overlapX < overlapY) { //Si l'intersection est plus longue que large, on déplace le zombie sur l'axe des X
        const float new_x = (pos.x < obstaclePos.x) ? obstaclePos.x - bounds.width : obstaclePos.x + obstacleSize.x; //On calcule la nouvelle position du zombie
        setpos(new_x, pos.y); //On déplace le zombie
      }
      else { //Si l'intersection est plus large que longue, on déplace le zombie sur l'axe des Y
        const float new_y = (pos.y < obstaclePos.y) ? obstaclePos.y - bounds.height : obstaclePos.y + obstacleSize.y; //On calcule la nouvelle position du zombie
        setpos(pos.x, new_y); //On déplace le zombie
      }
    }
  }
}
