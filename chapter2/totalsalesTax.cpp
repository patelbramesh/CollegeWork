/*
File name: totalsalesTax
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for total sales tax 
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double purchase, state_sales_tax, county_sales_tax;

    cout << "Enter the purchase amount: ";
    cin >> purchase;
    
    cout << "Enter the state sales tax percentage: ";
    cin >> state_sales_tax;
    
    cout << "Enter the county sales tax percentage: ";
    cin >> county_sales_tax;

    double state_tax = (state_sales_tax / 100) * purchase;
    double county_tax = (county_sales_tax / 100) * purchase;
    double total_tax = state_tax+county_tax;
    double total_amount = purchase + total_tax; 

    cout << fixed << setprecision(2) 
    << "Total tax is:" << total_tax <<"%" << endl
    << "Total amount paid after tax is: $" << total_amount << endl;
    
    return 0;
}