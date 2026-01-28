#include<iostream>
#include<thread>
#include<vector>
#include<map>
#include <mutex>
#include <string>

using namespace std;

map<string, string> attendance;
mutex mtx;

void markAttendance(const vector<string>& students, const string& status) {
    for(const auto& student : students) {
        try {
            lock_guard<mutex> lock(mtx);

            if (attendance.find(student) == attendance.end()) {
                throw runtime_error("error: Student " + student + "not found");
            }

            attendance[student] = status;
            cout << "Marked " << student << "as" << status << "by thread" << this_thread::get_id() << endl;

        }catch(const exception& e ){
            cerr << "Exception caught in thread" << this_thread::get_id() << ": " << e.what() << endl;

        }
    }
}

int main(){
    vector <string> students = {"Alice", "Bob", "Charlie", "David", "Eva"};
    for (const auto& student : students){
        attendance[student] =  "Absent";
    }

    vector<string> group1 = {"Alice", "Bob" , "Charlie"};
    vector <string> group2 = {"David", "Eva", "Frank"};

    thread t1(markAttendance, group1, "present");
    thread t2(markAttendance, group2, "present");

    t1.join();
    t2.join();

    cout << "\nFinal Attendance:\n";
    for(const auto& entry : attendance) {
        cout << entry.first << "-> " << entry.second << endl;
    }

    return 0;
}