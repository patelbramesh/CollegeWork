/*
File name: randomNumber.cpp
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program that calculates monthly payment.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double loanAmount, annualRate, monthlyRate, monthlyPayment, totalPaid, interestPaid;
    int numPayments;

    cout << "Enter the loan amount: ";
    cin >> loanAmount;
    cout << "Enter the annual interest rate (as a percentage, e.g., 12 for 12%): ";
    cin >> annualRate;
    cout << "Enter the number of monthly payments: ";
    cin >> numPayments;

    monthlyRate = (annualRate / 12) / 100;

    monthlyPayment = (monthlyRate * pow(1 + monthlyRate, numPayments) * loanAmount) 
                                    /
                     (pow(1 + monthlyRate, numPayments) - 1);


    totalPaid = monthlyPayment * numPayments;
    interestPaid = totalPaid - loanAmount;

    cout << fixed << setprecision(2);
    cout << "\nLoan Amount:         $" << loanAmount << endl;
    cout << "Monthly Interest Rate: " << (monthlyRate * 100) << "%" << endl;
    cout << "Number of Payments:   " << numPayments << endl;
    cout << "Monthly Payment:      $" << monthlyPayment << endl;
    cout << "Amount Paid Back:     $" << totalPaid << endl;
    cout << "Interest Paid:        $" << interestPaid << endl;

    return 0;
}