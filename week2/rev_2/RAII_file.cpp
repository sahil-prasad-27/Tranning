#include <cstdio>
#include <stdexcept>
#include <iostream>
using namespace std;

class FileRAII {
private:
    FILE* file;

public:
    FileRAII(const char* filename, const char* mode) :  file(fopen(filename, mode)){
        if (!file) {
            throw runtime_error("Failed to open file");
        }
        cout << "[RAII] File opened \n";
    }

    FileRAII(const FileRAII&) = delete;
    FileRAII& operator=(const FileRAII&) = delete;

    FileRAII& operator=(FileRAII&& other) noexcept {
        if ( this != &other) {
            cleanup();
            file = other.file;
            other.file = nullptr;
        }
        return *this;
    } 

    FILE* get() const{
        return file;
    }

    ~FileRAII() {
        cleanup();
    }

private:
    void cleanup(){
        if(file){
            cout << "file closed";
            fclose(file);
            file = nullptr;
        }
    }
};


void writeLogAndCrash(){
    FileRAII file("log.txt", "a");
    fputs("Writing brfore crash ...\n", file.get());

    throw runtime_error("something went wrong");
}

int main() {
    try{
        writeLogAndCrash();
    }
    catch ( const exception& e) {
        cout << "exception " << e.what() << "\n";
    }
    cout << "program continues safely\n";
    return 0;
}