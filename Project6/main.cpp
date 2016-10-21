#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 20;  //GLOBAL VARIABLE

void InitializeMyArray(double ArrayToPrint[SIZE][SIZE]){
    for (int row=0; row<SIZE; row++) {
        for (int column=0; column<SIZE; column++) {
            if (column==0 || column==19) {
                ArrayToPrint[row][column] = 0;
            }
            else if (row==0 || row==19) {
                ArrayToPrint[row][column]=100;
            }
            else{
                ArrayToPrint[row][column]=0;
            }
        }
    }
}

void FillMyArray(double ArrayToPrint[SIZE][SIZE]){
    for (int row=0; row<SIZE; row++) {
        for (int column=0; column<SIZE; column++) {
            if (column==0 || column==19) {
                ArrayToPrint[row][column] = 0;
            }
            else if (row==0 || row==19) {
                ArrayToPrint[row][column]=100;
            }
            else{
                ArrayToPrint[row][column]=((ArrayToPrint[row-1][column])+(ArrayToPrint[row+1][column])+(ArrayToPrint[row][column-1])+(ArrayToPrint[row][column+1]))/4;
            }
        }
    }
}

void PrintMyArray(double ArrayToPrint[SIZE][SIZE]){
    for (int row=0; row<SIZE; row++) {
        for (int column=0; column<SIZE; column++) {
            cout<< ArrayToPrint[row][column]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}

void CompareMyArray(double ArrayToPrint[SIZE][SIZE]){
    double ArrayToPrintCopy[SIZE][SIZE];
    double change=10;
    double ChangeChart[SIZE][SIZE];
    double ChangeChartChange=0;
    while (change>0.1) {
        for (int row=0; row<SIZE; row++) {
            for (int column=0; column<SIZE; column++) {
                ArrayToPrintCopy[row][column]=ArrayToPrint[row][column];
            }
        }
        FillMyArray(ArrayToPrint);
        for (int row=0; row<SIZE; row++) {
            for (int column=0; column<SIZE; column++) {
                ChangeChart[row][column]=abs(ArrayToPrint[row][column]-ArrayToPrintCopy[row][column]);
            }
        }
        for (int row=0; row<SIZE; row++) {
            for (int column=0; column<SIZE; column++){
                
                if (ChangeChart[row][column]>=ChangeChartChange) {
                    ChangeChartChange=ChangeChart[row][column];
                }
                
            }
        }
        if (ChangeChartChange<change) {
            change=ChangeChartChange;
        }
        ChangeChartChange=0;
    }
}

void SaveMyArray(double ArrayToPrint[SIZE][SIZE]){
    cout<<"Where would you like to save this file?\n";
    string location;
    cin>>location;
    ofstream myfile;
    myfile.open(location);
    {
        for (int row=0; row<SIZE; row++) {
            for (int column=0; column<SIZE; column++) {
                myfile<<ArrayToPrint[row][column]<<",";
            }
            myfile<<endl;
        }
        myfile.close();
    }
}`

int main(){
    double values[SIZE][SIZE];
    
    
    InitializeMyArray(values);
    PrintMyArray(values);
    FillMyArray(values);
    PrintMyArray(values);
    CompareMyArray(values);
    PrintMyArray(values);
    SaveMyArray(values);
    
    return 0;
}