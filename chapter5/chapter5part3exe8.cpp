/*
File name: chapter5part3exe8.cpp
Programmer name: Bramesh Patel
Date: 03/25
Requirements:
 Write a program that displays a menu to let the user select addition, subtraction, multiplication 
 or division. The program should not quit until the user chooses to quit by answering a prompt.
*/

#include <iostream>
#include <iomanip>
using namespace std;
// for addition
double getSum(double num1, double num2){
    return num1 + num2;
}
// for subtraction
double getSubtract(double num1, double num2){
    return num1 - num2;
}
// for Multiply
double getMultiply(double num1, double num2){
    return num1 * num2;
}
// For division
double getDivide(double num1, double num2){
    // to check if number is zero
    if (num2 == 0) { 
        cout << "Error: Cannot divide by zero!" << endl;
        return 0;
    }
    return num1 / num2;
}

// Ask user if they want to continue
bool getRepeat() {
    char choice;
    cout << "\nDo you want to perform another calculation? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
// to verify valid operators only
bool isValidOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

int main(){
    double num1, num2;
    char operation;
    bool repeat = true;

    while (repeat){
        // Display menu
        cout << "\nSelect an operation:" << endl;
        cout << "+ for Addition" << endl;
        cout << "- for Subtraction" << endl;
        cout << "* for Multiplication" << endl;
        cout << "/ for Division" << endl;
        cout << "Enter your choice: ";
        cin >> operation;

        if (!isValidOperator(operation)) {// To check any invalid signs or number
            cout << "Invalid operation. Please try again." << endl;
            continue; // Skip rest of loop, ask again
        }
        
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;


        // Perform operation
        switch (operation)
        {
        case '+':
            cout << "Result: " << getSum(num1, num2) << endl;
            break;
        case '-':
            cout << "Result: " << getSubtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Result: " << getMultiply(num1, num2) << endl;
            break;
        case '/':
            cout << "Result: " << getDivide(num1, num2) << endl;
            break;
        }

        repeat = getRepeat();
    }

    cout << "Thank you for using the calculator." << endl;
    return 0;
}
