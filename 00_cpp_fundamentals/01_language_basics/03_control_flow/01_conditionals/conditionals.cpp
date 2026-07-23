// Conditionals — C++ basics
// Demo if/else ladders, nested if, switch fall-through, ternary, short-circuit.
#include <iostream>
#include <string>

void demonstrateIfElse(int score);
void demonstrateNestedIf(int age, bool isCitizen);
void demonstrateSwitchCase(int month);
void demonstrateTernaryAndShortCircuit(int num, int divisor);

int main() {
    std::cout << "=== C++ Conditionals Demonstration ===\n\n";

    std::cout << "--- 1. If-Else / Ladder ---\n";
    demonstrateIfElse(85);
    demonstrateIfElse(45);
    std::cout << "\n";

    std::cout << "--- 2. Nested If ---\n";
    demonstrateNestedIf(20, true);
    demonstrateNestedIf(16, true);
    demonstrateNestedIf(25, false);
    std::cout << "\n";

    std::cout << "--- 3. Switch Case ---\n";
    demonstrateSwitchCase(2);
    demonstrateSwitchCase(4);
    demonstrateSwitchCase(12);
    demonstrateSwitchCase(15);
    std::cout << "\n";

    std::cout << "--- 4. Ternary Operator & Short-Circuiting ---\n";
    demonstrateTernaryAndShortCircuit(10, 2);
    demonstrateTernaryAndShortCircuit(10, 0); // divisor 0: short-circuit safe
    std::cout << "\n";
    return 0;
}

void demonstrateIfElse(int score) {
    std::cout << "Score: " << score << " -> ";
    if (score >= 90) {
        std::cout << "Grade: A\n";
    } else if (score >= 80) {
        std::cout << "Grade: B\n";
    } else if (score >= 70) {
        std::cout << "Grade: C\n";
    } else if (score >= 50) {
        std::cout << "Grade: D\n";
    } else {
        std::cout << "Grade: F (Fail)\n";
    }
}

void demonstrateNestedIf(int age, bool isCitizen) {
    std::cout << "Age: " << age << ", Citizen: " << (isCitizen ? "Yes" : "No")
              << " -> ";
    if (age >= 18) {
        if (isCitizen) {
            std::cout << "Eligible to vote!\n";
        } else {
            std::cout << "Not eligible (Must be a citizen).\n";
        }
    } else {
        std::cout << "Not eligible (Must be 18 or older).\n";
    }
}

void demonstrateSwitchCase(int month) {
    std::cout << "Month: " << month << " -> ";
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            std::cout << "31 days\n"; // intentional fall-through group
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            std::cout << "30 days\n";
            break;
        case 2:
            std::cout << "28 or 29 days (Leap Year dependent)\n";
            break;
        default:
            std::cout << "Invalid month number!\n";
            break;
    }
}

void demonstrateTernaryAndShortCircuit(int num, int divisor) {
    std::string parity = (num % 2 == 0) ? "Even" : "Odd"; // ternary select
    std::cout << "Number " << num << " is " << parity << ".\n";

    // left false => right side of && is not evaluated (avoids % 0)
    bool isDivisible = (divisor != 0) && (num % divisor == 0);
    std::cout << "Is " << num << " divisible by " << divisor << "? ";
    if (isDivisible) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No (or invalid divisor)\n";
    }
}
