/*
file name: zeroToHundred.cpp
Programmer name : Bramesh patel
date : march 2025
Requirements: 
Write a program from 0 to 100 count by 5.
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ofstream out;
    out.open("myfile.txt");
    int n =0;

    while(n <= 100){

       cout << n << endl;
       n += 5;
       out << n << endl;
        
   }
   out.close();

    return 0;
}