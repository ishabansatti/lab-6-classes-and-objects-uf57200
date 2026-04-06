
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    int pin;

public:
    BankAccount(string accNo, double initialBalance, int accountPin)
        : accountNumber(accNo), balance(initialBalance), pin(accountPin) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount, int enteredPin) {
        if (enteredPin != pin) {
            cout << "Incorrect pin." << endl;
            return;
        }

        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
            return;
        }

        if (amount > balance) {
            cout << "Insufficient balance." << endl;
            return;
        }

        balance -= amount;
        cout << "Withdrawn: " << amount << endl;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account("PK12345", 5000, 1234);

    cout << "Initial Balance: " << account.getBalance() << endl;
    account.deposit(1500);
    cout << "Balance: " << account.getBalance() << endl;
    account.withdraw(2000, 1111);
    account.withdraw(7000, 1234);
    account.withdraw(2000, 1234);
    cout << "Final Balance: " << account.getBalance() << endl;

    return 0;
}
