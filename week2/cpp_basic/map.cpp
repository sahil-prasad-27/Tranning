#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m[1] = "Apple";
    m[2] = "Banana";
    m.insert({3, "Orange"});

    for (auto x : m)
        cout << x.first << " " << x.second << endl;

    m.erase(2);

    cout << "Size: " << m.size() << endl;

    return 0;
}
