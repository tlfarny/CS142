#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int TOTALTIME = 5; //years

class Car{
private:
    string kind;
    int initPrice;
    int finalPrice;
    int milesPerYear;
    int efficiency;
public:
    Car(string kind, int initPrice, int finalPrice, int milesPerYear, int efficiency){
        this->kind = kind;
        this->initPrice = initPrice;
        this->finalPrice = finalPrice;
        this->milesPerYear = milesPerYear;
        this->efficiency = efficiency;
    };
    ~Car(){};
    
    int getTotalGallons(){
        return (TOTALTIME * this->milesPerYear / this->efficiency);
    }
    double getTotalGasCost(double gasPrice){
        return (this->getTotalGallons() * gasPrice);
    }
    int getDeprication(){
        return this->initPrice - this->finalPrice;
    }
    int getTotalCost(double gasPrice){
        return this->getDeprication() + this->getTotalGasCost(gasPrice);
    }
    void toString(double gasPrice){
        cout<<this->kind<<endl;
        cout<<"The total number of gallons of gas used over the 5 year period is "<<this->getTotalGallons()<<"."<<endl;
        cout<<"The total amount of money spent on gas in this time is $"<<this->getTotalGasCost(gasPrice)<<"."<<endl;
        cout<<"The total deprication for the car will be $"<<this->getDeprication()<<", making the total cost of owning the vehicle $"<<this->getTotalCost(gasPrice)<<"."<<endl;
    }
};

void getDetails( int &initCost, int &finalCost, int &milesPerYear, int &fuelEfficiency){
    cout<<"Enter the starting price:"<<endl;
    cin>>initCost;
    intChecker(initCost);
    cout<<"Enter the final selling price:"<<endl;
    cin>>finalCost;
    intChecker(finalCost);
    cout<<"Enter the number of miles per year to be driven:"<<endl;
    cin>>milesPerYear;
    intChecker(milesPerYear);
    cout<<"Enter the fuel efficiency of the vehicle:"<<endl;
    cin>>fuelEfficiency;
    intChecker(fuelEfficiency);
}

void intChecker(int &value){
    while (value <= 0) {
        cout<<"Invalid. Please enter a value greater than 0."<<endl;
        cin>>value;
    }
}

void stringChecker(string &str){
    while (str != "Gas" || str != "Cost") {
        cout<<"Invalid input. Please enter either \"Gas\" or \"Cost\""<<endl;
        cin>>str;
    }
}

int main(int argc, char const *argv[]) {
    int milesPerYear;
    double gasPrice;
    int fuelEfficiency;
    int initCost;
    int finalCost;
    string gasOrCost;
    cout<<"::::::HYBRID  DETAILS::::::"<<endl;
    getDetails(initCost, finalCost, milesPerYear, fuelEfficiency);
    Car hybrid = new Car("Hybrid", initCost, finalCost, milesPerYear, fuelEfficiency);
    cout<<"::::::REGULAR DETAILS::::::"<<endl;
    getDetails(initCost, finalCost, milesPerYear, fuelEfficiency);
    Car regular = new Car("Regular", initCost, finalCost, milesPerYear,fuelEfficiency);
    cout<<"Enter cost preference:"<<endl<<"For minimized gas consumption, enter \"Gas\". For minimized total cost, enter \"Cost\"."<<endl;
    cin>>gasOrCost;
    stringChecker(gasOrCost);
    if (gasOrCost == "Gas") {
        if (hybrid->getTotalGallons() < regular->getTotalGallons()) {
            hybrid->toString();
            regular->toString();
        } else {
            regular->toString();
            hybrid->toString();
        }
    } else {
        if (hybrid->getTotalCost(gasPrice) < regular->getTotalCost(gasPrice)) {
            hybrid->toString();
            regular->toString();
        } else {
            regular->toString();
            hybrid->toString();
        }
        system("pause");
        return 0;
    }