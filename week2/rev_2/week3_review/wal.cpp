#include <iostream>
#include <sqlite3.h>

void execute(sqlite3* db, const char* sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQLite error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}
int main() {
    sqlite3* db;
    if (sqlite3_open("test.db", &db) != SQLITE_OK) {
        std::cerr << "Cannot open database\n";
        return 1;
    }
    
    execute(db, "PRAGMA journal_mode=WAL;");
    execute(db,
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT);"
    );
    execute(db, "INSERT INTO users (name) VALUES ('Alice');");
    execute(db, "INSERT INTO users (name) VALUES ('Bob');");
    // Read data (READ → from DB + WAL)
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM users;", -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* name = sqlite3_column_text(stmt, 1);
        std::cout << "User: " << id << " - " << name << std::endl;
    }
    sqlite3_finalize(stmt);

    sqlite3_close(db);
    return 0;
}
