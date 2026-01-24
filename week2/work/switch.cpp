#include<iostream>
using namespace std;

int main(){
    int op;
    cin >> op;
    switch (op) {
        case 1:
            cout << "true";
            return 0;
        case 2:
            cout << "false";
            return 0;
        default : 
            cout << "not in the option";
            return 1;
    }
}