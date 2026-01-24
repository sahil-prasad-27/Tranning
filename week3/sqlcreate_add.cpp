#include<iostream>
#include <sqlite3.h>

using namespace std;

int main(){
    sqlite3* db;
    char* errMsg = 0;

    sqlite3_open("student.db",&db);

    const char* createTable = 
        "CREATE TABLE IF NOT EXISTS student ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT, "
        "age INTEGER);";
    sqlite3_exec(db, createTable, 0, 0, &errMsg);

    const char* insertData =
        "INSERT INTO student VALUES (1,'Sahil', 21);";
    sqlite3_exec(db, insertData,0,0,&errMsg);
    cout << "record inserted succ" <<endl;
    sqlite3_close(db);
    return 0;
}