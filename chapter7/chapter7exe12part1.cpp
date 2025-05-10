/*
File Name: Chapter7exe12.cpp
Developer/Programmer: Bramesh Patel
Date: 05/25

Requirement:
Create a Grade Book application using C++ that stores student names and their corresponding grades.
The program should:

1) Allow the user to enter student names (use 'done' to stop).
2) For each student, allow multiple grade entries (use -1 to stop).
3) Validate that all grades are between 0 and 100 inclusive.
4) Store student names and grades using vectors or arrays.
5) Drop the lowest grade when computing the average.
6) Calculate the average and determine the final letter grade using the following scale:
    - 90–100: A
    - 80–89: B
    - 70–79: C
    - 60–69: D
    - Below 60: F
7) Display each student’s name, all valid grades, average (after dropping lowest), and letter grade.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Calculate average after dropping lowest grade
double calculateAverage(const vector<int>& grades) {
    if (grades.empty()) return 0.0;
    if (grades.size() == 1) return grades[0];

    int sum = 0;
    int minGrade = *min_element(grades.begin(), grades.end());
    for (int grade : grades) sum += grade;
    sum -= minGrade;
    return static_cast<double>(sum) / (grades.size() - 1);
}

// Convert numeric average to letter grade
char getLetterGrade(double avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

// Display students and grades
void displayStudents(const vector<string>& names, const vector<vector<int>>& gradesList) {
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "\nStudent: " << names[i] << "\nGrades: ";
        for (int g : gradesList[i]) cout << g << " ";
        double avg = calculateAverage(gradesList[i]);
        cout << "\nAverage (lowest dropped): " << avg;
        cout << " -> Letter Grade: " << getLetterGrade(avg) << "\n";
    }
}

// Main program
int main() {
    vector<string> studentNames;
    vector<vector<int>> studentGrades;

    cout << "--- Grade Book Application ---\n";
    cout << "Enter student names (type 'done' to finish):\n";

    while (true) {
        string name;
        cout << "Enter student name: ";
        getline(cin, name);

        if (name == "done" || name == "DONE") break;
        if (name.empty()) {
            cout << "Name cannot be empty. Try again.\n";
            continue;
        }

        studentNames.push_back(name);
        vector<int> grades;

        cout << "Enter grades for " << name << " (type -1 to stop):\n";

        while (true) {
            string input;
            cout << "Grade: ";
            getline(cin, input);

            try {
                int grade = stoi(input);
                if (grade == -1) break;

                if (grade >= 0 && grade <= 100) {
                    grades.push_back(grade);
                } else {
                    cout << "Invalid grade. Must be between 0 and 100.\n";
                }
            } catch (...) {
                cout << "Invalid input. Please enter a number.\n";
            }
        }

        studentGrades.push_back(grades);
    }

    displayStudents(studentNames, studentGrades);
    return 0;
}