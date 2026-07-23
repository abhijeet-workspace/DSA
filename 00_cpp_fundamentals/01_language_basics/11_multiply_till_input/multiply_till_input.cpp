// Multiply Till Input — C++ basics
// Read N integers and print their running product.
#include <iostream>
#include <vector>

void multiplyOfNumber(int number) {
    if (number <= 0) { // empty product convention
        std::cout << "Total :- 1\n";
        return;
    }

    std::vector<long long> values(static_cast<std::size_t>(number)); // store inputs
    long long total = 1; // running product
    for (int i = 0; i < number; ++i) {
        std::cout << "Enter number " << i + 1 << " :- ";
        std::cin >> values[static_cast<std::size_t>(i)]; // read next factor
        total *= values[static_cast<std::size_t>(i)]; // accumulate product
    }
    std::cout << "Total :- " << total << '\n';
}

int main() {
    int number = 0;
    std::cout << "Enter how many numbers you want to multiply :- ";
    std::cin >> number; // count of factors
    multiplyOfNumber(number);
    return 0;
}
