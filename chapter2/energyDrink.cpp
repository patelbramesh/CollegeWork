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

    int totalSurveyed;
    float percentEnergyDrinkers, percentCitrusPref; 

    cout<< "Entre the munbers of peoples surveyed:";
    cin >> totalSurveyed;

    cout <<"How may peoples drinkes energy drinkes:";
    cin >> percentEnergyDrinkers;
    percentEnergyDrinkers = percentEnergyDrinkers / 100;

    cout <<"How may energy drink customers prefer citrus flavor:";
    cin >> percentCitrusPref;
    percentCitrusPref = percentCitrusPref / 100;

    int energyDrinkCustomers = totalSurveyed * percentEnergyDrinkers;

    int citrusFlavorCustomers = energyDrinkCustomers * percentCitrusPref;

    cout << "Number of customers who purchase one or more energy drinks per week: " << energyDrinkCustomers << endl;
    cout << "Number of customers who prefer citrus-flavored energy drinks: " << citrusFlavorCustomers << endl;

    return 0;
}
