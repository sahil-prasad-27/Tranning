#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex m;
condition_variable cv;
bool ready = false;

void consumer() {
    unique_lock<mutex> lock(m);
    cv.wait(lock, [] { return ready; });
    cout << "Consumer got data\n";
}

void producer() {
    {
        lock_guard<mutex> lock(m);
        ready = true;
    }
    cv.notify_one();
}

int main() {
    thread t1(consumer);
    thread t2(producer);

    t1.join();
    t2.join();
    return 0;
}
