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

    int n;
    double sum =0,num ,avg =0;

    cout<<"Enter Numbers of Elements:";
    cin >>n;

    for(int i =0;i < n;i++){
        cout <<"Enter an element:";
        cin >> num;
        sum += num;
    }
        avg = sum / n;

    cout <<fixed << setprecision(2) 
    <<"The number of elements are:" <<n<<endl
    <<"The total of n element is:"<<sum<<endl
    <<"The average number of n elements is:" << avg;

    return 0;
}
