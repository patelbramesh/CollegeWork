/*
File Name: finalExam.cpp
Programmer: bramesh patel
Date: 05/25

Requirement:
Create a Number Analysis Program that reads numbers from a file and displays statistics.

1) Prompt the user to enter a filename
2) Handle various file scenarios:
   - File not found
   - Empty file
   - Files containing non-numeric data
3) Calculate and display:
   - The lowest number in the array
   - The highest number in the array
   - The total sum of all numbers
   - The average of all numbers
4) Implement robust error handling for:
   - Invalid filenames
   - File access errors
   - Invalid data formats
5) Include validation for all user inputs
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int MAX_NUMBERS = 1000;  // Max number of entries allowed

// Function to get filename from user and check if it opens
string getFileName() {
    string filename;
    ifstream file;

    while (true) {
        cout << "Enter the filename : ";
        getline(cin, filename);

        file.open(filename);
        if (file) {
            file.close();
            return filename;
        } else {
            cout << "Error: File '" << filename << "' not found. Please try again.\n";
        }
    }
}

// Reads numeric data from file into an array
int readNumbersFromFile(const string& filename, double numbers[]) {
    ifstream inputFile(filename);
    int count = 0;
    string line;

    while (getline(inputFile, line)) {
        if (!line.empty()) {
            try {
                if (count >= MAX_NUMBERS) {
                    cerr << "Warning: Reached max limit of " << MAX_NUMBERS << " numbers.\n";
                    break;
                }
                numbers[count++] = stod(line);
            } catch (...) {
                cerr << "Warning: Skipping invalid or non-numeric line: '" << line << "'\n";
            }
        }
    }

    inputFile.close();
    return count;
}

// Analyzes the array and returns stats
void analyzeNumbers(const double numbers[], int count, double& lowest, 
                    double& highest, double& total, double& average) {
    lowest = numeric_limits<double>::max();
    highest = numeric_limits<double>::lowest();
    total = 0;

    for (int i = 0; i < count; i++) {
        if (numbers[i] < lowest) lowest = numbers[i];
        if (numbers[i] > highest) highest = numbers[i];
        total += numbers[i];
    }

    average = (count > 0) ? total / count : 0;
}

// Prints analysis results
void displayResults(double lowest, double highest, double total, double average) {
    cout << "\n===== Number Analysis Results =====\n";
    cout << left << setw(20) << "Lowest number:" << right << setw(15) << lowest << "\n";
    cout << left << setw(20) << "Highest number:" << right << setw(15) << highest << "\n";
    cout << left << setw(20) << "Total:" << right << setw(15) << total << "\n";
    cout << fixed << setprecision(2);
    cout << left << setw(20) << "Average:" << right << setw(15) << average << "\n";
    cout << "=================================\n";
}

int main() {
    cout << "===== Number Analysis Program =====\n\n";

    double numbers[MAX_NUMBERS];
    string filename = getFileName();
    int count = readNumbersFromFile(filename, numbers);

    if (count > 0) {
        double lowest, highest, total, average;
        analyzeNumbers(numbers, count, lowest, highest, total, average);
        displayResults(lowest, highest, total, average);
    } else {
        cout << "No valid numeric data found in the file.\n";
    }

    return 0;
}