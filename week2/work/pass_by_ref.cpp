#include<iostream>
using namespace std;

void valu(int &x){
    cout << "old value" << x << endl;
    x=20;
}


int main(){
    int c=10;

    valu(c);
    cout << "new value " << c;

    return 0;
}