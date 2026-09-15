// Form Largest Integer With Digits That Add up to Target — https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
#include <iostream>
#include <string>
#include <vector>

std::string largestNumber(std::vector<int>& cost, int target) {
    std::vector<std::string> dp(static_cast<size_t>(target + 1), "#");
    dp[0] = "";
    for (int t = 1; t <= target; ++t) {
        for (int d = 1; d <= 9; ++d) {
            const int c = cost[static_cast<size_t>(d - 1)];
            if (t < c || dp[static_cast<size_t>(t - c)] == "#") continue;
            std::string cand = std::to_string(d) + dp[static_cast<size_t>(t - c)];
            auto& cur = dp[static_cast<size_t>(t)];
            if (cur == "#" || cand.size() > cur.size() || (cand.size() == cur.size() && cand > cur)) {
                cur = cand;
            }
        }
    }
    return dp[static_cast<size_t>(target)] == "#" ? "0" : dp[static_cast<size_t>(target)];
}

int main() {
    std::vector<int> cost{4, 3, 2, 5, 6, 7, 2, 5, 5};
    std::cout << largestNumber(cost, 9) << " (expected 7772)\n";
    return 0;
}
