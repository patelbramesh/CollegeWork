/*
File name: chapter5part1exe17.cpp
Programmer name: Bramesh patel
Date: 03/25
Requirements:
 write a program that can be used in math tutore for young students. That should display two random numbers 
 added. the program should pause till students work no the problem and when he or she press a key to check
 for correct answer.
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

// Function to generate two random numbres
int generateNumber(int &num1,int &num2){

    
    // generate random number between 100 to 999
     num1 = rand ()% 900+100;
     num2 = rand ()% 900+100;
    
    return 0;
}
int getResult(int num1, int num2){
    return num1 - num2;
}
int main()
{
    int num1,num2,userAnswer,correctAnswer;
    
    srand(time(0)); //this generate different number everytime

    generateNumber(num1,num2);
    correctAnswer = getResult(num1,num2);
   
    cout << "Solve the following problem:"<< endl;
    cout << setw(5) << num1 << endl;
    cout << setw(1) << "- "<< num2 << endl;
    cout << setw(3) << "_____" << endl;

    cout << "Enter your answer: ";
    cin >> userAnswer;
    
    if(userAnswer == correctAnswer){
        cout << "Answer is correct."<<endl;
    }else{
        cout << "Answer is Incorrect."<< correctAnswer<< endl;
    }

    return 0;
}