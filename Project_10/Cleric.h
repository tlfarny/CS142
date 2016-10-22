#pragma once
#include "Fighter.h"

class Cleric : public Fighter{
protected:
    int MaxMana, CurrentMana;
    int Damage;
public:
    Cleric(string Name, int MaximumHP, int Strength, int Speed, int Magic);
    ~Cleric(void);
    virtual int getDamage();
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility();
};