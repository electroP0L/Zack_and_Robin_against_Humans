#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "living.hpp"

class Robot : public Living
{
  private:
    const float scale = 1.0f/10.0;
    
  public:
    Robot(vector<Texture>& textures);
    
    void bouger(Contexte& ctxt) override;
    void attaquer(Contexte& ctxt, vector<float> direction) override;
    //void pickUpItem();

    void changeTexture(vector<float>& mv) override;
};

#endif