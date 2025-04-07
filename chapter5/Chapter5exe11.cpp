/*
File Name: Chapter5exe11.cpp
Developer/Programmer: Bramesh Patel
Date: 04/25
Requirements:
This program predicts the size of a population of organisms based on:
1. A valid starting population (minimum 2),
2. A valid average daily population increase (percentage, non-negative),
3. A valid number of days for growth (minimum 1).
It displays the population size for each day. The program is modular and repeatable.
*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

// Function to get input from the user (Starting size, daily increase, and number of days)
void getInput(double &startingSize, double &dailyIncrease, int &numDays) {

    // Get starting population size (must be >= 2)
    do {
        cout << "Enter the starting number of organisms (minimum 2): ";
        cin >> startingSize;
        if (startingSize < 2)
            cout << "Invalid input. Please enter a value >= 2.\n";
    } while (startingSize < 2);

    // Get average daily population increase in percent (must be >= 0)
    do {
        cout << "Enter the average daily population increase (as %): ";
        cin >> dailyIncrease;
        if (dailyIncrease < 0)
            cout << "Invalid input. Please enter a non-negative value.\n";
    } while (dailyIncrease < 0);

    // Get number of days (must be >= 1)
    do {
        cout << "Enter the number of days the population will multiply: ";
        cin >> numDays;
        if (numDays < 1)
            cout << "Invalid input. Please enter a value >= 1.\n";
    } while (numDays < 1);
}

// Function to display the population growth each day
void displayPopulation(double &startingSize, double &dailyIncrease, int &numDays) {
    cout << fixed << setprecision(2);
    cout << "\nDay\tPopulation\n";
    cout << "-------------------\n";
    
    // Display population for each day
    for (int day = 1; day <= numDays; day++) {
        cout << day << "\t" << startingSize << endl;
        startingSize = startingSize + (startingSize * dailyIncrease / 100);  // Update population after display
    }
}

// Function to ask user if they want to repeat the program
bool getRepeat() {
    char choice;
    cout << "\nWould you like to run the program again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

int main() {
    double startingSize, dailyIncrease;
    int numDays;
    bool repeat = true;

    while (repeat) {
        getInput(startingSize, dailyIncrease, numDays);  // Get user input
        displayPopulation(startingSize, dailyIncrease, numDays);  // Display population each day
        repeat = getRepeat();  // Ask user if they want to run again
    }
    cout << "Thank you for using the Population Growth Predictor!" << endl;
    return 0;
}
