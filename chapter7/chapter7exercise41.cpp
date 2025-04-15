

#include<iostream>
#include<array>
using namespace std;
int main(){
    int name[20];

    for(int i =0;i<20;i++){
      name[i]= i;
      
    }
    for(int i : name){
        cout << "this is an array:";
        cout<< name[i]<< endl;
    }
}