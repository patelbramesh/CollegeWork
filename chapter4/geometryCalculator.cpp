/*
file name: geometryCalculator.cpp
Programmer name: Bramesh Patel
Date: March 2025
Requirements: 
Write a program that calculates shipping charges based on weight and distance.
*/
#include <iostream>
using namespace std;

int main() {
    int choice;
    double radius, length, width, base, height, area;

    cout << "Geometry Calculator\n";
    cout << "1. Calculate the Area of a Circle\n";
    cout << "2. Calculate the Area of a Rectangle\n";
    cout << "3. Calculate the Area of a Triangle\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        if (radius < 0) {
            cout << "Error: Radius cannot be negative.\n";
        } else {
            area = 3.14159 * radius * radius;
            cout << "The area of the circle is: " << area << endl;
        }
    } 
    else if (choice == 2) {
        cout << "Enter the length and width of the rectangle: ";
        cin >> length >> width;
        if (length < 0 || width < 0) {
            cout << "Error: Length and width cannot be negative.\n";
        } else {
            area = length * width;
            cout << "The area of the rectangle is: " << area << endl;
        }
    } 
    else if (choice == 3) {
        cout << "Enter the base and height of the triangle: ";
        cin >> base >> height;
        if (base < 0 || height < 0) {
            cout << "Error: Base and height cannot be negative.\n";
        } else {
            area = 0.5 * base * height;
            cout << "The area of the triangle is: " << area << endl;
        }
    } 
    else if (choice == 4) {
        cout << "Exiting program.\n";
    } 
    else {
        cout << "Error: Invalid choice. Please enter a number between 1 and 4.\n";
    }

    return 0;
}
