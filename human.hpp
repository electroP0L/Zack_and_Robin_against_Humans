#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "living.hpp"

class Human : public Living 
{
  private:
    float scale = 1.0f/10.0f;

  public:
    Human(vector<Texture>* textures, float x, float y);

    void bouger(Contexte* ctxt) override;
    void attaquer(Contexte* ctxt, vector<float>* direction) override;
};

#endif