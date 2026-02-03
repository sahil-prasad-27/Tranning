#include <iostream>
using namespace std;

class Shallow {
public:
    int *data;

    Shallow(int value) {
        data = new int(value);
    }

};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1;

    *obj2.data = 30;

    cout << "obj1 data: " << *obj1.data << endl;
    cout << "obj2 data: " << *obj2.data << endl;

    return 0;


}