#include<iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file("data.txt");
    string word;

    while (file >> word) {
        cout << word << " ";
    }
    file.close();

}