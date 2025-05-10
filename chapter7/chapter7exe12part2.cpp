/*
File Name: Chapter7exe12part2.cpp
Programmer: Bramesh Patel
Date: 05/25

Requirement:
Enhancement of Grade Book application to:
- Save and load student data from file
- Add a menu with options to add, search, and modify grades
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

const string DATA_FILE = "grades.txt";

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

// Display all or single student
void displayStudents(const vector<string>& names, const vector<vector<int>>& gradesList) {
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "\nStudent: " << names[i] << "\nGrades: ";
        for (int g : gradesList[i]) cout << g << " ";
        double avg = calculateAverage(gradesList[i]);
        cout << "\nAverage (lowest dropped): " << avg;
        cout << " -> Letter Grade: " << getLetterGrade(avg) << "\n";
    }
}

// Load student data from file
void loadData(vector<string>& names, vector<vector<int>>& gradesList) {
    ifstream inFile(DATA_FILE);
    if (!inFile) return;

    string name;
    while (getline(inFile, name)) {
        names.push_back(name);
        vector<int> grades;
        int n;
        while (inFile >> n) {
            if (n == -1) break;
            grades.push_back(n);
        }
        inFile.ignore(); // skip rest of line
        gradesList.push_back(grades);
    }
}

// Save student data to file
void saveData(const vector<string>& names, const vector<vector<int>>& gradesList) {
    ofstream outFile(DATA_FILE);
    for (size_t i = 0; i < names.size(); ++i) {
        outFile << names[i] << "\n";
        for (int g : gradesList[i]) outFile << g << " ";
        outFile << -1 << "\n";
    }
}

// Find student index by name
int searchStudent(const vector<string>& names, const string& target) {
    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == target) return i;
    }
    return -1;
}

// Modify grades interactively
void modifyGrade(vector<int>& grades) {
    if (grades.empty()) {
        cout << "No grades to modify.\n";
        return;
    }

    cout << "Grades: ";
    for (size_t i = 0; i < grades.size(); ++i)
        cout << "[" << i << "] " << grades[i] << "  ";
    cout << "\nEnter index to modify or -1 to cancel: ";

    string input;
    getline(cin, input);
    int idx;
    try {
        idx = stoi(input);
    } catch (...) {
        cout << "Invalid input.\n";
        return;
    }

    if (idx == -1) return;
    if (idx >= 0 && idx < static_cast<int>(grades.size())) {
        cout << "Enter new grade: ";
        getline(cin, input);
        try {
            int newGrade = stoi(input);
            if (newGrade >= 0 && newGrade <= 100)
                grades[idx] = newGrade;
            else
                cout << "Grade must be 0–100.\n";
        } catch (...) {
            cout << "Invalid input.\n";
        }
    } else {
        cout << "Invalid index.\n";
    }
}

// Main program
int main() {
    vector<string> studentNames;
    vector<vector<int>> studentGrades;

    loadData(studentNames, studentGrades);

    while (true) {
        cout << "\n--- Grade Book Menu ---\n";
        cout << "1. Add Student and Grades\n";
        cout << "2. Display All Students\n";
        cout << "3. Search for a Student\n";
        cout << "4. Modify Student Grades\n";
        cout << "5. Exit and Save\n";
        cout << "Choose an option: ";

        string input;
        getline(cin, input);
        int choice;
        try {
            choice = stoi(input);
        } catch (...) {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Enter student name: ";
            string name;
            getline(cin, name);
            if (name.empty()) {
                cout << "Name cannot be empty.\n";
                continue;
            }

            vector<int> grades;
            cout << "Enter grades for " << name << " (type -1 to stop):\n";
            while (true) {
                cout << "Grade: ";
                getline(cin, input);
                try {
                    int grade = stoi(input);
                    if (grade == -1) break;
                    if (grade >= 0 && grade <= 100)
                        grades.push_back(grade);
                    else
                        cout << "Grade must be 0–100.\n";
                } catch (...) {
                    cout << "Invalid input.\n";
                }
            }

            studentNames.push_back(name);
            studentGrades.push_back(grades);

        } else if (choice == 2) {
            displayStudents(studentNames, studentGrades);

        } else if (choice == 3) {
            cout << "Enter student name to search: ";
            string name;
            getline(cin, name);
            int idx = searchStudent(studentNames, name);
            if (idx != -1) {
                displayStudents({studentNames[idx]}, {studentGrades[idx]});
            } else {
                cout << "Student not found.\n";
            }

        } else if (choice == 4) {
            cout << "Enter student name to modify grades: ";
            string name;
            getline(cin, name);
            int idx = searchStudent(studentNames, name);
            if (idx != -1) {
                modifyGrade(studentGrades[idx]);
            } else {
                cout << "Student not found.\n";
            }

        } else if (choice == 5) {
            saveData(studentNames, studentGrades);
            cout << "Data saved. Goodbye!\n";
            break;

        } else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
