/*
file name: daysInMonth.cpp
Programmer name: Bramesh Patel
Date: March 2025
Requirements: 
Write a program to determine the number of days in a given month and year.
*/

#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 100 == 0) {
        return (year % 400 == 0);
    } else {
        return (year % 4 == 0);
    }
}

int main() {
    int month, year;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cout << "Enter a month (1-12): ";
    cin >> month;

    cout << "Enter a year: ";
    cin >> year;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please enter a value between 1 and 12." << endl;
        return 1;
    }

    if (month == 2 && isLeapYear(year)) {
        cout << "29 days" << endl;
    } else {
        cout << daysInMonth[month - 1] << " days" << endl;
    }

    return 0;
}
