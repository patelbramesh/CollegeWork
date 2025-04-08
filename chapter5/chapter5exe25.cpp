// File Name: Chapter5Ex25.cpp
// Developer/Programmer: Bramesh Patel
// Date: 04/25
// Requirements:
// This version of the program reads student names from a file (LineUp.txt),
// and determines which student would be at the front and end of the line
// based on alphabetical order. No input from the user is needed other than
// running the program.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to process student names from file
void processStudentLineupFromFile(string &first, string &last) {
    ifstream inputFile("LineUp.txt");
    string name;

    if (!inputFile) {
        cerr << "Error: Could not open LineUp.txt" << endl;
        exit(1);
    }

    bool firstName = true;

    while (inputFile >> name) {
        if (firstName) {
            first = last = name;
            firstName = false;
        } else {
            if (name < first)
                first = name;
            if (name > last)
                last = name;
        }
    }

    inputFile.close();
}

// Main function
int main() {
    string firstInLine, lastInLine;

    processStudentLineupFromFile(firstInLine, lastInLine);

    cout << "\nStudent at the front of the line: " << firstInLine << endl;
    cout << "Student at the end of the line: " << lastInLine << endl;

    cout << "\nProgram ended. Goodbye!" << endl;
    return 0;
}
