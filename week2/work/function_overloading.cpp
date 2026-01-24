#include<iostream>
using namespace std;

void valu(int x){
    cout << "int is called"<< endl;
}
void valu(float x){
    cout << "double ic called"<< endl;
}


int main(){
    int c=10;
    float a=10.3;
    valu(c);
    valu(a);
    cout << "function overloading";

    return 0;
}