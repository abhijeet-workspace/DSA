// Q3 Sum Two Numbers — basic practice
// Read two ints and print their sum.
#include <iostream>

int main() {
    int num1 = 0;
    int num2 = 0;
    int sum = 0;

    std::cout << "Enter First numbers: ";
    std::cin >> num1; // first addend
    std::cout << "Enter Second numbers: ";
    std::cin >> num2; // second addend

    sum = num1 + num2; // compute sum
    std::cout << "Sum of " << num1 << " and " << num2 << " is: " << sum << std::endl;
    return 0;
}
