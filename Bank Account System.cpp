
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string name;
    long accountNumber;
    string accountType;
    double balance;
public:
    Account() {}
    Account(string n, long a, string t, double b) {
        name = n;
        accountNumber = a;
        accountType = t;
        balance = b;
    }
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void display() = 0;
};

class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(string n, long a, string t, double b, double ir) : Account(n, a, t, b) {
        interestRate = ir;
    }
    
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
        }
        else {
            cout << "Insufficient balance" << endl;
        }
    }
    void display() {
    	double interestEarned = balance * (interestRate / 100);
    
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
        cout << "Interest Earned: " << interestEarned << endl;
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;
public:
    CurrentAccount(string n, long a, string t, double b, double ol) : Account(n, a, t, b) {
        overdraftLimit = ol;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (balance + overdraftLimit - amount >= 0) {
            balance -= amount;
        }
        else {
            cout << "Insufficient balance" << endl;
        }
    }
    void display() {
    	
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    int choice;
    string name, accountType;
    long accountNumber;
    double balance, amount, interestRate, overdraftLimit;
    Account* account;

	cout<<"-----Welcome to Triple Canopy Bank-----"<<endl;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter account type (Savings/Current): ";
    cin >> accountType;
    cout << "Enter balance: ";
    cin >> balance;

    if (accountType == "Savings") {
        cout << "Enter interest rate: ";
        cin >> interestRate;
        account = new SavingsAccount(name, accountNumber, accountType, balance, interestRate);
    }
    else if (accountType == "Current") {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
        account = new CurrentAccount(name, accountNumber, accountType, balance, overdraftLimit);
    }
    else {
        cout << "Invalid account type" << endl;
        return 0;
    }

    do {
        cout << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account->deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account->withdraw(amount);
            break;
        case 3:
        	system("cls");
        	cout <<"------Triple Canopy------"<<endl;
            account->display();
            
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    delete account;
    return 0;
}
