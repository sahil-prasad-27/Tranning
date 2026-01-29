#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>

void executeQuery(sqlite3* db, const std::string& sql, const std::string& joinType) {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << "\n";
        return;
    }

    std::cout << "\n " << joinType << "\n";

    int colCount = sqlite3_column_count(stmt);
    for (int i = 0; i < colCount; i++) {
        std::cout << sqlite3_column_name(stmt, i) << "\t";
    }
    std::cout << "\n";

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        for (int i = 0; i < colCount; i++) {
            const char* val = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            std::cout << (val ? val : "NULL") << "\t";
        }
        std::cout << "\n";
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3* db;
    if (sqlite3_open(":memory:", &db) != SQLITE_OK) {
        std::cerr << "Cannot open database\n";
        return 1;
    }
    const char* createTables = R"(
        CREATE TABLE Students (StudentID INTEGER PRIMARY KEY, Name TEXT, Age INTEGER);
        CREATE TABLE Courses (CourseID INTEGER PRIMARY KEY, StudentID INTEGER, CourseName TEXT);

        INSERT INTO Students VALUES (1, 'Alice', 20), (2, 'Bob', 21), (3, 'Carol', 22);
        INSERT INTO Courses VALUES (101, 1, 'Math'), (102, 1, 'English'), (103, 2, 'Physics'), (104, 4, 'Chemistry');
    )";

    if (sqlite3_exec(db, createTables, 0, 0, 0) != SQLITE_OK) {
        std::cerr << "Failed to create tables: " << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        return 1;
    }

    // INNER JOIN
    executeQuery(db,
        "SELECT Students.Name, Courses.CourseName "
        "FROM Students "
        "INNER JOIN Courses ON Students.StudentID = Courses.StudentID;",
        "INNER JOIN");

    // LEFT JOIN
    executeQuery(db,
        "SELECT Students.Name, Courses.CourseName "
        "FROM Students "
        "LEFT JOIN Courses ON Students.StudentID = Courses.StudentID;",
        "LEFT JOIN");

    // RIGHT JOIN (simulated using LEFT JOIN by swapping tables)
    executeQuery(db,
        "SELECT Students.Name, Courses.CourseName "
        "FROM Courses "
        "LEFT JOIN Students ON Students.StudentID = Courses.StudentID;",
        "RIGHT JOIN (simulated)");

    // FULL OUTER JOIN (simulated using UNION)
    executeQuery(db,
        "SELECT Students.Name, Courses.CourseName "
        "FROM Students LEFT JOIN Courses ON Students.StudentID = Courses.StudentID "
        "UNION "
        "SELECT Students.Name, Courses.CourseName "
        "FROM Courses LEFT JOIN Students ON Students.StudentID = Courses.StudentID;",
        "FULL OUTER JOIN (simulated)");

    // CROSS JOIN
    executeQuery(db,
        "SELECT Students.Name, Courses.CourseName "
        "FROM Students CROSS JOIN Courses;",
        "CROSS JOIN");

    // SELF JOIN
    executeQuery(db,
        "SELECT A.Name, B.Name, A.Age, B.Age "
        "FROM Students A "
        "INNER JOIN Students B ON A.Age > B.Age;",
        "SELF JOIN");

    sqlite3_close(db);
    return 0;
}
