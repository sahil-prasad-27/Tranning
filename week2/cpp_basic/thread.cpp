#include <iostream>
#include <thread>
using namespace std;

void task() {
    cout << "Hello from thread\n";
}

int main() {
    thread t(task);  // create thread
    t.join();        // wait for thread to finish
    return 0;
}
