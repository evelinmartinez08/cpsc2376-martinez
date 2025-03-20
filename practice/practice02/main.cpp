#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

double readBalanceFromFile();
void writeBalanceToFile(double balance);
void checkBalance(double balance);
void deposit(double &balance);
void withdraw(double &balance);
int getValidMenuChoice();

int main() {
    double balance = readBalanceFromFile();

    cout << "Welcome to Your Bank Account!" << endl;
    if (balance == 100.00) {
        cout << "Initializing account with $100.00..." << endl;
    } else {
        cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice = getValidMenuChoice();

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
                cout << "Exiting... Thank you for using our service.\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
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
    file.close();

    if (!file || balance < 0) {
        return 100.00;
    }

    return balance;
}

void writeBalanceToFile(double balance) {
    ofstream file("account_balance.txt");

    if (!file) {
        cerr << "Error: Unable to open file to save the balance.\n";
        exit(1);
    }

    file << fixed << setprecision(2) << balance;
    file.close();
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}

void deposit(double &balance) {
    double amount;
    cout << "Enter deposit amount: ";

    while (!(cin >> amount) || amount <= 0) {
        cout << "Error: Deposit amount must be a positive number. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    balance += amount;
    writeBalanceToFile(balance);
    cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
}

void withdraw(double &balance) {
    double amount;
    cout << "Enter withdrawal amount: ";

    while (!(cin >> amount) || amount <= 0) {
        cout << "Error: Withdrawal amount must be a positive number. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (amount > balance) {
        cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << endl;
        return;
    }

    balance -= amount;
    writeBalanceToFile(balance);
    cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
}

int getValidMenuChoice() {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return choice;
}
