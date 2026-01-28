#include<iostream>
using namespace std;

class Deep {
public:
    int *data;
    Deep(int value) {
        data = new int(value);
    }
    Deep (const Deep &obj) {
        data = new int(*obj.data);
    }
    ~Deep() {
        delete data;
    }
};

int main(){
    Deep obj1(10);
    Deep obj2 = obj1;
    *obj2.data = 20;

    cout << "obj1 data: " << *obj1.data << endl;
    cout << "obj2 data: " << *obj2.data << endl;

    return 0;

}
