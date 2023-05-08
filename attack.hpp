#ifndef ATTACK_HPP
#define ATTACK_HPP

#include "inanimate.hpp"

class Attack : public Inanimate{
  private:
    vector<Texture> attackTextures;
    Clock attackTimer;
    int attackDamage;
    String target;

  public:
    Attack(){}; //Constructeur par défaut
    Attack(vector<Texture>& attackTextures, int attackDamage, String target);
    
    Time getAttackTime() {return attackTimer.getElapsedTime();}
    String getTarget() {return target;}
    int getDamage() {return attackDamage;}

    void changeTexture();
    void computepos(FloatRect& hitbox, vector<float>& direction); //Fonction pour calculer la position du précédent déplacement du zombie
    bool hit(FloatRect& hitbox);
};



#endif
