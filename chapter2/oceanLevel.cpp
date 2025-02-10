/*
File name: oceanLevel
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for rising water levels in ocean 
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    float millimeter, years;

    cout << "Enter the amount of water rise in a year: ";
    cin >> millimeter;
    cout << "Enter the number of years: ";
    cin >> years;

    if (millimeter <= 0) {
        cout << "The amount is less than or equal to zero.";
    } else {
        cout << "Yearly ocean rise :\n";

        for (int i = 1; i <= years; i++) {
            cout << "Year " << i << ": " << (millimeter * i) << " mm higher\n";
        }
    }

    return 0;
}