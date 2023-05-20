#include "limb.hpp"
#include <cmath>

Limb::Limb(Texture &texlimb, Contexte& ctxt)
{
  sprite.setTexture(texlimb);
  sprite.scale(scale, scale);
  
  hitbox = sprite.getGlobalBounds();

  FloatRect& zombiePos = ctxt.getZombiePos();
  vector<float> zpos = {zombiePos.left + zombiePos.width/2, zombiePos.top + zombiePos.height/2};

  setpos(zpos[0], zpos[1]);

  choosetargetpos(ctxt);
}

void Limb::choosetargetpos(Contexte& ctxt)
{
  int xrand = SCREEN_WIDTH - 34; //34 = largeur du limb
  int yrand = SCREEN_HEIGHT -14; //14 = hauteur du limb

  float x = rand() % xrand;
  float y = rand() % yrand;
  //Si le limbe est superposé à un des obstacles du contexte :
  for (auto& obstacle : ctxt.getObstacles())
  {
    while(obstacle.getHitbox().intersects(hitbox))
    {
      x = rand() % xrand;
      y = rand() % yrand;
    }
  }
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