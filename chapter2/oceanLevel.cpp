/*
File name: oceanLevel
Programmer: Bramesh Patel
Date: feburary 2025
Requirements:
Write a program for rising water levels in ocean 
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float millimeter = 1.5;
    int year1 = 5,year2 =7,year3=10;
    
    float rise1 = millimeter * year1;
    float rise2 = millimeter * year2;
    float rise3 = millimeter * year3;

    cout << fixed << setprecision(2) 
    << "The ocean level rise in " << year1 << " years is: "<< rise1<<"mm higher"<<endl
    << "The ocean level rise in " << year2 << " years is: "<< rise2<<"mm higher"<<endl
    << "The ocean level rise in " << year3 << " years is: "<< rise3<<"mm higher"<<endl;
}