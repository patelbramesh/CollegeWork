
#include<iostream>

using namespace std;

int main(){
    string arr1[4] ={"New york","Boston","Atlanta","Dallas"};
    float arr2[4] ={8.258, 0.653838, 0.510823, 1.303};

    for(int i =0; i < 4; i++){
        cout << "city: " << arr1[i] << "Population: " << arr2[i] << endl;
}
return 0;
}