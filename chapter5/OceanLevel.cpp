#include <iostream>
#include <iomanip>

using namespace std;

void DisplayLevels(int years, float currentLevel) {
    cout << "\nDisplaying Water Levels:\n";
    for (int i = 1; i <= years; i++) {
        cout << "Year " << i << ": Water level = " << currentLevel << " units" << endl;
    }
}

void ValidateEntry(float &n) {
    while (n <= 0) {
        cout << "Invalid entry! Water level increase must be positive. Try again: ";
        cin >> n;
    }
}

void DisplayResult(int years, float n) {
    float currentLevel = 0.0;
    cout << "\nResults of Water Level Increase:\n";
    for (int i = 1; i <= years; i++) {
        currentLevel += n;
        cout << "Year " << i << ": Water level increased by " << n 
             << " ml, total level: " << currentLevel << " ml" << endl;
    }
}

bool GetRepeatInfol() {
    char choice;
    cout << "\nWould you like to repeat the process? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    float n;
    int years = 25;
    
    cout << "Welcome to Assignment #3\n";

    bool repeat = true;
    while (repeat) {
        cout << "Enter how much water level has increased in a year: ";
        cin >> n;

        ValidateEntry(n);
        DisplayResult(years, n);
        
        repeat = GetRepeatInfol();
    }

    cout << "\nProgram ended. Goodbye!";
    return 0;
}
