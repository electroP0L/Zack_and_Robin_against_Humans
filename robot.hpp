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
    Robot(vector<Texture>& textures);
    
    void bouger(Contexte& ctxt) override;
    void attaquer(Contexte& ctxt, vector<float> direction) override;
    
    //void pickLimb();

    void changeTexture(vector<float>& mv) override;
};

#endif