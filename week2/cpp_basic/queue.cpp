#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}
