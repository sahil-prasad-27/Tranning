#include <iostream>
#include <fstream>
#include <thread>

constexpr size_t BUFFER_SIZE = 1024;

void processBuffer(const char* buffer, size_t size) {
    std::cout.write(buffer, size);
}

int main() {
    std::ifstream file("data.txt");

    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];

    char* current = buffer1;
    char* next = buffer2;

    size_t bytesRead = 0;

    while ((bytesRead = file.readsome(current, BUFFER_SIZE)) > 0) {
        std::thread worker(processBuffer, current, bytesRead);

        std::swap(current, next);

        worker.join(); // sync
    }

    file.close();
    return 0;
}
