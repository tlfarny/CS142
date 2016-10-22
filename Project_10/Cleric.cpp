#include "Cleric.h"

Cleric::Cleric(string Name, int MaximumHP, int Strength, int Speed, int Magic) : Fighter(Name, MaximumHP, Strength, Speed, Magic){
    MaxMana = Magic*5;
    CurrentMana = MaxMana;
}

Cleric::~Cleric(){
}

int Cleric::getDamage(){
    return Magic;
}

void Cleric::reset(){
    Fighter::reset();
    CurrentMana=MaxMana;
}
void Cleric::regenerate(){
    Fighter::regenerate();
    int ManaRegenerate=Magic/5;
    if (ManaRegenerate<=0) {
        ManaRegenerate=1;
    }
    CurrentMana=CurrentMana+ManaRegenerate;
    if (CurrentMana>MaximumHP) {
        CurrentMana=MaximumHP;
    }
}

bool Cleric::useAbility(){
    if (CurrentMana>=CLERIC_ABILITY_COST) {
        int HPIncrease=Magic/3;
        CurrentMana=CurrentMana-CLERIC_ABILITY_COST;
        if (HPIncrease<=0) {
            HPIncrease=1;
        }
        CurrentHP=CurrentHP+HPIncrease;
        if (CurrentHP>MaximumHP) {
            CurrentHP=MaximumHP;
        }
        return true;
    }
    else{
        return false;
    }
}

