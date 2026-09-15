// LC263 Ugly Number
#include <iostream>

bool isUgly(int n) {
    if (n <= 0)
        return false;
    for (int p : {2, 3, 5}) {
        while (n % p == 0)
            n /= p;
    }
    return n == 1;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "isUgly(6)=" << isUgly(6) << " (expected true)\n";
    std::cout << "isUgly(14)=" << isUgly(14) << " (expected false)\n";
    std::cout << "isUgly(1)=" << isUgly(1) << " (expected true)\n";
    return 0;
}
