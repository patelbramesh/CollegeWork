/*
File name: area
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for find area 
*/
#include <iostream>
#include<iomanip>

using namespace std;

int main() {
   
     float height = 6.0;
     float length = 100.0;
     float coveragePerGallon = 340.0;
     int coats = 2;

    float totalArea = height * length * coats;

    float gallonsNeeded = totalArea / coveragePerGallon;

    cout << "Total area to be painted: " << totalArea << " square feet ";
    cout << fixed << setprecision(2) << "Gallons of paint needed: " << gallonsNeeded << endl;

    return 0;
}
