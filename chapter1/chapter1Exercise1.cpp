/*
Program File Name: chapter1Exerise1.cpp
Programmer: Bramesh Patel
Date: January 2025
Requirements:
Write a c++ code to calculate someone’s gross pay.
*/
#include<iostream>
using namespace std;

int main()
{
    int hours;
    double payrate;
    double pay;

    cout << "How may hours you worked:";
    cin >> hours;

    cout <<"How much you earn per hour:";
    cin >> payrate;

    pay = hours * payrate;

    cout << "Paycheck for this week is :$" << pay <<"\n";

    return 0;
}