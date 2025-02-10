/*
File name: oceanLevel
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for find area 
*/
#include <iostream>

using namespace std;

int main() {
   
     float height = 6.0;
     float length = 100.0;
     float coveragePerGallon = 340.0;
     int coats = 2;

    float totalArea = height * length * coats;

    int gallonsNeeded = totalArea / coveragePerGallon;

    cout << "Total area to be painted: " << totalArea << " square feet ";
    cout << "Gallons of paint needed: " << gallonsNeeded << endl;

    return 0;
}
