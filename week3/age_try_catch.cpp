#include<iostream>
using namespace std;

int main(){
    try{
        int age;
        cout << "Enter age : ";
        cin >> age;

        if(age < 0)
            throw age;

        cout << "Age is valid " << endl;
    }
    catch (int x) {
        cout << "invalid age : " << x << endl;
    }
    return 0;
}