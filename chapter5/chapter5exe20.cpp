/*
File Name: chapter5exe20.cpp
Programmer Name: Bramesh Patel
Date: 04/25
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SESSIONS = 10; // Max number of sessions we can store

void generateRandomNumber(int &num) {
    num = rand() % 50 + 1;
}

bool checkNumber(int num, int guess) {
    if (guess > num) {
        cout << "Too high, guess again." << endl;
        return false;
    } else if (guess < num) {
        cout << "Too low, try again." << endl;
        return false;
    } else {
        cout << "Congratulations! You guessed the correct number." << endl;
        return true;
    }
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Display Existing Sessions.\n";
    cout << "2. Play a New Session.\n";
    cout << "3. Delete Previous Sessions.\n";
    cout << "4. Exit the Program.\n";
    cout << "Enter your choice: ";
}

void displaySessions(int sessions[], int count) {
    if (count == 0) {
        cout << "No previous sessions found.\n";
    } else {
        cout << "Previous session guesses count:\n";
        for (int i = 0; i < count; ++i) {
            cout << "Session " << i + 1 << ": " << sessions[i] << " guesses\n";
        }
    }
}

void playGame(int sessions[], int &count) {
    if (count >= MAX_SESSIONS) {
        cout << "Maximum number of sessions reached.\n";
        return;
    }

    int num, guess, attempts = 0;
    generateRandomNumber(num);
    cout << "Guess the number (between 1 and 50): ";

    bool correct = false;
    while (!correct) {
        cin >> guess;
        attempts++;
        correct = checkNumber(num, guess);
    }

    sessions[count] = attempts;
    count++;
}

void deleteSessions(int sessions[], int &count) {
    count = 0;
    cout << "All previous sessions deleted.\n";
}

int main() {
    srand(time(0)); // Seed random once at start

    int sessions[MAX_SESSIONS]; // Array to store session results
    int sessionCount = 0;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displaySessions(sessions, sessionCount);
                break;
            case 2:
                playGame(sessions, sessionCount);
                break;
            case 3:
                deleteSessions(sessions, sessionCount);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}