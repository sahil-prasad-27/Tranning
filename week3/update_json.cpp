#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main() {
    json db;
    ifstream inFile("data.json");
    inFile >> db;
    inFile.close();

    int updateId = 1;

    for (auto& user : db["user"]) {
        if (user["id"] == updateId) {
            user["name"] = "Updated Sahil";
        }
    }

    ofstream outFile("data.json");
    outFile << db.dump(4);
    outFile.close();

    cout << "User updated successfully" << endl;
    return 0;
}
