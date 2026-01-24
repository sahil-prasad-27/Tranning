#include<iostream>
#include<fstream>
#include<nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main(){
    json db;

    ifstream inFile("data.json");
    inFile >> db;
    inFile.close();
    
    json newUser;
    newUser["id"] = 2;
    newUser["name"] = "haru";

    db["user"].push_back(newUser);

    ofstream outFile("data.json");
    outFile <<db.dump(4);
    outFile.close();

    cout << "user added succ" << endl;
    return 0;
}