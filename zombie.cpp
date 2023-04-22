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
  float speed = 300.0f/70;
  if (Keyboard::isKeyPressed(Keyboard::Z)) {dy = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::S)) {dy = speed;}
  if (Keyboard::isKeyPressed(Keyboard::Q)) {dx = -speed;}
  if (Keyboard::isKeyPressed(Keyboard::D)) {dx = speed;}
  if(dx!=0 || dy!=0) {this->sprite.move(dx, dy);}

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

  for (int i = 0; i < obstacles.size(); ++i) { //Pour chaque obstacle dans le vecteur d'obstacles
    const sf::FloatRect obstacleBounds = obstacles[i].getHitbox(); //On récupère la hitbox de l'obstacle

    if (obstacleBounds.intersects(bounds)) { //Si le zombie et l'obstacle se chevauchent
      sf::FloatRect intersection; //On déclare un rectangle d'intersection
      obstacleBounds.intersects(bounds, intersection);  //On calcule l'intersection

      if (intersection.width < intersection.height) { //Si l'intersection est plus longue que large, on déplace le zombie sur l'axe des X
        const float new_x = (pos.x < obstacleBounds.left) ? obstacleBounds.left - bounds.width : obstacleBounds.left + obstacleBounds.width; //On calcule la nouvelle position du zombie
        setpos(new_x, pos.y); //On déplace le zombie
      }
      else { //Si l'intersection est plus large que longue, on déplace le zombie sur l'axe des Y
        const float new_y = (pos.y < obstacleBounds.top) ? obstacleBounds.top - bounds.height : obstacleBounds.top + obstacleBounds.height; //On calcule la nouvelle position du zombie
        setpos(pos.x, new_y); //On déplace le zombie
      }
    }
  }
}
