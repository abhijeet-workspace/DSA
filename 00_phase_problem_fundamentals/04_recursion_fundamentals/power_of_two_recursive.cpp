// Power of Two — LC 231 (recursive halving)
#include <iostream>

bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;
    if (n == 1)
        return true;
    if (n % 2 != 0)
        return false;
    return isPowerOfTwo(n / 2);
}

int main() {
    std::cout << std::boolalpha << isPowerOfTwo(1) << " (expected true)\n"
              << isPowerOfTwo(16) << " (expected true)\n"
              << isPowerOfTwo(3) << " (expected false)\n";
    return 0;
}
