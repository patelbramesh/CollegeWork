/*
File Name: chapter5exe23.cpp
Programer Name: Bramesh patel
Date: 04/25
Requirement:
Write a program that use loop to display pattern a and pattern b
------------------------------
  Pattern A       Pattern B
------------------------------
+                 +++++
++                ++++
+++               +++
++++              ++
+++++             +

*/
#include<iostream>
#include <iomanip>

using namespace std;

void printPattern(int size){
   
    for (int i = 1; i <= size; i++) {
        // Print Pattern A
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }

        // Print spaces for alignment between patterns
        for (int s = 0; s < (17 - i); s++) {
            cout << " ";
        }

        // Print Pattern B 
        for (int j = size; j >= i; j--) {
            cout << "+";
        }

        cout << endl;
    }
}
int main(){
    int size;
    cout << "Enter the Size of Pattern you want to print:";
    cin  >> size;

    cout <<"-----------------------------------\n";
    cout <<"  Pattern A       Pattern B\n";
    cout <<"-----------------------------------\n";
    printPattern(size);

}