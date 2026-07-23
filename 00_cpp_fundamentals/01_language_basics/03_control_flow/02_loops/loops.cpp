// Loops — C++ basics
// Demo for/while/do-while, break/continue, and a discouraged goto sample.
#include <iostream>

void demonstrateForLoop();
void demonstrateWhileLoop(int num);
void demonstrateDoWhileLoop();
void demonstrateBreakAndContinue();
void demonstrateGoto();

int main() {
    std::cout << "=== C++ Loops Demonstration ===\n\n";

    std::cout << "--- 1. For Loop: Counting up and down ---\n";
    demonstrateForLoop();
    std::cout << "\n";

    std::cout << "--- 2. While Loop: Sum of digits ---\n";
    demonstrateWhileLoop(12345);
    demonstrateWhileLoop(908);
    std::cout << "\n";

    std::cout << "--- 3. Do-While Loop: Guaranteed first-run ---\n";
    demonstrateDoWhileLoop();
    std::cout << "\n";

    std::cout << "--- 4. Jump Statements (Break & Continue) ---\n";
    demonstrateBreakAndContinue();
    std::cout << "\n";

    std::cout << "--- 5. Goto Statement ---\n";
    demonstrateGoto();
    std::cout << "\n";
    return 0;
}

void demonstrateForLoop() {
    std::cout << "Counting 1 to 5: ";
    for (int i = 1; i <= 5; i++) { // known iteration count
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Counting down 5 to 1: ";
    for (int i = 5; i >= 1; i--) { // decrementing counter
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void demonstrateWhileLoop(int num) {
    int original = num; // keep for printing
    int sum = 0;
    while (num > 0) { // unknown digit count
        int lastDigit = num % 10; // peel ones place
        sum += lastDigit;
        num = num / 10; // drop last digit
    }
    std::cout << "Sum of digits of " << original << " is " << sum << "\n";
}

void demonstrateDoWhileLoop() {
    int choice = 3; // simulated menu selection (non-blocking)
    std::cout << "Simulating menu choosing (input value " << choice << "):\n";
    int count = 0;
    do { // body runs at least once
        std::cout << "  [1] Try Again\n";
        std::cout << "  [2] View Settings\n";
        std::cout << "  [3] Exit Game\n";
        std::cout << "  Selected option: " << choice << "\n";
        count++;
        if (choice == 3) {
            std::cout << "  Exiting menu successfully.\n";
        }
    } while (choice != 3 && count < 1);
}

void demonstrateBreakAndContinue() {
    std::cout << "Printing odd numbers between 1 and 10 (skipping 5, stopping at 9):\n";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // skip evens
        }
        if (i == 9) {
            std::cout << " [Found 9, breaking!]";
            break; // leave loop early
        }
        if (i == 5) {
            std::cout << "(skip 5) ";
            continue; // skip printing 5
        }
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void demonstrateGoto() {
    int steps = 1;
loop_start: // label
    if (steps > 3) {
        goto loop_end; // jump out
    }
    std::cout << "  Step: " << steps << "\n";
    steps++;
    goto loop_start; // jump back
loop_end:
    std::cout << "  Jumped out of goto block successfully.\n";
}
