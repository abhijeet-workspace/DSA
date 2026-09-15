// Find Numbers with Even Number of Digits — LC 1295
// Count how many nums[i] have an even digit count.
#include <iostream>
#include <vector>

static int digitCount(int x) {
    int d = 0;
    do {
        ++d;
        x /= 10;
    } while (x > 0);
    return d;
}

int findNumbers(const std::vector<int>& nums) {
    int ans = 0;
    for (int x : nums) {
        if (digitCount(x) % 2 == 0)
            ++ans;
    }
    return ans;
}

int main() {
    std::cout << findNumbers({12, 345, 2, 6, 7896}) << " (expected 2)\n";
    return 0;
}
