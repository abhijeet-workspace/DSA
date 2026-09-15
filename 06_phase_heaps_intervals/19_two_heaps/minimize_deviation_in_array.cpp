// Minimize Deviation in Array — https://leetcode.com/problems/minimize-deviation-in-array/
// Evens can /2; odds can *2 once. Normalize to even upper bounds; set/max-heap + track min.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int minimumDeviation(std::vector<int>& nums) {
    std::set<int> s;
    for (int x : nums) {
        if (x % 2) {
            x *= 2; // make odd numbers even (only upward move used once)
        }
        s.insert(x);
    }
    int best = *s.rbegin() - *s.begin();
    while (*s.rbegin() % 2 == 0) {
        const int mx = *s.rbegin();
        s.erase(std::prev(s.end()));
        s.insert(mx / 2);
        best = std::min(best, *s.rbegin() - *s.begin());
    }
    return best;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::cout << minimumDeviation(a) << " (expected 1)\n";
    std::vector<int> b = {4, 1, 5, 20, 3};
    std::cout << minimumDeviation(b) << " (expected 3)\n";
    return 0;
}
