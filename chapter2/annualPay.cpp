/* 
File name: annualPay
Programmer: Bramesh Patel
Date: February 2025
Requirement:
Write a program for annual pay;
*/
#include<iostream>

using namespace std;

int main(){

    int payAmount=2200,payPeriods=26,annualPay;

    annualPay = payAmount * payPeriods;

    cout <<"The pay amount per month is:"<<payAmount<< endl
         <<"The pay periods in a year are:"<<payPeriods<< endl
         <<"The amount earn per year is:"<<annualPay<< endl;

    return 0;
} 