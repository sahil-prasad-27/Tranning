#include <iostream>
using namespace std;

int main(){
    try{
        int a=10, b=0;
        if (b==0)
            throw "division by zero error";

        cout << a/b <<endl;
    }
    catch(const char* msg){
        cout << "exception caught" << msg<< endl;
    }

    return 0;
}