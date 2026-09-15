// XOR Operation in an Array — LC 1486
// nums[i] = start + 2*i; return bitwise XOR of all nums[i].
#include <iostream>

int xorOperation(int n, int start) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans ^= (start + 2 * i);
    }
    return ans;
}

int main() {
    std::cout << xorOperation(5, 0) << " (expected 8)\n";
    std::cout << xorOperation(4, 3) << " (expected 8)\n";
    return 0;
}
