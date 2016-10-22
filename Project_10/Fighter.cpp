#include "Fighter.h"

Fighter::Fighter(string Name, int MaximumHP, int Strength, int Speed, int Magic) : FighterInterface(){
    this->Name=Name;
    this->MaximumHP=MaximumHP;
    this->CurrentHP=MaximumHP;
    this->Strength=Strength;
    this->Speed=Speed;
    this->Magic=Magic;
}

Fighter::~Fighter(){
}

string Fighter::getName(){
    return Name;
}

int Fighter::getMaximumHP(){
    return MaximumHP;
}

int Fighter::getCurrentHP(){
    return CurrentHP;
}

int Fighter::getStrength(){
    return Strength;
}

int Fighter::getSpeed(){
    return Speed;
}

int Fighter::getMagic(){
    return Magic;
}
void Fighter::takeDamage(int damage){
	int resistance = .25*Speed;
    int DamageTaken = (damage-resistance);
    if (DamageTaken<=0) {
        DamageTaken=1;
    }
    CurrentHP = CurrentHP - DamageTaken;
}

void Fighter::reset(){
    CurrentHP = MaximumHP;
}

void Fighter::regenerate(){
    int RegeneratedHP;
    RegeneratedHP = Strength / 6;
    if (RegeneratedHP<=0) {
        RegeneratedHP = 1;
    }
    CurrentHP=CurrentHP+RegeneratedHP;
    if (CurrentHP>MaximumHP) {
        CurrentHP=MaximumHP;
    }
}