
#include<iostream>
using namespace std;

int main(){
    int n = 100;
    int numberArray1[n],numberArray2[n];

    for(int i = 1 ;i<n;i++){
        numberArray1[n] =i+1;
    }
    for(int i = 1 ;i<n;i++){
        numberArray2[n] =i;
    }
    for(int num : numberArray2){
        cout << num << endl; 
    }
}