/*
File name: chapter5part1exe17.cpp
Programmer name: Bramesh patel
Date: 03/25
Requirements:
 write a program that can be used in math tutore for young students. That should display two random numbers 
 added. the program should pause till students work no the problem and when he or she press a key it should 
 display correct solution.
*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

// Function to generate two random numbers
void genereatNumber(int &num1, int &num2){
    num1 = rand()%900 + 100;
    num2 = rand()%900 + 100;
}
// Function to get the result of two integers
int getResult(int num1, int num2) {
    return num1 + num2; //Addition of two numbers.
}
// to repeat the whole code.
bool getRepeat(){
    char choice;
    cout << "Do you want to try another problem? (Y/N): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');// this will Eliminate buffer. 
    return (choice == 'Y' || choice == 'y');
}

int main(){
    int num1, num2, result;
    srand(time(0)); // this will Generate new number each time.
    
    bool repeat = true;
    while(repeat){
        genereatNumber(num1,num2);
        result = getResult(num1,num2);

        cout << "\nSolve the following problem:\n";
        cout << setw(5) << num1 << endl;
        cout << "+ " << setw(3) << num2 << endl;
        cout << "-----" << endl;

        cout <<"Press Enter to see Answer.";
        cin.get();

        cout << setw(5) << result << endl;

        repeat = getRepeat();
    }
    cout << "Thank you for using the math tutor program. Goodbye!" << endl;

    return 0;
}
