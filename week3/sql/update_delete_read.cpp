#include <iostream>
#include <sqlite3.h>

using namespace std;

/* Callback function for SELECT */
int callback(void* data, int argc, char** argv, char** colName) {
    for (int i = 0; i < argc; i++) {
        cout << colName[i] << ": "
             << (argv[i] ? argv[i] : "NULL") << "  ";
    }
    cout << endl;
    return 0;
}

int main() {
    sqlite3* db;
    char* errMsg = 0;
    int rc;

    rc = sqlite3_open("student.db", &db);
    if (rc) {
        cout << "Cannot open database\n";
        return 1;
    }

    cout << "Database opened successfully\n";

    const char* createTable =
        "CREATE TABLE IF NOT EXISTS student ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT, "
        "age INTEGER);";

    rc = sqlite3_exec(db, createTable, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Table creation error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Table created successfully\n";
    }

    /* INSERT (CREATE RECORD) */
    const char* insertData =
        "INSERT INTO student VALUES (1, 'Sahil', 21);";

    rc = sqlite3_exec(db, insertData, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Insert error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Record inserted successfully\n";
    }

    /* READ (SELECT RECORDS) */
    const char* selectData =
        "SELECT * FROM student;";

    cout << "\nStudent Records:\n";
    rc = sqlite3_exec(db, selectData, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Select error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    /*UPDATE */
    const char* updateData =
        "UPDATE student SET age = 22 WHERE id = 1;";

    rc = sqlite3_exec(db, updateData, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Update error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Record updated successfully\n";
    }

     cout << "\nStudent Records:\n";
    rc = sqlite3_exec(db, selectData, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Select error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    /* DELETE */
    const char* deleteData =
        "DELETE FROM student WHERE id = 1;";

    rc = sqlite3_exec(db, deleteData, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Delete error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Record deleted successfully\n";
    }

    cout << "\nStudent Records:\n";
    rc = sqlite3_exec(db, selectData, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Select error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }

    /* Close Database */
    sqlite3_close(db);
    cout << "Database closed\n";

    return 0;
}