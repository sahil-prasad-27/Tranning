#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int count = 0;
mutex m;

void increment() {
    m.lock();
    count++;
    m.unlock();
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << count;
    return 0;
}
