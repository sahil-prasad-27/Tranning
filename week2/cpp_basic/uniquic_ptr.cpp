#include <memory>
#include <iostream>
using namespace std;

int main() {
    unique_ptr<int> p = make_unique<int>(10);
    cout << *p;
    return 0;
}
