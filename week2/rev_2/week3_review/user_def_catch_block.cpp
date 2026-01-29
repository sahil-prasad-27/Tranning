#include <iostream>
using namespace std;
// User-defined exception classes
class WrongPIN {};
class InsufficientBalance {};
class DailyLimitExceeded {};

void withdraw(int correctPin, int enteredPin, int balance, int amount) {
    if (enteredPin != correctPin)
        throw WrongPIN();

    if (amount > balance)
        throw InsufficientBalance();
    if (amount > 20000)
        throw DailyLimitExceeded();
    cout << "Please collect your cash." << endl;
}
int main() {
    int correctPin = 1234;
    int enteredPin = 1234;
    int balance = 9000;
    int amount = 7000;
    try {
        withdraw(correctPin, enteredPin, balance, amount);
    }
    catch (const WrongPIN&) {
        cout << "Error: Wrong PIN entered!" << endl;
    }
    catch (const InsufficientBalance&) {
        cout << "Error: Insufficient balance in your account!" << endl;
    }
    catch (const DailyLimitExceeded&) {
        cout << "Error: Daily withdrawal limit exceeded!" << endl;
    }
    return 0;
}
