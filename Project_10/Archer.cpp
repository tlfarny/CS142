#include "Archer.h"

Archer::Archer(string Name, int MaximumHP, int Strength, int Speed, int Magic) : Fighter(Name, MaximumHP, Strength, Speed, Magic){
    DynamicSpeed = Speed;
}

Archer::~Archer(){
}

int Archer::getDamage(){
    int DamageGiven;
    DamageGiven = getSpeed();
    return DamageGiven;
}

void Archer::reset(){
    Fighter::reset();
    Speed=DynamicSpeed;
}

bool Archer::useAbility(){
    Speed++;
    return true;
}
