#include <memory>
using namespace std;
#include<iostream>

class B;

class A {
public:
    shared_ptr<B> b;
};

class B {
public:
    shared_ptr<A> a;
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->b = b;
    b->a = a;
    cout<<&a->b<<endl;
    cout<<&b->a<<endl;
    return 0;
}
