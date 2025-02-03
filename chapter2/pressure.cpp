/*
File name: pressure
Programmer: Bramesh Patel
Date: February 2025
Requirement:
Write a program to find pressure;
*/
#include<iostream>

using namespace std;

int main(){

    double force = 172.5;
    double area = 27.5;

    double pressure = area/force;

    cout << "Pressure is:" << pressure; 
}