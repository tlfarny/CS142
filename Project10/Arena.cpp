#include "Arena.h"
#include "Fighter.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"
#include <sstream>

Arena::Arena() : ArenaInterface(){
    
}

Arena::~Arena(){
    
}

bool Arena::addFighter(string info){
    stringstream s;
    string Name, Type;
    int MaximumHP, CurrentHP, Strength, Speed, Magic;
    FighterInterface* NewFighter;
    s<<info;
    s>>Name>>Type>>MaximumHP>>Strength>>Speed>>Magic;
    CurrentHP = MaximumHP;
    for (int i=0; i<AllFighters.size(); i++) {
        if (Name==AllFighters[i]->getName()) {
       //     cout<<"\n\nERROR: A FIGHTER BY THE NAME "<<Name<<" IS ALREADY ON THE LIST OF FIGHTERS IN THE ARENA. PLEASE CHOOSE A DIFFERENT FIGHTER.\n\n";
            return false;
        }
    }
    if (MaximumHP<=0 || Strength<=0 || Speed<=0 || Magic<=0) {
      //  cout<<"\n\nERROR: ALL STATISTICS MUST BE GREATER THAN ZERO.\n\n";
        return false;
    }
    if (s.fail()) {
       // cout<<"\n\nERROR: WRONG INFORMATION ADDED. MAKE SURE THAT YOU ARE ENTERING THE INFORMATION IN THE CORRECT FORMAT.\n\n";
        return false;
    }
    else{
        if (s.eof()) {
            if (Type=="R") {
                NewFighter = new Robot(Name, MaximumHP, Strength, Speed, Magic);
            }
            else if (Type=="A"){
                NewFighter = new Archer(Name, MaximumHP, Strength, Speed, Magic);
            }
            else if (Type=="C"){
                NewFighter = new Cleric (Name, MaximumHP, Strength, Speed, Magic);
            }
            else{
            //    cout<<"\n\nERROR: FIGHTER TYPE DOES NOT MATCH ONE OF THE POSSIBLE OPTIONS.\n\n";
                return false;
            }
        }
        else{
           // cout<<"\n\nERROR: MORE INFORMATION THAN ASSIGNABLE TO FIGHTER. FIGHTER "<<Name<<" NOT ADDED TO ARENA.\n\n";
            return false;
        }
    }
    //cout<<"Fighter "<<NewFighter->getName()<<" was successfully added to the list of fighters.\n";
    AllFighters.push_back(NewFighter);
    return true;
}

bool Arena::removeFighter(string name){
    for (int i=0; i<AllFighters.size(); i++) {
        if (name==AllFighters[i]->getName()) {
            AllFighters.erase(AllFighters.begin()+i);
            return true;
        }
    }
    return false;
}

FighterInterface* Arena::getFighter(string name){
    FighterInterface* FighterToReturn;
    for (int i=0; i<AllFighters.size(); i++) {
        if (name==AllFighters[i]->getName()) {
            FighterToReturn = AllFighters[i];
            return FighterToReturn;
        }
    }
    return NULL;
}

int Arena::getSize(){
    int Size = AllFighters.size() ;
    return Size;
}



