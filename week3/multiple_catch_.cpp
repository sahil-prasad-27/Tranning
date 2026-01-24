#include<iostream>
using namespace std;

int main(){
    try{
        int x=0;
        if(x==1)
            throw x;
        else
            throw "unknown error";
    }
    catch(int a){
        cout << "inter exception : " << a << endl;
    }
    catch(const char* msg){
        cout << msg << endl;
    }
    return 0;
}