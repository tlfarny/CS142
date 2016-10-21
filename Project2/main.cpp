/*
 
 Test 1:
 //Test 1 ran a 120 guest audience and 25% tip. The results are as follows:
 Enter the total number of guests to attend:
 120
 Enter the total percentage tip to be paid:
 25
 Order 17 Large Pizzas.
 Order 0 Medium Pizzas.
 Order 1 Small Pizzas.
 The total surface area of the pizza that will be ordered is 5453.8 square inches.
 The total surface area of pizza each guest can eat is 45.4483 square inches.
 The total cost after tip will be $321.

 Test 2:
 //Test 1 ran a 338 Guest count and a 12% tip. Results:
 Enter the total number of guests to attend:
 338
 Enter the total percentage tip to be paid:
 12
 Order 48 Large Pizzas.
 Order 0 Medium Pizzas.
 Order 2 Small Pizzas.
 The total surface area of the pizza that will be ordered is 15305.8 square inches.
 The total surface area of pizza each guest can eat is 45.2835 square inches.
 The total cost after tip will be $806.

 Test 3:
 //Test 3 ran with 1300 guests and a 14.25 percent tip. Results:
 Enter the total number of guests to attend:
 1300
 Enter the total percentage tip to be paid:
 14.25
 Order 185 Large Pizzas.
 Order 1 Medium Pizzas.
 Order 2 Small Pizzas.
 The total surface area of the pizza that will be ordered is 58546.7 square inches.
 The total surface area of pizza each guest can eat is 45.0359 square inches.
 The total cost after tip will be $3133.

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    double pi = 3.14159;
    const int DIAMETERL = 20;
    const int DIAMETERM = 16;
    const int DIAMETERS = 12;
    const double PRICEL = 14.68;
    const double PRICEM = 11.48;
    const double PRICES = 7.28;
    cout<<"Enter the total number of guests to attend:\n";
    int guests;
    cin>>guests;
    cout<<"Enter the total percentage tip to be paid:\n";
    double TIPPERCENT;
    cin>>TIPPERCENT;
    double TIP = TIPPERCENT / 100;
    int ORDERL = guests / 7;
    int REMAINDERm = guests % 7;
    int ORDERM = REMAINDERm / 3;
    int REMAINDERs = REMAINDERm % 3;
    int ORDERS = REMAINDERs;
    cout<<"Order "<<ORDERL<<" Large Pizzas.\n";
    cout<<"Order "<<ORDERM<<" Medium Pizzas.\n";
    cout<<"Order "<<ORDERS<<" Small Pizzas.\n";
    int RADIUSL = DIAMETERL * 0.5;
    int RADIUSm = DIAMETERM * 0.5;
    int RADIUSs = DIAMETERS * 0.5;
    double AREAL = pi * RADIUSL * RADIUSL * ORDERL;
    double AREAm = pi * RADIUSm * RADIUSm * ORDERM;
    double AREAs = pi * RADIUSs * RADIUSs * ORDERS;
    double TOTAL_AREA = AREAL + AREAm + AREAs;
    cout<<"The total surface area of the pizza that will be ordered is "<<TOTAL_AREA<<" square inches.\n";
    double PIZZA_PER_PERSON = TOTAL_AREA / guests;
    cout<<"The total surface area of pizza each guest can eat is "<<PIZZA_PER_PERSON<<" square inches.\n";
    double COSTL = PRICEL * ORDERL;
    double COSTm = PRICEM * ORDERM;
    double COSTs = PRICES * ORDERS;
    double TOTALCOST_NOTIP = COSTL + COSTm + COSTs;
    double TOTAL_TIP = TOTALCOST_NOTIP * TIP;
    double TOTAL_COST_TIPPED = TOTAL_TIP + TOTALCOST_NOTIP;
    cout<<"The total cost after tip will be $"<<fixed<<setprecision(0)<<TOTAL_COST_TIPPED<<".\n";
    return 0;
    
}