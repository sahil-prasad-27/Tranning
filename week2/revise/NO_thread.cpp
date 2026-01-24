#include <iostream>
#include <vector>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    const long long LIMIT = 200000;  // increase to feel slowdown

    for (long long i = 1; i <= LIMIT; i++) {
        if (isPrime(i)) {
            // heavy computation
        }
    }

    cout << "Done (single-threaded)\n";
    return 0;
}
