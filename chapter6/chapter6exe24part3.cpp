/*
File Name: Chapter6exe24part3.cpp
Developer/Programmer: Bramesh Patel
Date: 05/25
Requirements:
- Play a Rock, Paper, Scissors game between the user and computer
- Show previous players' names and best scores
- Allow new games and delete old scores
- Save results to a file
- Validate all user inputs
- Make the game repeatable
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>

using namespace std;

// Function prototypes
void showScores(); // Shows scores from file
void startGame();  // Plays the game and saves score
void deleteScores(); // Deletes all scores

// Displays menu and gets validated user choice
int getMenuChoice() {
    string input;
    int choice = 0;

    do {
        cout << "\n--- Rock Paper Scissors Menu ---\n";
        cout << "1. Show Previous Scores\n";
        cout << "2. Start New Game\n";
        cout << "3. Delete Scores\n";
        cout << "4. Exit\n";
        cout << "Enter choice (1-4): ";
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
            if (choice < 1 || choice > 4) {
                cout << "Please choose a number between 1 and 4.\n";
                choice = 0;
            }
        } else {
            cout << "Invalid input. Numbers only.\n";
        }

    } while (choice == 0);

    return choice;
}

// Shows the previous scores from the file
void showScores() {
    ifstream file("scores.txt");
    if (!file) {
        cout << "No scores available.\n";
        return;
    }

    string line;
    cout << "\n--- Previous Scores ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Starts the game and tracks the score
void startGame() {
    srand(time(0));
    string playerName;
    char again;
    int userWins = 0;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, playerName);

    do {
        int userChoice, computerChoice;
        string input;

        // Input validation for choices
        do {
            cout << "\nChoose one:\n1. Rock\n2. Paper\n3. Scissors\nEnter choice (1-3): ";
            cin >> input;

            bool isNum = true;
            for (char c : input) {
                if (!isdigit(c)) {
                    isNum = false;
                    break;
                }
            }

            if (isNum) {
                userChoice = stoi(input);
                if (userChoice < 1 || userChoice > 3) {
                    cout << "Choice must be between 1 and 3.\n";
                    userChoice = 0;
                }
            } else {
                cout << "Invalid input. Please enter a number.\n";
                userChoice = 0;
            }

        } while (userChoice == 0);

        userChoice--; // Adjust to 0-indexed
        computerChoice = rand() % 3;

        string choices[3] = {"Rock", "Paper", "Scissors"};
        cout << "You chose: " << choices[userChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        if (userChoice == computerChoice) {
            cout << "It's a tie!\n";
        } else if (
            (userChoice == 0 && computerChoice == 2) ||
            (userChoice == 1 && computerChoice == 0) ||
            (userChoice == 2 && computerChoice == 1)
        ) {
            cout << "You win this round!\n";
            userWins++;
        } else {
            cout << "Computer wins this round.\n";
        }

        cout << "\nPlay again? (Y/N): ";
        cin >> again;
        again = tolower(again);

    } while (again == 'y');

    cout << "Game over! " << playerName << "'s score: " << userWins << endl;

    // Append score to file
    ofstream file("scores.txt", ios::app);
    if (file) {
        file << playerName << " - " << userWins << " wins\n";
        file.close();
    } else {
        cout << "Error writing to file.\n";
    }
}

// Deletes the scores file
void deleteScores() {
    ofstream file("scores.txt", ios::trunc);
    if (file) {
        cout << "Scores deleted successfully.\n";
        file.close();
    } else {
        cout << "Error clearing scores.\n";
    }
}

int main() {
    int choice;
    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1: showScores(); break;
            case 2: startGame(); break;
            case 3: deleteScores(); break;
            case 4: cout << "Goodbye!\n"; break;
        }

    } while (choice != 4);

    return 0;
}
