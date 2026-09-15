// Power of Three — LC 326 (recursive)
#include <iostream>

bool isPowerOfThree(int n) {
    if (n <= 0)
        return false;
    if (n == 1)
        return true;
    if (n % 3 != 0)
        return false;
    return isPowerOfThree(n / 3);
}

int main() {
    std::cout << std::boolalpha << isPowerOfThree(27) << " (expected true)\n"
              << isPowerOfThree(0) << " (expected false)\n"
              << isPowerOfThree(9) << " (expected true)\n";
    return 0;
}
