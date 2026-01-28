#include<iostream>

using namespace std;

class A{
public:
    int x;

};

class B : public A {

};
class C : public A {

};

class D : public B, public C {

};
int main(){
    D obj;
    obj.x = 10; 
    return 0;
}