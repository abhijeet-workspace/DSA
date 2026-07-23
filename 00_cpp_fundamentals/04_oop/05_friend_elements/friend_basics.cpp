// Friend Elements — friend function, friend member, friend class
// Selected outsiders may read Customer private fields for audit/eligibility.
#include <iostream>
#include <string>

class Customer;

class BankInspector {
public:
    void auditAccount(const Customer& c); // friend member (declared later)
};

class Customer {
private:
    std::string name;
    double creditScore;
    double debt;

public:
    Customer(std::string n, double score, double d)
        : name(n), creditScore(score), debt(d) {}

    friend void checkLoanEligibility(const Customer& c); // friend free function
    friend void BankInspector::auditAccount(const Customer& c); // friend member
    friend class CreditBureau; // entire friend class
};

void checkLoanEligibility(const Customer& c) {
    std::cout << "[Friend Function] Evaluating eligibility for " << c.name << ":"
              << std::endl;
    if (c.creditScore > 700 && c.debt < 50000) {
        std::cout << "  Status: ELIGIBLE for a credit line." << std::endl;
    } else {
        std::cout << "  Status: DENIED. High debt or low credit score." << std::endl;
    }
}

void BankInspector::auditAccount(const Customer& c) {
    std::cout << "[Friend Class Method] Audit report for " << c.name << ":"
              << std::endl;
    std::cout << "  Inspect score: " << c.creditScore << " | Unpaid debt: $"
              << c.debt << std::endl;
}

class CreditBureau {
public:
    void printCustomerProfile(const Customer& c) {
        std::cout << "[Friend Class Bureau] Profile Summary:" << std::endl;
        std::cout << "  Name: " << c.name << std::endl;
        std::cout << "  Score: " << c.creditScore << std::endl;
        std::cout << "  Debt: $" << c.debt << std::endl;
    }
};

int main() {
    std::cout << "=== OOP: Friend Functions and Friend Classes ===" << std::endl;

    Customer cust("Amit Verma", 750, 15000.00);
    checkLoanEligibility(cust);
    std::cout << std::endl;

    BankInspector inspector;
    inspector.auditAccount(cust);
    std::cout << std::endl;

    CreditBureau bureau;
    bureau.printCustomerProfile(cust);
    return 0;
}
