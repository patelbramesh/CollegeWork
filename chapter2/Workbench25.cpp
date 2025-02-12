/*
File name: Workbench25.cpp
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
a retail grants its customer a maximim amount of credit. Each customer's
available credit is their maximum amount of credit minus the amount of credit used.

wap an algorithm and then a c++ program that ask for a customer's maximum amout of credit,
and amount of credit used. display the all information.

1.Declare our variables.
2.Get the varaiable information from the user
3.calculate
4. display input and output
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double  avaiableCredit, creditUsed, maxCredit, warningPercentage =0.1;

    cout <<"Enter your maximum credit:";
    cin >> maxCredit;
    cout <<"Enter how much have you already charged:";
    cin >> creditUsed;

    avaiableCredit = maxCredit - creditUsed;

    cout << fixed << setw(20)<< setprecision(2)<< "Your max credit is:" << maxCredit;
    cout << fixed << setw(20)<< setprecision(2)<< "You have spent $" << creditUsed;
    cout << fixed << setw(20)<< setprecision(2)<< "You have $" << avaiableCredit << "remaining.";

    if(avaiableCredit < 0){
        cout << endl << "We are coming to send to collect!!";
    }
    else if(avaiableCredit < creditUsed * warningPercentage){
        cout << endl << "you are clouser to reach your max limit -  careful";
    }
    else 
        cout << endl << "thank you for shopping with us.";

    return 0;
}