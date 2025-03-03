/*
file name: shippingCharges.cpp
Programmer name: Bramesh Patel
Date: March 2025
Requirements: 
Write a program that calculates shipping charges based on weight and distance.
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    double weight, distance, rate, totalCost;

    cout << "Enter the weight of the package (kg): ";
    cin >> weight;

    cout << "Enter the shipping distance (miles): ";
    cin >> distance;

    if (weight <= 0 || weight > 20) {
        cout << "Invalid weight. Must be between 0 and 20 kg." << endl;
        return 1;
    }

    if (distance < 10 || distance > 3000) {
        cout << "Invalid distance. Must be between 10 and 3,000 miles." << endl;
        return 1;
    }

    if (weight <= 2)
        rate = 1.10;
    else if (weight <= 6)
        rate = 2.20;
    else if (weight <= 10)
        rate = 3.70;
    else
        rate = 4.80;

    int segments = ceil(distance / 500.0);
    totalCost = segments * rate;

    cout << fixed << setprecision(2) << "Shipping cost: $" << totalCost << endl;

    return 0;
}