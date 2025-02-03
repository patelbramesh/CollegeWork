/*
File name: distance
Programmer: Bramesh Patel
Date: February 2025
Requirement:
Write a program to find distance;
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double speed = 25.5;
    double time = 10.75;
     double distance = speed* time;

    cout << fixed << setprecision(2)<<"Distance is:"<< distance;
     return 0;
}