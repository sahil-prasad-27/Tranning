#include <iostream>
#include <memory>
using namespace std;

class File {
public:
    File() {
        cout << "File opened\n";
    }

    ~File() {
        cout << "File closed\n";
    }

    void write() {
        cout << "Writing to file\n";
    }
};
int main() {
    shared_ptr<File> f1 = make_shared<File>();
    {
        shared_ptr<File> f2 = f1;
        f2->write();
        cout << "Inside inner scope\n";
    } // f2 destroyed, but resource still alive

    cout << "Back to main\n";
}
