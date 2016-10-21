#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class Player
{
public:
    Player(string NameIn);
    ~Player(void);
    string GetName();
    int GetWins();
    int GetLosses();
    int GetDraws();
    void MatchWin();
    void MatchLoss();
    void MatchDraw();
    double GetWinRecord();
    string GetRPSThrow();
    void toString();
    
private:
    string name;
    int Wins = 0;
    int Losses = 0;
    int Draws = 0;

};