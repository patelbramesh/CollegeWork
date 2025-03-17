/*
file name: Exam.cpp
Programmer name : Bramesh patel
date : march 2025
Requirements: 
Write a program sales staff at Crazy Al’s works.
*/
#include<iostream>
#include<iomanip>

using namespace std;

double monthCommissionRate(double n) {

    // n = sales, x = commissionRate

    double x;

    if (n <= 0) {
        x = 0;
    } 
    else if (n <= 10000.99) {
        x = 5.0 / 100.0;
    }
    else if (n <= 14999.99) {
        x = 10.0 / 100.0;
    }
    else if (n <= 17999.99) {
        x = 12.0 / 100.0;
    }
    else if (n <= 21999.99) {
        x = 14.0 / 100.0;
    }
    else {
        x = 16.0 / 100.0;
    }

    return x;
}
double CommissionAmount(double n) {
    // n = commission
    double y;
    y = monthCommissionRate(n) * n;
    return y;
}
int main(){

    double sales, commissionRate, commission, advancePay, remainingPay;

    cout << "Enter Sales: $";
    cin >> sales;

    cout << "Enter Advance Payed Amount:";
    cin >> advancePay;

    commissionRate= monthCommissionRate(sales);
    commission = CommissionAmount(sales);
    remainingPay = commission - advancePay;

    cout << "Pay Results" << endl;
    cout << "-----------" << endl;
    cout << fixed << setprecision(2) << "Sales: $" << sales << endl;
    cout << "Commission Rate: " << commissionRate << endl;
    cout << "Commission: $" << commission << endl;
    cout << fixed << setprecision(2) << "Advance Pay: $" << advancePay << endl;
    cout << fixed << setprecision(2) << "Remaining Pay: $" << remainingPay << endl;

    return 0;

}