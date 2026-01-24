#include <iostream>
#include "MyClass.h"
using namespace std;

MyClass::MyClass(int v) {
    value = v;
}

void MyClass::display() {
    cout << "Value: " << value << endl;
}
