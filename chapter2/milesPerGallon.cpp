/*
File name: milesPerGallon
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for miles per gallon 
*/
#include <iostream>

using namespace std;

int main() {

    float milesDriven, gallonsUsed;

    cout << "Enter The miles driven:";
    cin >> milesDriven;
    cout << "Enter gallons used by car:";
    cin >> gallonsUsed;

    float mpg = milesDriven / gallonsUsed;

    cout << "The car's fuel efficiency is " << mpg << " miles per gallon.";

    return 0;
}
