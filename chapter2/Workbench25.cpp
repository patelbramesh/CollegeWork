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
    double  avaiableCredit, creditUsed, maxCredit;

    cout <<"Enter your maximum credit:";
    cin >> maxCredit;
    cout <<"Enter how much have you already charged:";
    cin >> creditUsed;

    avaiableCredit = maxCredit - creditUsed;

    cout <<"The amount of have left: " << avaiableCredit;

    return 0;
}