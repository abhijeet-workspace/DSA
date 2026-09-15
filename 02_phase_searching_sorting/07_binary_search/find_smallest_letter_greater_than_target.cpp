// Find Smallest Letter Greater Than Target —
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/ Circular sorted letters;
// return smallest letter strictly greater than target.
#include <iostream>
#include <vector>

char nextGreatestLetter(const std::vector<char>& letters, char target) {
    int lo = 0;
    int hi = static_cast<int>(letters.size()); // exclusive upper bound
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        if (letters[static_cast<size_t>(mid)] > target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (lo == static_cast<int>(letters.size())) {
        return letters[0]; // wrap
    }
    return letters[static_cast<size_t>(lo)];
}

int main() {
    std::cout << nextGreatestLetter({'c', 'f', 'j'}, 'a') << " (expected c)\n"
              << nextGreatestLetter({'c', 'f', 'j'}, 'c') << " (expected f)\n"
              << nextGreatestLetter({'x', 'x', 'y', 'y'}, 'z') << " (expected x)\n";
    return 0;
}
