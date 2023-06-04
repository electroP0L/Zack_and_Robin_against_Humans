#ifndef CONTEXTE_HPP
#define CONTEXTE_HPP

#include "obstacle.hpp"
#include "attack.hpp"
class Limb;
class Human;

#include <vector>

class Contexte {
  private:
    Clock clock;

    vector<Obstacle*>* obstacles;
    vector<Human*>* humans;

    vector<Limb*>* limbs;
    vector<int> limbStatus;
    //Première adresse : 0 = Rien à faire ; 1 = Supprimer le limb car pris en charge ; 2 = Limb donné, regagner 1 HP
    //Deuxième adresse : indice du limb à supprimer ou à donner

    FloatRect zombiePos;

    vector<vector<vector<Texture>>>* attackTextures;
    //0 = Zombie ; 1 = Robot ; 2 = Human
    //0 = haut ; 1 = bas ; 2 = droite ; 3 = gauche
    vector<Attack*> attacks;

    map<String, vector<float>*>* waypoints;
    vector<bool> changeRegion = {false, false}; //changeRegion[0] = doit-on changer de région ? //changeRegion[1] = en avant ou en arrière ?


  public:
    Contexte(){}; //Constructeur par défaut
    Contexte(vector<Obstacle*>* obstacles, vector<Human*>* humans,
            map<String, vector<float>*>* waypoints, vector<vector<vector<Texture>>>* texattacks,
             vector<Limb*>* missingLimbs){
      this->obstacles = obstacles;
      this->humans = humans;
      this->waypoints = waypoints;
      this->attackTextures = texattacks;
      this->limbStatus = {0, 0};
      this->limbs = missingLimbs;
      this->attacks = {};
    }
    ~Contexte(){
      
      for (Attack* attack : attacks) {
        delete attack;
      }
      attacks.clear();
    }


    float getElapsedTime() {return this->clock.getElapsedTime().asMilliseconds();}
    void restartClock() {this->clock.restart();}
    

    vector<Obstacle*>* getObstacles() {return obstacles;}
    vector<Human*>* getHumans() {return humans;}


    void setZombiePos(FloatRect& zombieHitbox)  {zombiePos = zombieHitbox;}
    FloatRect* getZombiePos() {return &zombiePos;}
    void setLimbs(vector<Limb*>* limbs) {this->limbs = limbs;}
    vector<Limb*>* getLimbs() {return limbs;}
    void setLimbStatus(int status, int adress) {limbStatus.clear(); limbStatus.push_back(status); limbStatus.push_back(adress);}
    vector<int>* getLimbStatus() {return &limbStatus;}


    vector<Attack*>* getAttacks() {return &attacks;}
    vector<Texture>* getAttackTextures(int who, int direction) {return &((*attackTextures)[who][direction]);}
    void setAttackTextureVectors(vector<vector<vector<Texture>>>* attackTextures) {this->attackTextures= attackTextures;}
    void addAttack(Attack* attack) {(attacks).push_back(attack);}

    map<String, vector<float>*>* getWaypoints() {return waypoints;}
    vector<bool>* getChangeRegion() {return &changeRegion;}
    void setChangeRegion(bool change, int direction) {changeRegion.clear(); changeRegion.push_back(change); changeRegion.push_back(direction);}
};

#endif