// Squares of a Sorted Array — LC 977
// Merge from largest |value|: fill result from the right with two pointers.
#include <iostream>
#include <vector>

std::vector<int> sortedSquares(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> result(static_cast<size_t>(n));
    int L = 0;
    int R = n - 1;
    int write = n - 1;
    while (L <= R) {
        long leftSq =
            static_cast<long>(nums[static_cast<size_t>(L)]) * nums[static_cast<size_t>(L)];
        long rightSq =
            static_cast<long>(nums[static_cast<size_t>(R)]) * nums[static_cast<size_t>(R)];
        if (leftSq > rightSq) {
            result[static_cast<size_t>(write--)] = static_cast<int>(leftSq);
            ++L;
        } else {
            result[static_cast<size_t>(write--)] = static_cast<int>(rightSq);
            --R;
        }
    }
    return result;
}

int main() {
    auto a = sortedSquares({-4, -1, 0, 3, 10});
    std::cout << "[";
    for (size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << (i + 1 < a.size() ? "," : "");
    std::cout << "] (expected [0,1,9,16,100])\n";

    auto b = sortedSquares({-7, -3, 2, 3, 11});
    std::cout << "[";
    for (size_t i = 0; i < b.size(); ++i)
        std::cout << b[i] << (i + 1 < b.size() ? "," : "");
    std::cout << "] (expected [4,9,9,49,121])\n";
    return 0;
}
