// Operators — C++ basics
// Demo arithmetic, relational, logical, assignment, increment, and precedence.
#include <iostream>

int main() {
    int a = 10;
    int b = 3;

    std::cout << "=== Arithmetic ===\n";
    std::cout << "a+b=" << (a + b) << " a-b=" << (a - b) << " a*b=" << (a * b)
              << " a/b=" << (a / b) << " a%b=" << (a % b) << '\n'; // int division truncates

    std::cout << "=== Relational / Logical ===\n";
    std::cout << "a>b=" << (a > b) << " a==b=" << (a == b) << " !(a<b)=" << !(a < b) << '\n';
    std::cout << "(a>5 && b<5)=" << (a > 5 && b < 5) << " (a<0 || b==3)=" << (a < 0 || b == 3)
              << '\n';

    std::cout << "=== Assignment / Compound ===\n";
    int x = 5;
    x += 2; // x = x + 2
    x *= 3; // x = x * 3
    std::cout << "x after +=2 then *=3: " << x << '\n'; // 21

    std::cout << "=== Increment / Decrement ===\n";
    int n = 5;
    std::cout << "n++ prints " << n++ << " then n=" << n << '\n'; // post: print then bump
    std::cout << "++n prints " << ++n << " then n=" << n << '\n'; // pre: bump then print

    std::cout << "=== Precedence ===\n";
    std::cout << "2+3*4=" << (2 + 3 * 4) << " (2+3)*4=" << ((2 + 3) * 4) << '\n';

    return 0;
}
