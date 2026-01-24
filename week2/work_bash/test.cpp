#include<iostream>
using namespace std;

int main(){
    int c=0;
    for(int i =0;i<5;i++){
        for(int j=0;j<c;j++){
            cout << " ";
        }
        for(int j=5;j>i;j--){
            cout << "*";
        }
        for(int j=5;j>i;j--){
            cout << "*";
        }
        c+=1;
        cout <<"" <<endl;
    }
}