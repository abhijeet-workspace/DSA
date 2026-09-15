// 4Sum II — LC 454
#include <iostream>
#include <unordered_map>
#include <vector>

int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C,
                 std::vector<int>& D) {
    std::unordered_map<int, int> ab;
    for (int a : A)
        for (int b : B)
            ++ab[a + b];
    int ans = 0;
    for (int c : C)
        for (int d : D) {
            auto it = ab.find(-(c + d));
            if (it != ab.end())
                ans += it->second;
        }
    return ans;
}

int main() {
    std::vector<int> A{1, 2}, B{-2, -1}, C{-1, 2}, D{0, 2};
    std::cout << fourSumCount(A, B, C, D) << " (expected 2)\n";
    return 0;
}
