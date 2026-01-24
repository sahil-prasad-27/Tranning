#include <iostream>
using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource acquired\n";
    }

    ~Resource() {
        cout << "Resource released\n";
    }
};

int main() {
    Resource r;
    cout << "Inside main\n";
    return 0;
}
