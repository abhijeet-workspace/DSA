// Encapsulation Basics — OOP pillar 1
// Hide BankAccount fields; mutate only via validated public methods.
#include <iostream>
#include <stdexcept>
#include <string>

class BankAccount {
private:
    std::string owner; // account holder
    double balance; // current funds
    std::string accountNumber; // account id

public:
    BankAccount(std::string ownerName, double initialBalance, std::string accNumber) {
        owner = ownerName; // set owner
        accountNumber = accNumber; // set id
        if (initialBalance >= 0) { // validate initial funds
            balance = initialBalance;
        } else {
            balance = 0;
            throw std::invalid_argument("Initial balance cannot be negative!");
        }
    }

    double getBalance() const { // read-only balance
        return balance;
    }

    std::string getOwner() const { // read-only owner
        return owner;
    }

    void setOwner(std::string newOwnerName) { // validated rename
        if (!newOwnerName.empty()) {
            owner = newOwnerName;
        } else {
            std::cout << "Error: Owner name cannot be empty!" << std::endl;
        }
    }

    void deposit(double amount) { // add funds if positive
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited $" << amount
                      << ". New Balance: $" << balance << std::endl;
        } else {
            std::cout << "Error: Deposit amount must be positive!" << std::endl;
        }
    }

    void withdraw(double amount) { // remove funds if affordable
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive!" << std::endl;
            return;
        }
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Successfully withdrew $" << amount
                      << ". Remaining Balance: $" << balance << std::endl;
        } else {
            std::cout << "Error: Insufficient funds! Current Balance: $"
                      << balance << std::endl;
        }
    }
};

int main() {
    std::cout << "=== OOP Pillar 1: Encapsulation ===" << std::endl;
    try {
        BankAccount account("Rahul Sharma", 1000.0, "ACC-2026-991"); // construct
        std::cout << "Account Owner: " << account.getOwner() << std::endl;
        std::cout << "Initial Balance: $" << account.getBalance() << std::endl;

        account.deposit(250.0); // valid deposit
        account.withdraw(500.0); // valid withdraw

        std::cout << "\n--- Testing Data Validation & Protection ---" << std::endl;
        account.deposit(-50); // rejected
        account.withdraw(2000.0); // rejected
        account.setOwner(""); // rejected
        account.setOwner("Rahul S. Sharma"); // accepted
        std::cout << "Updated Account Owner: " << account.getOwner() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
