// Kids With the Greatest Number of Candies — LC 1431
// True if candies[i] + extraCandies >= global max.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<bool> kidsWithCandies(const std::vector<int>& candies, int extraCandies) {
    const int mx = *std::max_element(candies.begin(), candies.end());
    std::vector<bool> ans;
    ans.reserve(candies.size());
    for (int c : candies)
        ans.push_back(c + extraCandies >= mx);
    return ans;
}

int main() {
    auto ans = kidsWithCandies({2, 3, 5, 1, 3}, 3);
    for (bool b : ans)
        std::cout << std::boolalpha << b << " ";
    std::cout << "\n"; // expected true true true false true
    return 0;
}
