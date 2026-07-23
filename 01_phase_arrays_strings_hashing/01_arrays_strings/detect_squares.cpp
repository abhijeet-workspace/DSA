// Detect Squares — https://leetcode.com/problems/detect-squares/
// add(point); count axis-aligned squares with point as one corner.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

class DetectSquares {
    std::unordered_map<long long, int> cnt; // packed (x,y) -> frequency
    static long long key(int x, int y) {
        return (static_cast<long long>(x) << 32) ^ static_cast<unsigned>(y);
    }
public:
    void add(std::vector<int> p) {
        ++cnt[key(p[0], p[1])]; // insert / bump count
    }
    int count(std::vector<int> p) {
        const int x = p[0], y = p[1];
        int ans = 0;
        for (const auto& [k, c] : cnt) {
            const int px = static_cast<int>(k >> 32);
            const int py = static_cast<int>(k & 0xffffffffLL);
            if (px == x || py == y) continue; // need diagonal partner
            if (std::abs(px - x) != std::abs(py - y)) continue; // square diagonal
            ans += c * cnt[key(px, y)] * cnt[key(x, py)]; // other two corners
        }
        return ans;
    }
};

int main() {
    DetectSquares d;
    d.add({3, 10});
    d.add({11, 2});
    d.add({3, 2});
    std::cout << d.count({11, 10}) << " (expected 1)\n";
    return 0;
}
