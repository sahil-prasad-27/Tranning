#include <iostream>
using namespace std;

void greet() {
    cout << "Hello\n";
}

int main() {
    void (*fp)() = greet;
    fp();   // calls greet
    return 0;
}
