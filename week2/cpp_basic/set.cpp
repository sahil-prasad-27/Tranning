#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(20);

    for (int x : s)
        cout << x << " ";

    s.erase(10);

    cout << "\nSize: " << s.size();
    return 0;
}
