/*
File Name: Chapter6exe18.cpp
Developer/Programmer: Bramesh Patel
Date: 04/25
Requirement:
A paint company has determine that for every 110 square feet of wall space takes 8 hours labour and 
company charges 25$ per hour
WAP where user can write 
1)How many rooms to need to paint
2)what is the price of paint
3)what is the area of room
It should display 
- the number of gallons of paint required
- the hours of labour required
- the cost of the paint
- the labour charges
- the total cost of paint job
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double LABOR_COST_PER_HOUR = 25.00;
const double SQUARE_FEET_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;

// Get and validate input
void getInput(int &numRooms, double &paintPrice, double &totalSquareFeet) {
    
    totalSquareFeet = 0.0;

    // Get number of rooms
    do {

        cout << "Enter how many rooms need to be painted (at least 1): ";
        cin >> numRooms;

    } while (numRooms < 1);

    double roomSizes[100];

    for (int i = 0; i < numRooms; ++i) {
        do {
            cout << "No Negative Numbers" << endl;
            cout << "Enter the square feet of room " << (i + 1) << " : ";

            cin >> roomSizes[i];

        } while (roomSizes[i] < 0);
        totalSquareFeet += roomSizes[i];
    }

    // paint price per gallon
    do {
        
        cout << "Enter the price of paint per gallon (at least $10.00): ";
        cin >> paintPrice;

    } while (paintPrice < 10.00);
}

// calculations of everthing
void calculateCosts(double totalSquareFeet, double paintPrice, int &gallonsNeeded, double &laborHours,
                    double &paintCost, double &laborCost, double &totalCost) 
{
    gallonsNeeded = ceil(totalSquareFeet / SQUARE_FEET_PER_GALLON);

    laborHours = gallonsNeeded * HOURS_PER_GALLON;
    
    paintCost = gallonsNeeded * paintPrice;
    
    laborCost = laborHours * LABOR_COST_PER_HOUR;
    
    totalCost = paintCost + laborCost;
}

// Module 3: Display output
void displayResults(int gallonsNeeded, double laborHours, double paintCost, double laborCost,
                    double totalCost) 
{
    cout << fixed << setprecision(2);

    cout << "\n----- Paint Job Estimate -----\n";
    
    cout << "Gallons of paint required: " << gallonsNeeded << endl;
    
    cout << "Hours of labor required: " << laborHours << endl;
    
    cout << "Cost of paint: $" << paintCost << endl;
    
    cout << "Labor charges: $" << laborCost << endl;
    
    cout << "Total cost of paint job: $" << totalCost << endl;
}

int main() {

    char choice;

    do {
        // Variables
        int numRooms, gallonsNeeded;
       
        double totalSquareFeet, paintPrice, laborHours, paintCost, laborCost, totalCost;

        getInput(numRooms, paintPrice, totalSquareFeet);
       
        calculateCosts(totalSquareFeet, paintPrice, gallonsNeeded, laborHours, paintCost, laborCost, totalCost);
       
        displayResults(gallonsNeeded, laborHours, paintCost, laborCost, totalCost);

        // Repeat
        cout << "\nWould you like to estimate another paint job? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the Paint Job Estimator!\n";
    return 0;
}

