/*
file name: minMax.cpp
Programmer name : Bramesh patel
date : feb 2025
Requirements: 
Write a program to Identify which is maximum or minimum.
*/
#include<iostream>
using namespace std;

void MIN_MAX(double x, double y){
    if(x==y){
        cout<< "Both number are equal.";
    }
    if(x>y){
        cout<< x << " this number is maximum and " << y << " this number is minimum.";
    }
    else{
        cout<< y << " this number is maximum and " << x << " this number is minimum.";
    }
}
int main(){
    double n1,n2;

    cout << "Enter A number:";
    cin >> n1;

    cout << "Enter A number:";
    cin >> n2;

    MIN_MAX(n1,n2);

    return 0;
}
