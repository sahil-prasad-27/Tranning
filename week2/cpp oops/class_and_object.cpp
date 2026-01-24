#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;

    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};
int main() {
    Student s1;   // object created
    s1.roll = 101;
    s1.name = "Sahil";

    s1.display();
    return 0;
}
