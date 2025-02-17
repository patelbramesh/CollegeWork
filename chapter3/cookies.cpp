/*
File name: cookies.cpp
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program that ask the user how many cookies he/she wants to make
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int cookies;
    float sugar = 1.5, butter = 1, flour = 2.75;

    cout << "How many cookies you like to have?:";
    cin  >> cookies;

    float scalingFactor = (cookies/48.0);

    sugar = sugar * scalingFactor;
    butter = butter * scalingFactor;
    flour = flour * scalingFactor;

    cout << fixed << setprecision(2);
    cout << "The number of cookies you like " << cookies << "cups" << endl;
    cout << "The number of cups of suger you will need " << sugar << "cups" << endl;
    cout << "The number of cups of butter you will need " << butter << "cups" << endl;
    cout << "The number of cups of flour you will need " << flour << "cups" << endl;
}