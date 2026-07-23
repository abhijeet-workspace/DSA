// Bit Manipulation demos — XOR singles, power-of-two, popcount, add without +
// LC 136 / 137 / 260 patterns and related bit tricks.
#include <iostream>
#include <vector>
#include <utility>

int singleNumberI(const std::vector<int>& nums) {
    int x = 0;
    for (int num : nums) x ^= num; // pairs cancel
    return x;
}

int singleNumberII(const std::vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        int sum = 0;
        for (int num : nums) {
            if ((num >> i) & 1) ++sum;
        }
        if (sum % 3 != 0) result |= (1 << i); // leftover bit of the unique
    }
    return result;
}

std::pair<int, int> singleNumberIII(const std::vector<int>& nums) {
    int xor_sum = 0;
    for (int num : nums) xor_sum ^= num;
    const unsigned diff = static_cast<unsigned>(xor_sum)
                        & -static_cast<unsigned>(xor_sum); // lowbit
    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (static_cast<unsigned>(num) & diff) num1 ^= num;
        else num2 ^= num;
    }
    return {num1, num2};
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // clear lowest set bit
        ++count;
    }
    return count;
}

int addWithoutPlus(int a, int b) {
    while (b != 0) {
        const unsigned carry = static_cast<unsigned>(a & b) << 1;
        a = a ^ b;
        b = static_cast<int>(carry);
    }
    return a;
}

int main() {
    std::cout << "Single Number I {2,2,1} -> " << singleNumberI({2, 2, 1}) << "\n";
    std::cout << "Single Number II {2,2,3,2} -> " << singleNumberII({2, 2, 3, 2}) << "\n";
    auto res = singleNumberIII({1, 2, 1, 3, 2, 5});
    std::cout << "Single Number III -> {" << res.first << ", " << res.second << "}\n";
    std::cout << "Is 16 power of two? " << (isPowerOfTwo(16) ? "YES" : "NO") << "\n";
    std::cout << "Is 18 power of two? " << (isPowerOfTwo(18) ? "YES" : "NO") << "\n";
    std::cout << "Set bits in 15: " << countSetBits(15) << "\n";
    std::cout << "15+27 without +: " << addWithoutPlus(15, 27) << " (Expected: 42)\n";
    return 0;
}
