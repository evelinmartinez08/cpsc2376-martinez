#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double readBalanceFromFile();
void writeBalanceToFile(double balance);
void checkBalance(double balance);
void deposit(double &balance);
void withdraw(double &balance);

int main() {
    double balance;

    balance = readBalanceFromFile();

    cout << "Welcome to Your Bank Account!" << endl;
    if (balance == 100.00) {
    cout << "Initializing account with $100.00..." << endl;
    } else {
        cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
    }

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

                switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                cout << "Exiting... Thank you for using our service." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
    }
}

return 0;
}

double readBalanceFromFile() {
    ifstream file("account_balance.txt");

    if (!file) {
        return 100.00;
    }

    double balance;
    file >> balance;

    if (!file || balance < 0) {
        return 100.00;
    }

    return balance;
}

void writeBalanceToFile(double balance) {
    ofstream file("account_balance.txt");
    
    if (!file) {
        cerr << "Error: Unable to open file to save the balance." << endl;
        exit(1);
    }

    file << fixed << setprecision(2) << balance;
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}

void deposit(double &balance) {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Error: Deposit amount must be positive." << endl;
        return;
    }

    balance += amount;
    writeBalanceToFile(balance);
    cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
}

void withdraw(double &balance) {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Error: Withdrawal amount must be positive." << endl;
        return;
    }

    if (amount > balance) {
        cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << endl;
        return;
    }

    balance -= amount;
    writeBalanceToFile(balance);
    cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
}
