#include<iostream>
using namespace std;

int fact(int x){
    if(x == 0){
        return 1;
    }
    return x * fact(x-1);
}


int main(){
    int c=5;
    cout << "recursion : "<<fact(c);
    return 0;
}