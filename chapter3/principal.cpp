/*
File name: principal.cpp
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program that calculates number of times intrest is compounded 
*/
#include <iostream>
#include <cmath>  
#include <iomanip>  

using namespace std;

int main() {
    double principal, rate, amount, interest;
    int timesCompounded;

    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the interest rate (in %): ";
    cin >> rate;
    cout << "Enter the number of times interest is compounded per year: ";
    cin >> timesCompounded;

    rate = rate / 100;

    amount = principal * pow((1 + rate / timesCompounded), timesCompounded);
    interest = amount - principal;

    cout << fixed << setprecision(2);
    cout << "\nInterest Rate:      " << (rate * 100) << "%" << endl;
    cout << "Times Compounded:   " << timesCompounded << endl;
    cout << "Principal:          $" << principal << endl;
    cout << "Interest:           $" << interest << endl;
    cout << "Amount in Savings:  $" << amount << endl;

    return 0;
}
