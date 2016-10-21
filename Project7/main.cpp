/*
 
 TEST CASES:
 
 TEST CASE 1:
 
 For this test case, I just wanted to make sure that all of the error functions were working correctly. I began by inputting the wrong options on the main menu and then proceeded to input incorrect options on every menu option (1-6) which allowed for user input. This really only applied to the main menu, option 2, option 3, and option 5. On each of those options, my error commands all worked correctly, meaning that it gave the user an error message and then returned the user to the menu or reprompted the user (in the tournament).
 
 TEST CASE 2:
 
 For this test case, I wanted to make sure that the program would work correctly just off of the basic settings when the program is started. To do this, I just went through each menu option giving correct responses. The program resulted just how I expected it to.
 
 TEST CASE 3:
 
 For this test case, I decided to try the tournament with smaller and larger values than the standard 16. This worked great. My match and round information was all correct. The matches worked correctly for all sizes of 2^n where 0<n≤5.
 
 
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void VectorInitializer(vector<string> &Restaurant){
    Restaurant.push_back("Carrabba's");
    Restaurant.push_back("Cafe Rio");
    Restaurant.push_back("Ghengis Grill");
    Restaurant.push_back("Olive Garden");
    Restaurant.push_back("Kneader's");
    Restaurant.push_back("Zupas");
    Restaurant.push_back("Red Iguana");
    Restaurant.push_back("Red Rock");
    Restaurant.push_back("Panera Bakery");
    Restaurant.push_back("McDonald's");
    Restaurant.push_back("Burger King");
    Restaurant.push_back("Pizza Hut");
    Restaurant.push_back("Taco Bell");
    Restaurant.push_back("Little Caeser's Pizza");
    Restaurant.push_back("Chipotle");
    Restaurant.push_back("Dickey's BBQ");
}

void PrintMyVector(vector<string>&Restaurant){
    for (int i=0; i<Restaurant.size(); i++) {
        if (i==0) {
            cout<<Restaurant[i]<<",";
        }
        else if (i!=Restaurant.size()-1) {
            cout<<" "<<Restaurant[i]<<",";
        }
        else{
            cout<<" "<<Restaurant[i]<<endl;
        }
    }
    cout<<"END OF RESTAURANT LIST.\n";
    cout<<"NUMBER OF RESTAURANTS CURRENTLY ON LIST: "<<Restaurant.size()<<".\n";
}

string Menu(){
    string input;
    cout<<"\nMenu\n\nPlease enter one of the following options:\n1 - Display the list of restaurants\n2 - Add a name to the list of restaurants\n3 - Remove one restaurant from the list\n4 - Shuffle the list of restaurants\n5 - Enter the tournament\n6 - Quit the program\n";
    getline(cin, input);
    if (input=="1" || input=="2" || input=="3" || input=="4" || input=="5" || input=="6") {
        return input;
    }
    else{
        cout<<"ERROR: ENTER A NUMBER FROM 1 - 6\n";
    }
    return input;
}

void AddFunction(vector<string>& Restaurant){
    bool Duplicate = true;
    string RestaurantInput;
    for (int i=0; i<Restaurant.size(); i++) {
        cout<<i+1<<". "<<Restaurant[i]<<endl;
    }
    if (Duplicate==true) {
        Duplicate=false;
        cout<<"Enter the name of the restaurant that you would like to add to the end of the list:\n";
        getline(cin,RestaurantInput);
        for (int i=0; i<Restaurant.size(); i++) {
            if (RestaurantInput==Restaurant[i]) {
                Duplicate=true;
                cout<<"ERROR: RESTAURANT "<<Restaurant[i]<<" ALREADY ON THE LIST. RESTAURANT "<<Restaurant[i]<<" NOT ADDED TO THE LIST.\n";
                cout<<"The current list is "<<Restaurant.size()<<" restaurants long.\n";
            }
        }
        if (Duplicate==false) {
            Restaurant.push_back(RestaurantInput);
            cout<<"Restaurant "<<RestaurantInput<<" successfully added to the list.\n";
            cout<<"The current list is "<<Restaurant.size()<<" restaurants long.\n";
        }
    }
    
}

void DeleteFunction(vector<string>&(Restaurant),string &RestaurantToRemove, bool Tournament){
    bool flag =false;
    for (int i = 0; i<Restaurant.size()-1; i++) {
        if (Restaurant[i]==RestaurantToRemove) {
            flag=true;
        }
        if (flag==true) {
            Restaurant[i]=Restaurant[i+1];
        }
    }
    Restaurant.pop_back();
}

void ShuffleMyVector(vector<string>&Restaurant){
    for (int i=0; i<Restaurant.size(); i++) {
        int num1=rand()%Restaurant.size();
        int num2=rand()%Restaurant.size();
        string temp=Restaurant[num1];
        Restaurant[num1]=Restaurant[num2];
        Restaurant[num2]=temp;
    }
    cout<<"List successfully shuffled to :\n";
    for (int i=0; i<Restaurant.size(); i++) {
        cout<<i+1<<". "<<Restaurant[i]<<endl;
    }
}

void EnterTournament(double Rounds, vector<string>& Restaurant, bool Tournament){
    cout<<"\n\n* * * * * * LET THE TOURNAMENT BEGIN * * * * * * \n\n";
    cout<<"Enter the restaurant name of where you would rather eat:\n";
    int RoundsCount=1;
    vector<string>(RestaurantCopy) = Restaurant;
    while (RestaurantCopy.size()>=2) {
        int MatchCount=1;
        string RestaurantToRemove = "";
        string RestaurantToKeep;
        int DisplayNumber=RestaurantCopy.size();
        for (int i=0; i<RestaurantCopy.size()-1; i++){
            while(RestaurantToRemove!=RestaurantCopy[i] || RestaurantToRemove!=RestaurantCopy[i+1]){
                cout<<"Match "<<MatchCount<<" of "<<DisplayNumber/2<<" Round "<<RoundsCount<<" of "<<Rounds<<"! At which restaurant would you rather eat: "<<RestaurantCopy[i]<<" or "<<RestaurantCopy[i+1]<<"?\n";
                getline(cin, RestaurantToKeep);
                if (RestaurantToKeep==RestaurantCopy[i]) {
                    RestaurantToRemove=RestaurantCopy[i+1];
                }
                else if (RestaurantToKeep==RestaurantCopy[i+1])
                {
                    RestaurantToRemove=RestaurantCopy[i];
                }
                if (RestaurantToRemove!=RestaurantCopy[i] && RestaurantToRemove!=RestaurantCopy[i+1]) {
                    cout<<"ERROR: "<<RestaurantToRemove<<" IS NOT A VALID RESTAURANT.\n";
                    cout<<"Please re-enter which restaurant at which you would rather eat, keeping in mind case and spelling.\n";
                }
                else{
                    break;
                }
            }
            DeleteFunction(RestaurantCopy, RestaurantToRemove, Tournament);
            MatchCount++;
        }
        RoundsCount++;
    }
    cout<<"\n\n* * * * * * * * * WINNER    WINNER    WINNER * * * * * * * * *\n\n";
    cout<<RestaurantCopy[0]<<" is the place at which you would like to eat the most from the restaurants on this list.\n";
}

string TournamentPrep(vector<string>&Restaurant, bool Tournament){
    double TotalSize=Restaurant.size();
    string input ="5";
    for (double i = 1; i<=5; i++) {
        double Base = 2;
        if (pow(Base,i)==TotalSize) {
            Tournament=true;
            EnterTournament(i, Restaurant, Tournament);
            return input="6";
        }
    }
    if (Tournament==true) {
        return input;
    }
    else if (Tournament==false){
        cout<<"\nERROR: INCORRECT SIZE TO BEGIN TOURNAMENT. MUST BE 2, 4, 8, 16, OR 32 ENTRIES.\n";
    }
    return input;
}

string InputChecker(string input, vector<string> & Restaurant, bool Tournament){
    if (input=="1") {
        PrintMyVector(Restaurant);
    }
    if (input=="2") {
        AddFunction(Restaurant);
    }
    if (input=="3") {
        cout<<"Enter the name of the restaurant (in correct case!) that you would like to remove from the list:\n";
        for (int i=0; i<Restaurant.size(); i++) {
            cout<<i+1<<". "<<Restaurant[i]<<endl;
        }
        string RestaurantToRemove;
        getline(cin, RestaurantToRemove);
        bool NotPresent=true;
        if (NotPresent==true) {
            for (int i=0; i<Restaurant.size(); i++) {
                if (RestaurantToRemove==Restaurant[i]) {
                    NotPresent=false;
                }
            }
            if (NotPresent==true) {
                cout<<"ERROR: "<<RestaurantToRemove<<" IS NOT ON THE LIST. RESTAURANT "<<RestaurantToRemove<<" WAS NOT REMOVED FROM THE LIST.\n";
                cout<<"The current list is "<<Restaurant.size()<<" restaurants long.\n";
            }
            else if (NotPresent==false){
                DeleteFunction(Restaurant, RestaurantToRemove, Tournament);
                cout<<"Restaurant "<<RestaurantToRemove<<" successfully removed from the list.\n";
                cout<<"The current list is "<<Restaurant.size()<<" restaurants long.\n";
            }
        }
        
    }
    if (input=="4") {
        ShuffleMyVector(Restaurant);
    }
    if (input=="5") {
        input = TournamentPrep(Restaurant, Tournament);
    }
    return input;
}

int main(){
    srand(time(0));
    string input="";
    vector<string> Restaurant;
    bool Tournament = false;
    VectorInitializer(Restaurant);
    while (input!="6") {
        input=Menu();
        input =InputChecker(input, Restaurant, Tournament);
        
    }
    cout<<"\n\nQuitting...\n\n\n";
    return 0;
}

