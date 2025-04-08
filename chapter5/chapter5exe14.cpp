/*
File Name: Chapter5exe14.cpp
Developer/Programmer: Bramesh Patel
Date: 04/25
Requirements:
1) All students need to line up according to their first name in order of a to z.
2) Once all the names have been read, it reports which student would be at the front of the line and
which one would be at the end of the line.
3) No two students have the same name.
4) Do not accept a number < 1 or >= 25 for the number of students.
*/
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function to get a valid number of students between 1 and 25
int getNumberOfStudents() {
    int num;
    do {
        cout << "Enter the number of students (1-25): ";
        cin >> num;
        if (cin.fail() || num < 1 || num > 25) {
            cout << "Invalid input. Please enter a number between 1 and 25." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    } while (num < 1 || num > 25);
    return num;
}

// Function to read student names and determine front and end of line
void processStudentLineup(int numStudents, string &first, string &last) {
    string name;
    cout << "Enter the names of " << numStudents << " students:" << endl;

    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << (i + 1) << ": ";
        cin >> name;

        // Initialize the first and last names
        if (i == 0) {
            first = last = name;
        } else {
            if (name < first)
                first = name;
            if (name > last)
                last = name;
        }
    }
}

// Function to ask user if they want to repeat the program
bool getRepeat() {
    char choice;
    cout << "\nWould you like to run the program again? (Y/N): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear any leftover input
    return (choice == 'Y' || choice == 'y');
}

int main() {
    do {
        int numStudents = getNumberOfStudents();
        string firstInLine, lastInLine;

        processStudentLineup(numStudents, firstInLine, lastInLine);

        cout << "\nStudent at the front of the line: " << firstInLine << endl;
        cout << "Student at the end of the line: " << lastInLine << endl;

    } while (getRepeat());

    cout << "Program ended. Goodbye!" << endl;
    return 0;
}