#include<memory>
using namespace std;

class B;

class A{
public:
    shared_ptr<B> b;
};

class B{
public:
    shared_ptr<A> a;
};

int main(){
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->b = b;
    b->a = a;
    return 0;
}