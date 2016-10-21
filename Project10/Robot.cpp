#include "Robot.h"
#include <math.h>

Robot::Robot(string Name, int MaximumHP, int Strength, int Speed, int Magic) : Fighter( Name, MaximumHP, Strength, Speed, Magic){
    MaxElectricity = 2*Magic;
    CurrentElectricity=MaxElectricity;
}

Robot::~Robot(){
}

int Robot::getDamage(){
    Damage=Strength+BonusDamage;
    BonusDamage=0;
    return Damage;
}

void Robot::reset(){
    Fighter::reset();
    CurrentElectricity=MaxElectricity;
}

bool Robot::useAbility(){
    if (CurrentElectricity>=ROBOT_ABILITY_COST) {
        BonusDamage=(Strength  * (pow( ( (double)CurrentElectricity/(double)MaxElectricity ), 4)));
        CurrentElectricity=CurrentElectricity-ROBOT_ABILITY_COST;
        return true;
    }
    else{
        return false;
    }
}
