#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <vector>
#include <stdexcept>

std::queue<int> buffer;
const unsigned int MAX_BUFFER_SIZE = 5;

std::mutex mtx;
std::condition_variable cv;
int dishCounter = 1;
bool doneProducing = false;

// Producer function
void producer(int id, int dishesToProduce) {
    try {
        for (int i = 0; i < dishesToProduce; ++i) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return buffer.size() < MAX_BUFFER_SIZE; });

            if (dishesToProduce <= 0) // Artificial exception for invalid input
                throw std::runtime_error("Producer received invalid dish count");

            buffer.push(dishCounter);
            std::cout << "Chef " << id << " produced dish " << dishCounter << std::endl;
            dishCounter++;

            lock.unlock();
            cv.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    } catch (const std::exception &e) {
        std::cerr << "Producer " << id << " error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Producer " << id << " encountered an unknown error.\n";
    }
}

// Consumer function
void consumer(int id) {
    try {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return !buffer.empty() || doneProducing; });

            if (buffer.empty() && doneProducing) break;

            if (!buffer.empty()) {
                int dish = buffer.front();
                buffer.pop();
                std::cout << "Waiter " << id << " served dish " << dish << std::endl;
            }

            lock.unlock();
            cv.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    } catch (const std::exception &e) {
        std::cerr << "Consumer " << id << " error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Consumer " << id << " encountered an unknown error.\n";
    }
}

int main() {
    try {
        int choice;
        std::cout << "Producer-Consumer Scenarios:\n";
        std::cout << "1. Single Producer, Single Consumer\n";
        std::cout << "2. Multiple Producers, Single Consumer\n";
        std::cout << "3. Single Producer, Multiple Consumers\n";
        std::cout << "4. Multiple Producers, Multiple Consumers\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (std::cin.fail()) throw std::runtime_error("Invalid input, not a number.");

        int numProducers = 1, numConsumers = 1, dishesPerProducer = 5;
        std::vector<std::thread> producers;
        std::vector<std::thread> consumers;

        switch(choice) {
            case 1:
                numProducers = 1; numConsumers = 1; break;
            case 2:
                numProducers = 3; numConsumers = 1; break;
            case 3:
                numProducers = 1; numConsumers = 3; break;
            case 4:
                numProducers = 3; numConsumers = 3; break;
            default:
                throw std::runtime_error("Invalid scenario choice.");
        }

        // Launch producer threads
        for (int i = 0; i < numProducers; ++i)
            producers.emplace_back(producer, i+1, dishesPerProducer);

        // Launch consumer threads
        for (int i = 0; i < numConsumers; ++i)
            consumers.emplace_back(consumer, i+1);

        // Wait for producers
        for (auto &p : producers) p.join();

        // Signal consumers production is done
        {
            std::unique_lock<std::mutex> lock(mtx);
            doneProducing = true;
        }
        cv.notify_all();

        // Wait for consumers
        for (auto &c : consumers) c.join();

        std::cout << "All dishes produced and served successfully.\n";

    } catch (const std::exception &e) {
        std::cerr << "Main error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Main encountered an unknown error.\n";
    }

    return 0;
}
