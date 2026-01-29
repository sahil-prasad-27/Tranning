#include <iostream>
#include <sqlite3.h>

void executeSQL(sqlite3* db, const std::string& sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
    }
}
int main() {
    sqlite3* db;
    sqlite3_open(":memory:", &db);
    executeSQL(db, "CREATE TABLE Students (StudentID INTEGER PRIMARY KEY, Name TEXT, Age INTEGER);");
    executeSQL(db, "CREATE TABLE Courses (CourseID INTEGER PRIMARY KEY, StudentID INTEGER, CourseName TEXT);");
    executeSQL(db, "INSERT INTO Students VALUES (1, 'Alice', 20), (2, 'Bob', 21), (3, 'Carol', 22);");
    executeSQL(db, "INSERT INTO Courses VALUES (101, 1, 'Math'), (102, 2, 'Physics');");
    // Insert using data from another table
    executeSQL(db, "INSERT INTO Courses (StudentID, CourseName) "
                   "SELECT StudentID, 'Biology' FROM Students WHERE Age > 21;");
    // Update using another table
    executeSQL(db, "UPDATE Students SET Age = 20 WHERE StudentID IN "
                   "(SELECT StudentID FROM Courses WHERE CourseName = 'Physics');");
    // Delete using another table
    executeSQL(db, "DELETE FROM Students WHERE StudentID NOT IN (SELECT StudentID FROM Courses);");

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM Students;", -1, &stmt, 0);
    std::cout << "\nFinal Students table:\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << sqlite3_column_int(stmt, 0) << "\t"
                  << sqlite3_column_text(stmt, 1) << "\t"
                  << sqlite3_column_int(stmt, 2) << "\n";
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}
