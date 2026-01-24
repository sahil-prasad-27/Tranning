#include <iostream>
using namespace std;

void greet() {
    cout << "Hello!\n";
}

void execute(void (*func)()) {
    func();   
}

int main() {
    execute(greet);
    return 0;
}
