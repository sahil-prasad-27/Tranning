#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>

constexpr size_t BUFFER_SIZE = 1024;

struct Buffer {
    char data[BUFFER_SIZE];
    size_t size = 0;
    bool ready = false;
};

Buffer buffers[2];
int writeIndex = 0;
int readIndex = 1;

std::mutex mtx;
std::condition_variable cv;
bool done = false;

void processBuffer(const char* buffer, size_t size) {
    std::cout.write(buffer, size);
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] {
            return buffers[readIndex].ready || done;
        });

        if (done && !buffers[readIndex].ready)
            break;

        processBuffer(buffers[readIndex].data,
                      buffers[readIndex].size);

        buffers[readIndex].ready = false;
        std::swap(readIndex, writeIndex);

        lock.unlock();
        cv.notify_one();
    }
}

int main() {
    std::ifstream file("data.txt", std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::thread worker(consumer);

    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] {
            return !buffers[writeIndex].ready;
        });

        file.read(buffers[writeIndex].data, BUFFER_SIZE);
        buffers[writeIndex].size = file.gcount();

        if (buffers[writeIndex].size == 0)
            break;

        buffers[writeIndex].ready = true;
        std::swap(writeIndex, readIndex);

        lock.unlock();
        cv.notify_one();
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_one();

    worker.join();
    return 0;
}
