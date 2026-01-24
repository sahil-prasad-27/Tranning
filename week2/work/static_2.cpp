#include<iostream>

using namespace std;

static int x = 10;

void fry(){
    
    cout <<"this is old " << x << endl;
    x++;
}

int main(){
    fry();
    cout << "this is new " << x << endl;
    fry();
    fry();
    fry();
    cout << "this is second new " << x << endl;
    return 0;
}