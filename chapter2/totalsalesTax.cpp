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
    double purchase = 95.00, state_sales_tax = 4, county_sales_tax = 2;

    double state_tax = (state_sales_tax / 100) * purchase;
    double county_tax = (county_sales_tax / 100) * purchase;
    double total_amount = purchase + state_tax + county_tax; 

    cout << fixed << setprecision(2) << "Total amount paid after tax is: $" << total_amount << endl;
    
    return 0;
}