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

    vector<Obstacle> obstacles;
    vector<Human>* humans;

    vector<Limb>* limbs;
    vector<int> limbStatus;
    //Première adresse : 0 = Rien à faire ; 1 = Supprimer le limb car pris en charge ; 2 = Limb donné, regagner 1 HP
    //Deuxième adresse : indice du limb à supprimer ou à donner

    FloatRect zombiePos;

    vector<vector<vector<Texture>>> attackTextures;
    //0 = Zombie ; 1 = Robot ; 2 = Human
    //0 = haut ; 1 = bas ; 2 = droite ; 3 = gauche
    vector<Attack> attacks;

    map<String, vector<float>> waypoints;
    vector<bool> changeRegion = {false, false}; //changeRegion[0] = doit-on changer de région ? //changeRegion[1] = en avant ou en arrière ?


  public:

    Contexte(vector<Obstacle> obstacles, vector<Human>* humans, map<String, vector<float>> waypoints, vector<vector<vector<Texture>>>& texattacks, vector<Limb>& missingLimbs){
      this->obstacles.clear(); this->waypoints.clear(); this->attacks.clear();
      this->obstacles = obstacles; this->humans = humans; this->waypoints = waypoints;
      this->attackTextures = texattacks;
      this->limbStatus = {0, 0};
      setLimbs(missingLimbs);
    }


    float getElapsedTime() {return this->clock.getElapsedTime().asMilliseconds();}
    void restartClock() {this->clock.restart();}
    

    vector<Obstacle>& getObstacles() {return this->obstacles;}
    vector<Human>& getHumans() {return *humans;}


    void setZombiePos(FloatRect& zombieHitbox)  {  zombiePos = zombieHitbox;}
    FloatRect& getZombiePos() {return this->zombiePos;}
    void setLimbs(vector<Limb>& limbs) {this->limbs = &limbs;}
    vector<Limb>& getLimbs() {return *limbs;}
    void setLimbStatus(int status, int adress) {this->limbStatus.clear(); this->limbStatus.push_back(status); this->limbStatus.push_back(adress);}
    vector<int> getLimbStatus() {return this->limbStatus;}


    vector<Attack>& getAttacks() {return this->attacks;}
    vector<Texture>& getAttackTextures(int who, int direction) {return this->attackTextures[who][direction];}
    void setAttackTextureVectors(vector<vector<vector<Texture>>>& attackTextures) {this->attackTextures= attackTextures;}
    void addAttack(Attack& attack) {this->attacks.push_back(attack);}

    map<String, vector<float>>& getWaypoints() {return this->waypoints;}
    vector<bool> getChangeRegion() {return this->changeRegion;}
    void setChangeRegion(bool change, int direction) {changeRegion.clear(); changeRegion.push_back(change); changeRegion.push_back(direction);}
};

#endif