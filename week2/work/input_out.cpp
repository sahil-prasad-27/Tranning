#include<iostream>
using namespace std;
#include <chrono>
#include <thread>

int main(){
    int age;
    cout << "enter your age : ";
    cin >> age;

    cout << "conforming your age 19 + ";

    this_thread::sleep_for(chrono::seconds(2));

    if (age > 19){
        cout << "thank you";
        return 0;
    }else{
        cout << "not allowed";
        return 1;
    }
}