/*
file name: bmi.cpp
Programmer name : Bramesh patel
date : feb 2025
Requirements: 
Write a program to Identify body mass index.
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    double bmi,weight,height;

    cout << "Enter your weight in pounds:";
    cin >> weight;

    cout <<"Enter your height in inches:";
    cin >> height;

    bmi = ((weight * 703) /(height * height));
    cout << fixed << setprecision(2) << "Your Body Mass Index is: "<< bmi << endl;

    if (bmi <= 18.5){
        cout << "You are underweight.";
    }
    else if(bmi >= 18.5 || bmi <=25 ){
        cout << "You are normal weight.";
    }
    else if(bmi >=25.1 || bmi <= 30){
        cout << "You are overweight.";
    }
    else{
        cout << "You are obese.";
    }

    return 0;
}