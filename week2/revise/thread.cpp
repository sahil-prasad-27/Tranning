#include <iostream>
#include <thread>
#include <vector>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void findPrimes(long long start, long long end) {
    for (long long i = start; i <= end; i++) {
        isPrime(i);
    }
}

int main() {
    const long long LIMIT = 200000;
    const int THREADS = 4; // typical laptop cores

    vector<thread> workers;
    long long chunk = LIMIT / THREADS;

    for (int i = 0; i < THREADS; i++) {
        long long start = i * chunk + 1;
        long long end = (i == THREADS - 1) ? LIMIT : start + chunk - 1;
        workers.push_back(thread(findPrimes, start, end));
    }

    for (auto &t : workers) {
        t.join();
    }

    cout << "Done (multi-threaded)\n";
    return 0;
}
