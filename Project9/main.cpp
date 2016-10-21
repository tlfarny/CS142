/*
 Test Cases:
 
 Test Case 1:
 For this test case, I wanted to make sure that my error messages were working properly. There weren't very many this time, but there was trying to select a menu option which is not present, add a player to the all list of players and trying to start the tournament with less than two. All three cases worked properly.
 
 Test Case 2:
 For this test case, I just wanted to try everything to make sure that everything work as expected. It all did.
 
 Test Case 3:
 I tried going through the tournament with a large number and with multiple times of the same entrant to make sure that the totals would update correctly. They all did so.
 */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Player.h"


using namespace std;

void Menu(){
    cout<<"\nMenu\nPlease enter which option you would like to select:\n";
    cout<<"1 - Show all players\n";
    cout<<"2 - Add a player\n";
    cout<<"3 - Add a player to the line-up\n";
    cout<<"4 - Show the current line-up of players\n";
    cout<<"5 - FIGHT\n";
    cout<<"6 - Quit the program\n";
}

bool PlayerChecker(vector<Player*> AllPlayers, string NameToCheck){
    bool Present = false;
    for (int i=0; i>AllPlayers.size(); i++) {
        if (AllPlayers.size()==0) {
            return Present;
        }
        else if (NameToCheck==AllPlayers[i]->GetName()) {
            Present=true;
        }
    }
    return Present;
}

void AddAPlayer(vector<Player*> & AllPlayers){
    cout<<"What is the name of the person you would like to add to the list?\n";
    string NewName;
    getline(cin, NewName);
    for (int i=0; i<AllPlayers.size(); i++) {
        if (NewName==AllPlayers[i]->GetName()) {
            cout<<"ERROR: NAME IS ALREADY ON THE LIST.\n";
            return;
        }
    }
    Player* NewPlayer = new Player(NewName);
    AllPlayers.push_back(NewPlayer);
    cout<<"Player "<<NewName<<" successfully added to the list of players.\n";
    
}

void AddToLineup(vector<Player*> AllPlayers, vector<Player*> &LineUp){
    cout<<"Please type the name of the player that you would like to add to the line-up:\n";
    for (int i=0; i<AllPlayers.size(); i++) {
        cout<<i+1<<". "<<AllPlayers[i]->GetName()<<endl;
    }
    string NameToMove;
    getline(cin, NameToMove);
    Player* PointerToAdd;
    for (int i=0; i<AllPlayers.size(); i++) {
        if (NameToMove==AllPlayers[i]->GetName()) {
            PointerToAdd= AllPlayers[i];
            LineUp.push_back(PointerToAdd);
        }
    }
    
}

void DisplayPlayers(vector<Player*> EitherDependingOnSituation){
    for (int i=0; i<EitherDependingOnSituation.size(); i++) {
        EitherDependingOnSituation[i]->toString();
        cout<<endl;
    }
    cout<<"END OF LIST OF PLAYERS.\n";
}

bool FightChecker(vector<Player*> LineUp){
    bool problem=false;
    if (LineUp.size()<2) {
        cout<<"ERROR: CANNOT PROCEED WHILE LESS THAN 2 PLAYERS ARE ON THE LIST.\n";
        problem=true;
    }
    return problem;
}

void Fight(vector<Player*> & LineUp){
    cout<<"\n\n\n * *   * *   * *   * *   * *   L E T   T H E   B A T T L E   B E G I N  * *   * *   * *   * *   * * \n\n\n";
    cout<<"A battle has begun between "<<LineUp[0]->GetName()<<" and "<<LineUp[1]->GetName()<<".\n";
    if (LineUp[0]->GetName()==LineUp[1]->GetName()) {
        cout<<"The game ended in a draw because "<<LineUp[0]->GetName()<<" was battling himself.\n";
        LineUp[0]->MatchDraw();
        LineUp.erase(LineUp.begin());
        LineUp.erase(LineUp.begin());
        return;
    }
    string Throw0 = LineUp[0]->GetRPSThrow();
    string Throw1 = LineUp[1]->GetRPSThrow();
    cout<<LineUp[0]->GetName()<<" throws "<<Throw0<<".\n";
    cout<<LineUp[1]->GetName()<<" throws "<<Throw1<<".\n";
    
    if (Throw0==Throw1) {
        cout<<"THE MATCH HAS ENDED IN A DRAW!\n";
        LineUp[0]->MatchDraw();
        LineUp[1]->MatchDraw();
    }
    else if (Throw0=="Rock"){
        if (Throw1=="Paper") {
            cout<<LineUp[1]->GetName()<<" IS THE WINNER!\n";
            LineUp[1]->MatchWin();
            LineUp[0]->MatchLoss();
        }
        if (Throw1=="Scissors") {
            cout<<LineUp[0]->GetName()<<" IS THE WINNER!\n";
            LineUp[0]->MatchWin();
            LineUp[1]->MatchLoss();
        }
    }
    else if (Throw0=="Paper"){
        if (Throw1=="Rock") {
            cout<<LineUp[0]->GetName()<<" IS THE WINNER!\n";
            LineUp[1]->MatchLoss();
            LineUp[0]->MatchWin();
        }
        if (Throw1=="Scissors") {
            cout<<LineUp[1]->GetName()<<" IS THE WINNER!\n";
            LineUp[1]->MatchWin();
            LineUp[0]->MatchLoss();
        }
    }
    else if (Throw0=="Scissors"){
        if (Throw1=="Rock") {
            cout<<LineUp[1]->GetName()<<" IS THE WINNER!\n";
            LineUp[1]->MatchWin();
            LineUp[0]->MatchLoss();
        }
        if (Throw1=="Paper") {
            cout<<LineUp[0]->GetName()<<" IS THE WINNER!\n";
            LineUp[1]->MatchLoss();
            LineUp[0]->MatchWin();
        }
    }
    LineUp.erase(LineUp.begin());
    LineUp.erase(LineUp.begin());
    
}

string InputChecker(string input, vector<Player *> &AllPlayers, vector<Player*> &LineUp){
    if (input=="1") {
        cout<<"Current list of all players:\n";
        DisplayPlayers(AllPlayers);
    }
    else if (input=="2") {
        AddAPlayer(AllPlayers);
    }
    else if (input=="3") {
        AddToLineup(AllPlayers, LineUp);
    }
    else if (input=="4") {
        cout<<"Current list of players in line-up:\n";
        DisplayPlayers(LineUp);
    }
    else if (input=="5") {
        bool Problem = FightChecker(LineUp);
        if (Problem==true) {
            
        }
        else{
            Fight(LineUp);
        }
    }
    else if (input=="6") {
    }
    else{
        cout<<"ERROR: PLEASE SELECT A NUMBER 1 - 6.\n";
    }
    return input;
}

int main(){
    srand(time(0));
    string input = "";
    vector<Player*> AllPlayers;
    vector<Player*> LineUp;
    while (input!="6") {
        Menu();
        getline(cin, input);
        InputChecker(input, AllPlayers, LineUp);
        
    }
    cout<<"\n\nQuitting.....\n\n\n";
}