/*
 
 
 
 
 
Test 1:  I tested all of the functions of the menu: One, Multiple, and Quit. For my values, I just used 1 chip in slot 1 for both and then quit immediately afterward.
 
 Test 1 Results:
 
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 One
 Enter the number of the slot in which you would like to drop the chip:
 1
 0
 The path of your chip was:
 1
 1.5
 1
 1.5
 2
 2.5
 3
 3.5
 4
 4.5
 4
 3.5
 4
 The amount of money that you won is $10000.
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Multiple
 Enter the number of chips that you would like to drop into the Plinko machine:
 1
 Enter the number of the slot in which you would like to drop your chips:
 1
 The total amount of money won was $100.
 The average amount of money won for each chip was $100.
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Quit
 Quitting....
 
 
 
 
 Test 2: This test I was trying out all of the error codes to ensure that they were working correctly. This meant that I needed to break the slot for both "One" and "Multiple" as well as the number of chips for the "Multiple". 
 
 Test 2 Results:
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 One
 Enter the number of the slot in which you would like to drop the chip:
 10
 Error. Returned to Menu.
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Multiple
 Enter the number of chips that you would like to drop into the Plinko machine:
 -1
 Error. Returned to Menu.
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Multiple
 Enter the number of chips that you would like to drop into the Plinko machine:
 10
 Enter the number of the slot in which you would like to drop your chips:
 9
 Error. Returned to Menu.
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Quit
 Quitting....
 
 
 
 
 
 Test 3: This test I was checking to make sure that the averages were displaying the correct amounts. I did this by using 2 chips so that the average would be 50% of the total score and 4 chips so that the total would be 25% of the total score.
 
 Test 3 Results:
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Multiple
 Enter the number of chips that you would like to drop into the Plinko machine:
 2
 Enter the number of the slot in which you would like to drop your chips:
 4
 The total amount of money won was $500.
 The average amount of money won for each chip was $250.
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Multiple
 Enter the number of chips that you would like to drop into the Plinko machine:
 4
 Enter the number of the slot in which you would like to drop your chips:
 4
 The total amount of money won was $12000.
 The average amount of money won for each chip was $3000.
 Please enter if you would like to drop one chip, multiple chips, or quit the program.
 Enter "One", "Multiple", or "Quit".
 Quit
 Quitting....
 
 
 
 
 
 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
    const int Slot0 = 0;
    const int Slot1 = 1;
    const int Slot2 = 2;
    const int Slot3 = 3;
    const int Slot4 = 4;
    const int Slot5 = 5;
    const int Slot6 = 6;
    const int Slot7 = 7;
    const int Slot8 = 8;
    const int Slot0Score = 100;
    const int Slot1Score = 500;
    const int Slot2Score = 1000;
    const int Slot3Score = 0;
    const int Slot4Score = 10000;
    const int Slot5Score = 0;
    const int Slot6Score = 1000;
    const int Slot7Score = 500;
    const int Slot8Score = 100;
    double Slot;
    int TotalScore=0;
    int Chips=1;
    double FinalSlot;
    double SlotChange;
    string input = "";
    
    srand(time(0));
    while (input!="quit" && input!="q" && input!="Quit" && input!="Q"){
        cout<<"Please enter if you would like to drop one chip, multiple chips, or quit the program.\nEnter \"One\", \"Multiple\", or \"Quit\".\n";
        cin>>input;
        while (input!="One" && input!="one"&& input!="o" && input!="O" && input!="Multiple" && input!="multiple" && input!="M" && input!="m" && input!="quit" && input!="q" && input!="Quit" && input!="Q") {
            cout<<"Please enter if you would like to drop one chip, multiple chips, or quit the program.\nEnter \"One\", \"Multiple\", or \"Quit\".\n";
            cin>>input;
        }
        if (input=="quit" && input=="q" && input=="Quit" && input=="Q") {
            break;
        }
        while (input=="One" || input=="one"|| input=="o"||input=="O") {
            cout<<"Enter the number of the slot in which you would like to drop the chip:\n";
            cin>>Slot;
            if (Slot<0||Slot>=9) {
                cout<<"Error. Returned to Menu.\n";
                break;
            }
            cout<<TotalScore<<endl;
            cout<<"The path of your chip was:\n"<<Slot<<endl;
            for (int g=1; g<=Chips; g++) {
                for (int i = 1; i<=12; i++) {
                    int random1 = rand()% 2+1;
                    if (random1 ==1) {
                        if (i==1) {
                            if (Slot==0) {
                                SlotChange=Slot+0.5;
                            }
                            else{
                                SlotChange=Slot-0.5;
                            }
                            
                        }
                        else
                        {
                            
                            SlotChange=SlotChange-0.5;
                        }
                        if (SlotChange<=0) {
                            if (i==12) {
                                SlotChange = SlotChange;
                            }
                            else{
                                cout<<SlotChange<<endl;
                                SlotChange = SlotChange+0.5;
                                i++;
                            }
                        }
                    }
                    else if (random1==2){
                        if (i==1) {
                            if (Slot==8) {
                                SlotChange=Slot-0.5;
                            }
                            else{
                                SlotChange=Slot+0.5;
                            }
                        }
                        else{
                            SlotChange=SlotChange+0.5;
                        }
                        if (SlotChange>=8) {
                            if (i==12) {
                                SlotChange = SlotChange;
                            }
                            else{
                                cout<<SlotChange<<endl;
                                SlotChange = SlotChange-0.5;
                                i++;
                            }
                        }
                    }
                    cout<<SlotChange<<endl;
                    
                    
                }
                FinalSlot = SlotChange;
                if (FinalSlot == Slot0) {
                    TotalScore = TotalScore + Slot0Score;
                }
                if (FinalSlot == Slot1) {
                    TotalScore = TotalScore + Slot1Score;
                }
                if (FinalSlot == Slot2) {
                    TotalScore = TotalScore + Slot2Score;
                }
                if (FinalSlot==Slot3) {
                    TotalScore = TotalScore + Slot3Score;
                }
                if (FinalSlot==Slot4) {
                    TotalScore = TotalScore + Slot4Score;
                }
                if (FinalSlot==Slot5) {
                    TotalScore = TotalScore + Slot5Score;
                }
                if (FinalSlot==Slot6) {
                    TotalScore = TotalScore + Slot6Score;
                }
                if (FinalSlot==Slot7) {
                    TotalScore = TotalScore + Slot7Score;
                }
                if (FinalSlot==Slot8) {
                    TotalScore = TotalScore + Slot8Score;
                }
                cout<<"The amount of money that you won is $"<<TotalScore<<".\n";
                TotalScore=0;
                
            }
            break;
            
        }
        while (input=="Multiple" || input=="multiple" || input=="M" || input=="m") {
            cout<<"Enter the number of chips that you would like to drop into the Plinko machine:\n";\
            cin>>Chips;
            if (Chips<=0) {
                cout<<"Error. Returned to Menu.\n";
                break;
            }
            cout<<"Enter the number of the slot in which you would like to drop your chips:\n";
            double Slot;
            cin>>Slot;
            if (Slot<0 || Slot>=9) {
                cout<<"Error. Returned to Menu.\n";
                break;
            }
            for (int g=1; g<=Chips; g++) {
                for (int i = 1; i<=12; i++) {
                    int random1 = rand()% 2+1;
                    if (random1 ==1) {
                        if (i==1) {
                            if (Slot==0) {
                                SlotChange=Slot+0.5;
                            }
                            else{
                                SlotChange=Slot-0.5;
                            }
                            
                        }
                        else
                        {
                            SlotChange=SlotChange-0.5;
                        }
                        if (SlotChange<=0) {
                            if (i==12) {
                                SlotChange = SlotChange;
                            }
                            else{
                                SlotChange = SlotChange+0.5;
                                i++;
                            }
                        }
                    }
                    else if (random1==2){
                        if (i==1) {
                            if (Slot==8) {
                                SlotChange=Slot-0.5;
                            }
                            else{
                                SlotChange=Slot+0.5;
                            }
                        }
                        else{
                            SlotChange=SlotChange+0.5;
                        }
                        if (SlotChange>=8) {
                            if (i==12) {
                                SlotChange = SlotChange;
                            }
                            else{
                                SlotChange = SlotChange-0.5;
                                i++;
                            }
                        }
                    }
                }
                FinalSlot = SlotChange;
                
                if (FinalSlot == Slot0) {
                    TotalScore = TotalScore + Slot0Score;
                }
                if (FinalSlot == Slot1) {
                    TotalScore = TotalScore + Slot1Score;
                }
                if (FinalSlot == Slot2) {
                    TotalScore = TotalScore + Slot2Score;
                }
                if (FinalSlot==Slot3) {
                    TotalScore = TotalScore + Slot3Score;
                }
                if (FinalSlot==Slot4) {
                    TotalScore = TotalScore + Slot4Score;
                }
                if (FinalSlot==Slot5) {
                    TotalScore = TotalScore + Slot5Score;
                }
                if (FinalSlot==Slot6) {
                    TotalScore = TotalScore + Slot6Score;
                }
                if (FinalSlot==Slot7) {
                    TotalScore = TotalScore + Slot7Score;
                }
                if (FinalSlot==Slot8) {
                    TotalScore = TotalScore + Slot8Score;
                }
            }
            cout<<"The total amount of money won was $"<<TotalScore<<".\n";
            cout<<"The average amount of money won for each chip was $"<<TotalScore / Chips<<".\n";
            TotalScore=0;
            Chips=1;
            break;
        }
    }
    if (input=="quit" || input=="q" || input=="Quit" || input=="Q"){
        cout<<"Quitting....\n";
        return 0;
    }
}
