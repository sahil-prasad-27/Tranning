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

    int deleteId = 1;

    auto& users = db["user"];
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)["id"] == deleteId) {
            users.erase(it);
            break;
        }
    }

    ofstream outFile("data.json");
    outFile << db.dump(4);
    outFile.close();

    cout << "User deleted successfully" << endl;
    return 0;
}
