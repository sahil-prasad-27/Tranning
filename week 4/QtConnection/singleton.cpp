#include <iostream>
class Singleton {
private:
    Singleton() {
        std::cout << "Singleton instance created!\n";
    }
    
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    friend Singleton* getSingletonInstance();
    
    void showMessage() {
        std::cout << "Hello from Singleton!\n";
    }
};
Singleton* singletonInstance = nullptr;
Singleton* getSingletonInstance() {
    if (singletonInstance == nullptr) {
        singletonInstance = new Singleton();
    }
    return singletonInstance;
}
int main() {
    Singleton* s1 = getSingletonInstance();
    s1->showMessage();

    Singleton* s2 = getSingletonInstance();
    s2->showMessage();

    if (s1 == s2) {
        std::cout << "Both point to the same instance!\n";
    }
    return 0;
}
