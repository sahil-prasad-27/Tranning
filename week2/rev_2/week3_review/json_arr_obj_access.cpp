#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

json loadJSON(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return json::object();
    }
    json j;
    file >> j;
    return j;
}
void saveJSON(const string& filename, const json& j) {
    ofstream file(filename);
    file << setw(4) << j << endl;
}
void create(json& j) {
    json newObj = {
        {"id", 1},
        {"name", "Alice"},
        {"skills", {"C++", "Python"}}
    };
    if (!j.contains("users")) {
        j["users"] = json::array();
    }
    j["users"].push_back(newObj);

    if (!j.contains("numbers")) {
        j["numbers"] = json::array();
    }
    j["numbers"].push_back(42);
}

void read(const json& j) {
    cout << "Current JSON content:\n";
    cout << setw(4) << j << endl;
}
void update(json& j) {
    if (j.contains("users") && !j["users"].empty()) {
        j["users"][0]["name"] = "Bob";
        j["users"][0]["skills"].push_back("Java");
    }
    if (j.contains("numbers") && !j["numbers"].empty()) {
        j["numbers"][0] = 99;
    }
}
void removeElement(json& j) {
    if (j.contains("users") && !j["users"].empty()) {
        j["users"].erase(j["users"].begin());
    }
    if (j.contains("numbers") && !j["numbers"].empty()) {
        j["numbers"].erase(j["numbers"].begin());
    }
}
int main() {
    string filename = "data.json";
    json j = loadJSON(filename);
    create(j);
    saveJSON(filename, j);
    read(j);
    update(j);
    saveJSON(filename, j);
    cout << "\nAfter update:\n";
    read(j);
    removeElement(j);
    saveJSON(filename, j);
    cout << "\nAfter delete:\n";
    read(j);
    return 0;
}
