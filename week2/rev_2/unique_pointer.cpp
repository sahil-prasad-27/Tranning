#include <iostream>
#include <memory>
using namespace std;

class Headphones {
public:
    Headphones() { cout << "Headphones plugged in\n"; }
    ~Headphones() { cout << "Headphones unplugged\n"; }

    void listen() {
        cout << "Listening to music\n";
    }
};

int main() {
    unique_ptr<Headphones> user1 = make_unique<Headphones>();

    // unique_ptr cannot be copied
    // unique_ptr<Headphones> user2 = user1; ❌

    // Ownership transferred
    unique_ptr<Headphones> user2 = move(user1);

    user2->listen();
}
