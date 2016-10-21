/*
 TEST CASES:
 
 TEST CASE 1:
 
 For this test case, I decided to use all of the error functions that I programmed in. There was the main menu, buying car that was more expensive than I had in the balance, trying to buy a car that was already in the inventory, selling a car that was not in the inventory, and then end by quitting. It worked perfectly.
 
 TEST CASE 2:
 For this test case, I tried to successfully complete each step so that I would know that everything was working properly. I imported both .txt files and exported one as well. Everything working well.
 
 TEST CASE 3:
 I just wanted to make sure I could export both large and small files. Everything worked as expected.
 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Car.h"

using namespace std;

void Menu(){
    cout<<"\nMenu\n\nPlease enter the number of the option that you would like to select:\n";
    cout<<"1 - Show a current inventory of cars\n";
    cout<<"2 - Show a current balance of money\n";
    cout<<"3 - Buy a car\n";
    cout<<"4 - Sell a car\n";
    cout<<"5 - Paint a car\n";
    cout<<"6 - Load file\n";
    cout<<"7 - Save file\n";
    cout<<"8 - Quit\n\n";
}

void CarInventory(vector<Car> &CarLot, double & BankAccount){
    for (int i =0; i<CarLot.size(); i++) {
        cout<<CarLot[i].toString()<<endl;;
    }
    cout<<"\nEND OF CARS IN INVENTORY.\n";
}

void BuyACar(vector<Car> & CarLot, double & BankAccount){
    string Name, Color;
    double Price;
    cout<<"What kind of car would you like to buy?\n";
    getline(cin, Name);
    cout<<"What color is this car?\n";
    getline(cin, Color);
    cout<<"How much does this car cost?\n";
    cin>>Price;
    cin.ignore(1000,'\n');
    Car NewCar(Name, Color, Price);
    if (Price>BankAccount) {
        cout<<"ERROR: CAR COSTS MORE THAN IS AVAILABLE IN YOUR ACCOUNT ($"<<fixed<<setprecision(2)<< BankAccount<<").\n";
    }
    else{
        bool Duplicate = false;
        for (int i=0; i<CarLot.size(); i++) {
            if (NewCar.getName()==CarLot[i].getName()) {
                Duplicate=true;
            }
        }
        if (Duplicate==true) {
            cout<<"ERROR: CAR BY THIS NAME IS ALREADY IN YOUR INVENTORY.\n";
        }
        else{
        CarLot.push_back(NewCar);
        BankAccount = BankAccount-Price;
        cout<<Name<<" SUCCESSFULLY ADDED TO CAR INVENTORY.\n";
        }
    }
}

void SellACar(vector<Car> & CarLot, double & BankAccount){
    cout<<"Which car would you like to sell?\n";
    for (int i=0; i<CarLot.size(); i++) {
        cout<<i+1<<". "<<CarLot[i].getName()<<".\n";
    }
    string Name;
    double SalePrice;
    getline(cin, Name);
    bool CarNotPresent=true;
    for (int i=0; i<CarLot.size(); i++) {
        if (Name==CarLot[i].getName()) {
            SalePrice=CarLot[i].getPrice();
            CarLot.erase(CarLot.begin()+i);
            CarNotPresent=false;
            BankAccount=BankAccount+SalePrice;
        }
    }
    if (CarNotPresent==true) {
        cout<<"ERROR: INPUT "<<Name<<" DOES NOT MATCH A CAR IN THE INVENTORY.\n";
    }
    else{
        cout<<"CAR "<<Name<<" SUCCESSFULLY SOLD FOR $"<<SalePrice<<". BANK ACCOUNT BALANCE NOW $"<<BankAccount<<".\n";
    }
}

void PaintACar(vector<Car> & CarLot){
    cout<<"Which car would you like to paint?\n";
    bool CarNotOnList=true;
    int ParkingSpot;
    string CarToPaint, ColorToPaint;
    for (int i=0; i<CarLot.size(); i++) {
        cout<<i+1<<". "<<CarLot[i].getName()<<".\n";
    }
    getline(cin, CarToPaint);
    for (int i=0; i<CarLot.size(); i++) {
        if (CarToPaint==CarLot[i].getName()) {
            CarNotOnList=false;
            ParkingSpot=i;
        }
    }
    if (CarNotOnList==true) {
        cout<<"ERROR: CAR "<<CarToPaint<<" IS NOT IN THE INVENTORY OF CARS.\n";
    }
    else{
        cout<<"What color would you like to paint the "<<CarToPaint<<"?\n";
        getline(cin, ColorToPaint);
        CarLot[ParkingSpot].paint(ColorToPaint);
    }
}

void OpenFile(vector<Car> &CarLot, double &BankAccount){
    string filename, Name, Color;
    cout<<"Which file would you like to open?\n";
    getline(cin, filename);
    ifstream FileIn;
    cout<<"Opening "<<filename<<".\n\n";
    FileIn.open(filename);///Users/travisfarnsworth/Documents/CS142/Lab8/Lab8/cars1.txt
                          ///Users/travisfarnsworth/Documents/CS142/Lab8/Lab8/cars2.txt
    double AddToBalance, Price;
    FileIn>>AddToBalance;
    BankAccount = BankAccount+AddToBalance;
    while (!FileIn.eof()) {
        FileIn>>Name;
        FileIn>>Color;
        FileIn>>Price;
        CarLot.push_back(Car(Name, Color, Price));
    }
    FileIn.close();
    cout<<"SUCCESSFULLY IMPORTED CONTENTS OF "<<filename<<".\n";
}

void SaveFile(vector<Car> &CarLot,double &BankAccount){
    string FileName, Name, Color;
    double Price;
    cout<<"What would you like to call the file?\n";
    getline(cin, FileName);
    ofstream FileOut;
    cout<<"Saving to "<<FileName<<".\n\n";
    FileOut.open(FileName);
    FileOut<<fixed<<setprecision(2)<<BankAccount<<endl;
    for (int i=0; i<CarLot.size(); i++) {
        Name=CarLot[i].getName();
        Color=CarLot[i].getColor();
        Price=CarLot[i].getPrice();
        FileOut<<Name<<" "<<Color<<" "<<Price<<endl;
    }
    cout<<"SUCCESSFULLY CREATED FILE "<<FileName<<".\n";
}

string InputChecker(string input, vector<Car> &CarLot, double &BankAccount){
    if (input=="1") {
        CarInventory(CarLot, BankAccount);
    }
    else if (input=="2") {
        cout<<"The total amount in your account is $"<<fixed <<setprecision(2)<<BankAccount<<".\n";
    }
    else if (input=="3") {
        BuyACar(CarLot, BankAccount);
    }
    else if (input=="4") {
        SellACar(CarLot, BankAccount);
    }
    else if (input=="5") {
        PaintACar(CarLot);
    }
    else if (input=="6") {
        OpenFile(CarLot, BankAccount);
    }
    else if (input=="7") {
        SaveFile(CarLot, BankAccount);
    }
    else if (input=="8") {
        //Simply returns input of 7 to quit the program
    }
    else{
        cout<<"ERROR: PLEASE ENTER A MENU OPTION 1 - 8.\n";
    }
    return input;
}

int main(){
    vector<Car> CarLot;
    string input="";
    double BankAccount = 10000.00;
    while (input!="8") {
        Menu();
        getline(cin, input);
        InputChecker(input, CarLot, BankAccount);
    }
    
    cout<<"\n\nQuitting...\n\n\n";
    return 0;
    
}