/*
File Name: Chapter6exe24.cpp
Developer/Programmer: Bramesh Patel
Date: 05/25
Requirements: Write a Rock, Paper, Scissors game between user and computer. 
All input should be validated. Use at least 3 modules. Avoid using cin.fail.
Each module must have a brief comment. Program must be repeatable.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//Gets and validates the choice
int getUserChoice() {
    string input;
    int choice = 0;

    do {
        cout << "\nChoose one:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        
        cout << "Enter choice (1-3): ";
        cin >> input;

        bool isNumeric = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (isNumeric) {
            choice = stoi(input);
            if (choice < 1 || choice > 3) {
                cout << "Invalid range. Please enter a number between 1 to 3.\n";
                choice = 0;
            }
        } else {
            cout << "Invalid input. Numbers only, please.\n";
        }

    } while (choice == 0);

    return choice;
}

// Determines and displays the result of the game
// 0 = Rock, 1 = Paper, 2 = Scissors

void determineWinner(int userChoice, int computerChoice) {
    string choices[3] = {"Rock", "Paper", "Scissors"};

    cout << "\nYou chose: " << choices[userChoice] << endl;
    cout << "Computer chose: " << choices[computerChoice] << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie! Play again.\n";
    } else if (
        (userChoice == 0 && computerChoice == 2) // Rock beats Scissors
    ) {
        cout << "You win! Rock smashes Scissors.\n";
    } else if (
        (userChoice == 1 && computerChoice == 0) // Paper beats Rock
    ) {
        cout << "You win! Paper wraps Rock.\n";
    } else if (
        (userChoice == 2 && computerChoice == 1) // Scissors beats Paper
    ) {
        cout << "You win! Scissors cuts Paper.\n";
    } else if (
        (computerChoice == 0 && userChoice == 2)
    ) {
        cout << "Computer wins! Rock smashes Scissors.\n";
    } else if (
        (computerChoice == 1 && userChoice == 0)
    ) {
        cout << "Computer wins! Paper wraps Rock.\n";
    } else if (
        (computerChoice == 2 && userChoice == 1)
    ) {
        cout << "Computer wins! Scissors cuts Paper.\n";
    }
}

int main() {
    srand(time(0));
    char again;

    do {
        int userChoice = getUserChoice()-1;

        int computerChoice = rand() % 3;

        determineWinner(userChoice, computerChoice);

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;

        again = tolower(again);

    } while (again == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}
