#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void createTable(sqlite3* db) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS employees (
            id INTEGER PRIMARY KEY,
            name TEXT,
            profile_picture BLOB
        );
    )";
    sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
}

// Insert employee with image
void insertEmployee(sqlite3* db, const string& name, const string& imagePath) {
    ifstream file(imagePath, ios::binary);
    vector<char> imgData((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, "INSERT INTO employees (name, profile_picture) VALUES (?, ?);", -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_blob(stmt, 2, imgData.data(), imgData.size(), SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

// Retrieve image
void retrieveImage(sqlite3* db, int id, const string& outputPath) {
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, "SELECT profile_picture FROM employees WHERE id = ?;", -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const void* blob = sqlite3_column_blob(stmt, 0);
        int size = sqlite3_column_bytes(stmt, 0);
        ofstream out(outputPath, ios::binary);
        out.write(reinterpret_cast<const char*>(blob), size);
        cout << "Image saved to " << outputPath << endl;
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3* db;
    sqlite3_open("simple.db", &db);

    createTable(db);
    insertEmployee(db, "Alice", "employee1.jpg");
    retrieveImage(db, 1, "alice_copy.jpg");

    sqlite3_close(db);
    return 0;
}
