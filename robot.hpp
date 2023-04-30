#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "living.hpp"

class Robot : public Living
{
  private:
    const float scale = 1.0f/8.0;
    float speed = 1.5f;
    //float speed = 5.0f;
    
  public:
    Robot(vector<Texture>& textures);
    void bouger(Contexte& ctxt) override;
    //void attaquer();
    //void pickUpItem();
    void changeTexture(vector<float>& mv) override;
};

#endif