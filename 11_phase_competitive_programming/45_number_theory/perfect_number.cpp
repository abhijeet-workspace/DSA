// LC507 Perfect Number
#include <iostream>

bool checkPerfectNumber(int num) {
    if (num <= 1)
        return false;
    long long sum = 1;
    for (int i = 2; 1LL * i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i)
                sum += num / i;
        }
    }
    return sum == num;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "checkPerfectNumber(28)=" << checkPerfectNumber(28) << " (expected true)\n";
    std::cout << "checkPerfectNumber(7)=" << checkPerfectNumber(7) << " (expected false)\n";
    return 0;
}
