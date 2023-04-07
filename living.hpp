#ifndef LIVING_HPP
#define LIVING_HPP

#include "entity.hpp"
#include "command.hpp"

class Command;

class Living : public Entity
{
  public:
    virtual void bouger(Command cmd) = 0;
    //virtual void attaquer() = 0;
};  


#endif