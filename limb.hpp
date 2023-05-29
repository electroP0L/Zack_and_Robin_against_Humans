#ifndef LIMB_HPP
#define LIMB_HPP

#include "inanimate.hpp"
#include "contexte.hpp"

class Limb : public Inanimate
{
  private:
    float scale = 1.0f / 30.0f;
    vector<float> targetpos;
    float speed = 5.0f;


  public:
    //Limb(){}; //Constructeur par défaut

    Limb(Texture& texlimb, Contexte* ctxt);
    void choosetargetpos(Contexte* ctxt);
    void updatepos();
};  


#endif