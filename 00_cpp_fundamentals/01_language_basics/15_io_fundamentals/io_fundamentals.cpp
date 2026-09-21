// I/O Fundamentals — C++ basics
// Demo cout/cin, getline, and why mixing >> with getline needs care.
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::cout << "=== Formatted output ===\n";
    int year = 2026;
    double pi = 3.14159;
    std::cout << "year=" << year << " pi=" << pi << '\n';

    std::cout << "\n=== Read an int with cin >> ===\n";
    std::cout << "Enter an integer: ";
    int n = 0;
    if (!(std::cin >> n)) {
        std::cout << "Failed to read int\n";
        return 1;
    }
    std::cout << "You entered: " << n << '\n';

    // leftover newline from >> would make the next getline empty without ignore
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n=== Read a full line with getline ===\n";
    std::cout << "Enter a full line: ";
    std::string line;
    std::getline(std::cin, line);
    std::cout << "Line: \"" << line << "\" (size=" << line.size() << ")\n";

    std::cout << "\n=== Stream state check ===\n";
    std::cout << "cin goodbit=" << std::cin.good() << " failbit=" << std::cin.fail() << '\n';

    return 0;
}
