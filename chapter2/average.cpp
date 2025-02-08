/*
File name: totalsalesTax
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for average numbers 
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    float a=28,b=32,c=37,d=24,e=33, sum =0;

    sum =(a+b+c+d+e)/5;

    cout <<fixed << setprecision(2) << "The average number of 5 intergers is:" << sum;

    return 0;
}
