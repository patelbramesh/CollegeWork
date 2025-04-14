/*
File Name: chapter5exe21.cpp
Programmer Name: Bramesh Patel
Date: 04/25

Requirements: 
Guess the number, If guessed number is too high, display "Too high, guess again. If
guessed number is too low, display "Too low, try again."
-> Count number of guesses.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Generates a random number between 1 and 50
void generateRandomNumber(int &num) {
    num = rand() % 50 + 1;
}

// Checks if the guess is correct and provides hints
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

// Handles one round of the guessing game
void playGame() {
    int num, guess, attempts = 0;
    bool repeat = true;

    generateRandomNumber(num);
    cout << "\nNew Game! Guess the number (between 1 and 50): ";

    while (repeat) {
        cin >> guess;

        // Simple validation
        if (guess < 1 || guess > 50) {
            cout << "Invalid number. Try again." << endl;
            continue;
        }

        attempts++;
        repeat = !checkNumber(num, guess);
    }

    cout << "Total guesses: " << attempts << endl;
}

int main() {
    srand(time(0)); // Initialize random number generator
    char choice;

    do {
        playGame(); // Play one round

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}
