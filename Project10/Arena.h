#pragma once
#include <iostream>
#include <vector>
#include "FighterInterface.h"
#include "ArenaInterface.h"

class Arena : public ArenaInterface{
    
protected:
    vector<FighterInterface*> AllFighters;

public:
    Arena(void);
    ~Arena(void);
    virtual bool addFighter(string info);
    virtual bool removeFighter(string name);
    virtual FighterInterface* getFighter(string name);
    virtual int getSize();
    
};