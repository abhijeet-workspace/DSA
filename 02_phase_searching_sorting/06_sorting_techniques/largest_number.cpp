// Largest Number — LC 179
// Arrange non-negative integers to form the largest concatenated number.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string largestNumber(std::vector<int>& nums) {
    std::vector<std::string> parts;
    parts.reserve(nums.size());
    for (int x : nums) {
        parts.push_back(std::to_string(x));
    }
    std::sort(parts.begin(), parts.end(), [](const std::string& a, const std::string& b) {
        return a + b > b + a; // custom order: which prefix yields larger concat
    });
    if (parts.empty() || parts[0] == "0") {
        return "0"; // all zeros collapse to single 0
    }
    std::string ans;
    for (const auto& p : parts) {
        ans += p;
    }
    return ans;
}

int main() {
    std::vector<int> a = {10, 2};
    std::vector<int> b = {3, 30, 34, 5, 9};
    std::cout << largestNumber(a) << " (expected 210)\n";
    std::cout << largestNumber(b) << " (expected 9534330)\n";
    return 0;
}
