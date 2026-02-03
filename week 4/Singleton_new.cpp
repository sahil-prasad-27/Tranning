#include <iostream>
#include <string>
using namespace std;
class Logger {
public:
    // Global access point
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    void log(const string& message) {
        cout << "[LOG] " << message << endl;
    }

    
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
   
    Logger() {
        cout << "Logger initialized\n";
    }
};

int main() {
    
    Logger& logger1 = Logger::getInstance();
    logger1.log("Application started");

   
    Logger& logger2 = Logger::getInstance();
    logger2.log("Performing some operations");

    
    cout << "Address of logger1: " << &logger1 << endl;
    cout << "Address of logger2: " << &logger2 << endl;

    return 0;
}
