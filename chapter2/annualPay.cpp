/* 
File name: annualPay
Programmer: Bramesh Patel
Date: February 2025
Requirement:
Write a program for annual pay;
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float payAmount, payPeriods, annualPay;

    cout << "Enter the amount you earn: ";
    cin >> payAmount;

    cout << "Enter the number of pay periods: ";
    cin >> payPeriods;

    annualPay = payAmount * payPeriods;

    cout << fixed << setprecision(2);
    cout << "The amount earned per year is: " << annualPay << endl;

    return 0;
}
