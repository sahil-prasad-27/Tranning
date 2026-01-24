#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main() {
    json db;
    ifstream file("data.json");
    file >> db;

    for (auto& user : db["user"]) {
        cout << "ID: " << user["id"] 
             << ", Name: " << user["name"] << endl;
    }

    file.close();
    return 0;
}
