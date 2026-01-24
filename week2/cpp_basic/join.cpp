#include <iostream>
#include <thread>
using namespace std;

void task() {
    cout << "Task started\n";
}

int main() {
    thread t(task);

    t.join();

    cout << "Main finished\n";
}