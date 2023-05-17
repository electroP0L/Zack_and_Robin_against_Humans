#include "limb.hpp"
#include <cmath>

Limb::Limb(Texture &texlimb)
{
  sprite.setTexture(texlimb);
  sprite.scale(scale, scale);
  
  hitbox = sprite.getGlobalBounds();

  choosetargetpos();
}

void Limb::choosetargetpos()
{
  float x = rand() % 1000;
  float y = rand() % 1000;
  targetpos = {x, y};
}

void Limb::updatepos()
{
  Vector2f pos = sprite.getPosition();
  float dx = targetpos[0] - pos.x;
  float dy = targetpos[1] - pos.y;
  float norm = sqrt(dx*dx + dy*dy);
  if (norm < speed){setpos(targetpos[0], targetpos[1]);}
  else
  {
    float vx = speed * dx / norm;
    float vy = speed * dy / norm;
    sprite.move(vx, vy);
  }
}