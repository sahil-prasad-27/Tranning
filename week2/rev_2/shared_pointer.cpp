#include <iostream>
#include <memory>
using namespace std;

class Document {
public:
    Document() { cout << "Document opened\n"; }
    ~Document() { cout << "Document closed\n"; }

    void read() {
        cout << "Reading document\n";
    }
};

int main() {
    shared_ptr<Document> emp1 = make_shared<Document>();
    cout << emp1.use_count() << endl; 

    shared_ptr<Document> emp2 = emp1;
    shared_ptr<Document> emp3 = emp1;

    cout << emp1.use_count() << endl; 

    emp2->read();
}
