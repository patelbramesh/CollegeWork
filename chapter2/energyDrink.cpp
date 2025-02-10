/*
File name: energyDrink
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for survey of energy drink
*/
#include <iostream>

using namespace std;

int main() {

    int totalSurveyed = 16500;
    float percentEnergyDrinkers = 0.15; 
    float percentCitrusPref = 0.58; 

    int customersPurchasingEnergyDrinks = totalSurveyed * percentEnergyDrinkers;

    int customersPreferringCitrus = customersPurchasingEnergyDrinks * percentCitrusPref;

    cout << "Approximate number of customers who purchase one or more energy drinks per week: "
         << customersPurchasingEnergyDrinks << endl;

    cout << "Approximate number of customers who prefer citrus-flavored energy drinks: "
         << customersPreferringCitrus << endl;

    return 0;
}
