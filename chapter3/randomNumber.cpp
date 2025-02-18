/*
File name: randomNumber.cpp
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program that generats two random numbers and add two of them and check the answer
*/
#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

int main(){
    srand(time(0));

    int num1 = rand() % 900 + 100;
    int num2 = rand() % 900 + 100;
    int n ;
    int sum = num1+num2;


    cout << "The first number is:" << num1 << endl;
    cout << "The second number is:" << num2 << endl;
    cout<< "Enter your answer:";
    cin >> n;
    if (sum == n){
        cout << "Your answer is correct.";

        getchar();
        cout << sum << endl;
    }
    else{
        cout << "Your answer is Wrong. try again";
    }

    return 0;
}