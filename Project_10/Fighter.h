#pragma once
#include "FighterInterface.h"
#include <iostream>

class Fighter : public FighterInterface{
protected:
    string Name;
    int MaximumHP, CurrentHP, Strength, Speed, Magic;
public:
    Fighter(string Name, int MaximumHP, int Strength, int Speed, int Magic);
    ~Fighter(void);
    virtual string getName();
    virtual int getMaximumHP();
    virtual int getCurrentHP();
    virtual int getStrength();
    virtual int getSpeed();
    virtual int getMagic();
    virtual int getDamage() = 0;
    virtual void takeDamage(int damage);
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility() = 0;
};
