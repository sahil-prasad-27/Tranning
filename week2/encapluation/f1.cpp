#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // Constructor
    Teacher() {
        dept = "computer science";
    }

    void changedept(string newData) {
        dept = newData;
    }

    // Setter
    void setsalary(double s) {
        salary = s;
    }

    // Getter
    double getsalary() {
        return salary;
    }
};

int main() {
    Teacher t1;
    t1.name = "sahil";
    t1.subject = "c++";
    t1.setsalary(2500);

    cout << t1.dept << endl;
    cout << t1.getsalary() << endl;

    return 0;
}
