/*
File Name: Chapter6exe24part2.cpp
Developer/Programmer: Bramesh Patel
Date: 05/25
Requirements: 
Repeatable Rock, Paper, Scissors game with player name input and win counter.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
using namespace std;

// Gets and validates the player's choice (1 = Rock, 2 = Paper, 3 = Scissors)
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

    return choice - 1; // Convert to 0 index
}

// Determines the winner and displays
int determineWinner(int userChoice, int computerChoice) {
    string choices[3] = {"Rock", "Paper", "Scissors"};
    cout << "\nYou chose: " << choices[userChoice] << endl;
    cout << "Computer chose: " << choices[computerChoice] << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie! Play again.\n";
        return 0;
    } else if (
        (userChoice == 0 && computerChoice == 2) // Rock beats Scissors
    ) {
        cout << "You win! Rock smashes Scissors.\n";
        return 1;
    } else if (
        (userChoice == 1 && computerChoice == 0) // Paper beats Rock
    ) {
        cout << "You win! Paper wraps Rock.\n";
        return 1;
    } else if (
        (userChoice == 2 && computerChoice == 1) // Scissors beats Paper
    ) {
        cout << "You win! Scissors cuts Paper.\n";
        return 1;
    } else if (computerChoice == 0 && userChoice == 2) {
        cout << "Computer wins! Rock smashes Scissors.\n";
    } else if (computerChoice == 1 && userChoice == 0) {
        cout << "Computer wins! Paper wraps Rock.\n";
    } else if (computerChoice == 2 && userChoice == 1) {
        cout << "Computer wins! Scissors cuts Paper.\n";
    }
    return 0;
}

int main() {
    srand(time(0));
    string playerName;
    string doAgain;
    map<string, int> playerWins; // Map to store wins for each player

    cout << "Enter your name: ";
    getline(cin, playerName);

    do {
        int userChoice = getUserChoice();
        int computerChoice = rand() % 3;

        int result = determineWinner(userChoice, computerChoice);
        
        if (result == 1) {
            playerWins[playerName]++; // Increment the win counter for the player
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> doAgain;

        //prevent leftover newline in input buffer
        cin.ignore();

    } while (doAgain == "Y" || doAgain == "y");

    cout << "\nThanks for playing, " << playerName << "!\n";
    cout << "You won " << playerWins[playerName] << " time(s).\n";

    // Displaying win count
    cout << "\n--- Win Counts ---\n";
    for (const auto& entry : playerWins) {
        cout << entry.first << " won " << entry.second << " time(s).\n";
    }

    return 0;
}