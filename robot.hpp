#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "living.hpp"
#include "limb.hpp"

class Robot : public Living
{
  private:
    const float scale = 1.0f/10.0;
    bool haslimb;
    
  public:
    //Robot(){}; //Constructeur par défaut
    Robot(vector<Texture>* textures);
    
    void bouger(Contexte* ctxt) override;
    void attaquer(Contexte* ctxt, vector<float>* direction) override;
    
    bool pickLimb(Contexte* ctxt);
    void giveLimb(Contexte* ctxt);

    void changeTexture(vector<float>* mv) override;
};

#endif