#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "living.hpp"

class Human : public Living 
{
  private:
    int HP;
    float scale = 1.0f/10.0f;

  public:
    Human(); //Constructeur par défaut
    Human(vector<Texture>& textures, vector<float> pos);
    void bouger(Contexte& ctxt) override;
    //void attaquer();
};

#endif