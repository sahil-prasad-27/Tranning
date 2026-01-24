#include<iostream>
void change(int x) {
    x = 10;
}

int main() {
    int a = 5;
    change(a);
    cout << a;   // 5
}
