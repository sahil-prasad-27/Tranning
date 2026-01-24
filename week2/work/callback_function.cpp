#include<iostream>
using namespace std;

void greet() {
    cout << "Hello!\n";
}

void execute(void (*func)()){
    cout<< "this is runnnig "<<endl;
    func();
    cout << "this is running 2";
}

int main(){
    execute(greet);
    return 0;
}