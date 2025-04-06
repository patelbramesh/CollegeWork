/*
File name: chapter5part1exe17.cpp
Programmer name: Bramesh Patel
Date: 03/25
Requirements:
Write a program that can be used in math tutoring for young students. It should display two random numbers 
to be added. The program should pause until the student works on the problem and presses a key to check 
the correct answer. If it's correct, it should display a congratulatory message.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate two random numbers
void generateNumber(int &num1, int &num2) {
    num1 = rand() % 900 + 100;
    num2 = rand() % 900 + 100;
}

// Function to get the result of two integers
int getResult(int num1, int num2) {
    return num1 + num2; // This should be addition, not subtraction
}

// Function to ask if the user wants to repeat
bool getRepeat() {
    char choice;
    cout << "Do you want to try another problem? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

int main() {
    int num1, num2, userAnswer, correctAnswer;
    srand(time(0)); // Seed the random number generator

    bool repeat = true;

    while (repeat) {
        generateNumber(num1, num2);
        correctAnswer = getResult(num1, num2);

        cout << "\nSolve the following problem:\n";
        cout << setw(5) << num1 << endl;
        cout << "+ " << setw(3) << num2 << endl;
        cout << "-----" << endl;

        cout << "Enter your answer: ";
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Congratulations! Your answer is correct 🎉." << endl;
        } else {
            cout << "Sorry, that's incorrect. The correct answer is " << correctAnswer << "." << endl;
        }

        repeat = getRepeat();
    }

    cout << "Thank you for using the math tutor program. Goodbye!" << endl;

    return 0;
}
