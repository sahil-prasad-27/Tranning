#include <iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file("data.txt");
    const size_t BUFFER_SIZE =1024;
    char buffer[BUFFER_SIZE];

    while(file.read(buffer, BUFFER_SIZE) || file.gcount() > 0) {
        cout.write(buffer, file.gcount());
    }
    file.close();
    return 0;
}