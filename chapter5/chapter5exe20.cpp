/*
File Name: chapter5exe20.cpp
Programmer Name: Bramesh Patel
Date: 04/25
Requirements: 
Write a program to guess number. If guessed number is too high, display "Too high, guess again."
If guessed number is too low, display "Too low, try again." Cycle keeps going until user guesses correctly.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// This will generate random number
void generateRandomNumber(int &num) {
    num = rand() % 50 + 1;
}

// Check guess and return true if correct
bool checkNumber(int num, int guess) {
    if (guess > num) {
        cout << "Too High, guess again." << endl;
        return false;
    } else if (guess < num) {
        cout << "Too low, try again." << endl;
        return false;
    } else {
        cout << "Congratulations! You guessed the correct number." << endl;
        return true;
    }
}

int main() {
    int num, guess;
    
    srand(time(0)); // To generate new number
    
    generateRandomNumber(num);
    cout << "Guess the number (between 1 and 50): ";

    bool repeat = true;
    while (repeat) {
        cin >> guess;
        repeat = !checkNumber(num, guess); // Keep looping until guess is correct
    }

    return 0;
}
