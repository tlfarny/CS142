#pragma once
#include "Fighter.h"
#include <iostream>

class Robot : public Fighter{
protected:
    int MaxElectricity, CurrentElectricity;
    int Damage, BonusDamage;
public:
    Robot(string Name, int MaximumHP, int Strength, int Speed, int Magic);
    ~Robot(void);
    virtual int getDamage();
    virtual void reset();
    virtual bool useAbility();
};