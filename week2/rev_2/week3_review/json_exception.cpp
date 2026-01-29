#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

int main() {
    std::string jsonString = R"({
        "name": "Alice",
        "age": 30
    })";

    json j;
    try {
        j = json::parse(jsonString);
        std::cout << "JSON parsed successfully!\n";
    }
    catch (json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << "\n";
        return 1;
    }
    catch (json::type_error& e) {
        std::cerr << "Type error: " << e.what() << "\n";
        return 1;
    }
    catch (std::exception& e) {
        std::cerr << "Other error: " << e.what() << "\n";
        return 1;
    }
    if (!j.contains("city")) {
        j["city"] = "Unknown";
    }
    if (!j.contains("email")) {
        j["email"] = "not_provided@example.com";
    }
    try {
        std::string name = j.at("name");
        int age = j.at("age");
        std::string city = j.at("city");
        std::string email = j.at("email");

        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "City: " << city << "\n";
        std::cout << "Email: " << email << "\n";
    }
    catch (json::out_of_range& e) {
        std::cerr << "Missing key error: " << e.what() << "\n";
    }
    std::cout << "\nFinal JSON:\n" << j.dump(4) << "\n";

    return 0;
}
