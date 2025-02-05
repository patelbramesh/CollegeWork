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

    float payAmount,payPeriods,annualPay;

    cout <<"Enter the amount you Earn:";
    cin >>payAmount;

    cout <<"Enter the number of pay period:";
    cin >>payPeriods;

    annualPay = payAmount * payPeriods;

    cout <<"The amount earn per year is:"<<annualPay;

    return 0;
} 