#include<iostream>
using namespace std;
int main()
{
    int const row_size = 3;
    int const col_size = 2;

    int arr1[3][2];
    int grades[3][2] = {{100,90},
                        {80,75},
                        {90,80}};
    string names[3]={"AA","BB","CC"};

    int sum ;
    for(int row = 0 ; row < row_size; row++){
        sum =0;
        for(int col = 0; col < col_size; col++){
            sum += grades[row][col];
        }
        cout << "The average for a student " << row + 1 << ": " << names[row]<< " " << sum / col_size;
        cout << endl;
    }
}