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

    int sum = num1+num2;


    cout << "The first number is:" << num1 << endl;
    cout << "The second number is:" << num2 << endl;
    
    cout<< setw(8) << num1 << endl;
    cout<< setw(5) <<"+"<< num2 << endl;
    cout<< setw(9) <<"______" << endl;
    getchar();
    cout << setw(9) << sum << endl;

    return 0;
}