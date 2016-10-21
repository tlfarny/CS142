#include "Player.h"

using namespace std;
//-------------------------------------------------------------------------------

Player::Player(string NewName){
    name = NewName;
}

//-------------------------------------------------------------------------------

string Player::GetName(){
    return name;
}

//-------------------------------------------------------------------------------

int Player::GetWins(){
    return Wins;
}

//-------------------------------------------------------------------------------

int Player::GetLosses(){
    return Losses;
}

//-------------------------------------------------------------------------------

int Player::GetDraws(){
    return Draws;
}

//-------------------------------------------------------------------------------

void Player::MatchWin(){
    Wins++;
}

//-------------------------------------------------------------------------------

void Player::MatchLoss(){
    Losses++;
}

//-------------------------------------------------------------------------------

void Player::MatchDraw(){
    Draws++;
}

//-------------------------------------------------------------------------------

double Player::GetWinRecord(){
    double TotalMatches = Wins+Losses+Draws;
    double WinRecord;
    if (TotalMatches==0) {
        WinRecord=0;
    }
    else{
        WinRecord = 100*(GetWins()/TotalMatches);
    }
    return WinRecord;
}

//-------------------------------------------------------------------------------

string Player::GetRPSThrow(){
    string Throw;
    int Random1 = rand()% 3+1;
    if (Random1==1) {
        Throw="Rock";
    }
    if (Random1==2) {
        Throw="Paper";
    }
    if (Random1==3) {
        Throw="Scissors";
    }
    return Throw;
}

//-------------------------------------------------------------------------------

void Player::toString(){
    cout<<"Name: "<<name<<endl;
    cout<<"Wins: "<<Wins<<endl;
    cout<<"Losses: "<<Losses<<endl;
    cout<<"Draws: "<<Draws<<endl;
    cout<<"Win Record: "<<GetWinRecord()<<"%"<<endl;
}

//-------------------------------------------------------------------------------