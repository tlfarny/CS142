#pragma once
#include "Fighter.h"
#include <iostream>

class Archer : public Fighter{
protected:
    int DynamicSpeed;
    int Damage;
public:
    Archer(string Name, int MaximumHP, int Strength, int Speed, int Magic);
    ~Archer(void);
    virtual int getDamage();
    virtual void reset();
    virtual bool useAbility();
};