// team members:
// Mohd Anas - 202352322
// Nitin Kumar - 202352323


#include <iostream>
#include <string>
// #include "uuid_v4"

using namespace std;

class Account {
    // protected: is similar to private, but protected members can be accessed by child classes
    protected:
    string acc_no;
    public:
    // constructor :a special member function that is called when an object is created and to its name should be the same as the class name
    Account(string acc_no) {
        acc_no = acc_no;
    }
    string toString() {
        return acc_no;
    }
};

// Inheritance: A class can be derived from more than one class or interface, which means that it can inherit data and functions from multiple base classes or interfaces.
class BankAccount : public Account {
    private:
    class BalanceInfo {
        // private: members are accessible only within the same class
        private:
        double balance;
        double interestRate;
        // public: members are accessible from outside the class
        public:
        // created a constructor that initializes the balance and interestRate
        BalanceInfo(double b, double i) {
            balance = b;
            interestRate = i;
        }
        double getBalance() const {
            return balance;
        }
        void setBalance(double b) {
            balance = b; 
        }
        double getInterestRate() {
            return interestRate; 
        }
        void deposit(double amount) {
            balance += amount;
        }
        void deposit(double amount1, double amount2) {
            balance += amount1 + amount2;
        }
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
            } else {
                cout << "Insufficient balance" << endl;
            }
        }
    };
    // created the object of the BalanceInfo class
    BalanceInfo balanceInfo;

    public:
    // created a constructor that initializes the account number, balance and interestRate using the constructor of the Account class and the constructor of the BalanceInfo class
    BankAccount(string acc_no, double b, double i) : Account(acc_no), balanceInfo(b, i) {
        cout << "Accoutnt Number: " << acc_no << endl;
    }
    // here we are using the copy constructor to create a new object of the BankAccount class with the same values as the object passed as an argument
    // and we used Account class constructor to initialize the acc_no and BalanceInfo class constructor
    BankAccount(BankAccount& t) : Account(t.acc_no), balanceInfo(t.balanceInfo.getBalance(), t.balanceInfo.getInterestRate()) {
        // deep copy
        balanceInfo.setBalance(t.balanceInfo.getBalance());
    }
    void display() {
        cout << acc_no << "\t" << balanceInfo.getBalance() << "\t" << balanceInfo.getInterestRate() << endl;
    }
    void deposit(double amount) {
        balanceInfo.deposit(amount);
    }
    void deposit(double amount1, double amount2) {
        balanceInfo.deposit(amount1, amount2);
    }
    void withdraw(double amount) {
        balanceInfo.withdraw(amount);
    }
    double getBalance() {
        return balanceInfo.getBalance();
    }

};

int main() {
    Account a("A123456");
    BankAccount b("B987654", 1000, 2.5);
    b.display();
    b.deposit(200);
    b.display();
    b.deposit(50, 100);
    b.display();
    // cout << b.acc_no << endl; // acc_no is private and cannot be accessed from outside the class
    // cout << b.balance << endl; // balance is private and cannot be accessed from outside the class
    cout << b.getBalance() << endl;

    // shallow copy : in this case, c is pointing to the same memory location as b
    BankAccount c = b;
    cout<< "shalow copy" << endl;
    c.display();
    b.deposit(500);
    b.display();
    c.display();
    // deep copy : in this case, d is pointing to a different memory location than b
    BankAccount d(b);
    cout<< "deep copy" << endl;
    d.display();
    b.deposit(1000);
    b.display();
    c.display();
    d.display();

    return 0;
}