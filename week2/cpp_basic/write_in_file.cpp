

#include<iostream>
#include <fstream>

using namespace std;
int main(){
    ofstream file("data.txt");
    file << "Hello World\n";
    file << "C++ File Handling";
    file.close();
}