#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {
    try {
        json j = "Hello, world!";

        // Trying to access it like an array
        char firstChar = j.at(0);
        std::cout << "First character: " << firstChar << std::endl;
    }
    catch (json::type_error& e) {
        std::cout << "JSON type error: " << e.what() << std::endl;
    }

    return 0;
}
