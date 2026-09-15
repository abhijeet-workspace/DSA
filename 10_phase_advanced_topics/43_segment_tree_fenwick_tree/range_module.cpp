// Range Module — https://leetcode.com/problems/range-module/
// Disjoint intervals in std::map; half-open [left, right).
#include <iostream>
#include <map>

class RangeModule {
    std::map<int, int> mp; // start -> end

  public:
    void addRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it != mp.begin()) {
            auto pit = std::prev(it);
            if (pit->second >= left) {
                left = pit->first;
                right = std::max(right, pit->second);
                mp.erase(pit);
            }
        }
        while (it != mp.end() && it->first <= right) {
            right = std::max(right, it->second);
            it = mp.erase(it);
        }
        mp[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it == mp.begin())
            return false;
        --it;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it != mp.begin()) {
            auto pit = std::prev(it);
            if (pit->second > left) {
                int oldR = pit->second;
                pit->second = left;
                if (oldR > right)
                    mp[right] = oldR;
            }
        }
        it = mp.lower_bound(left);
        while (it != mp.end() && it->first < right) {
            if (it->second <= right)
                it = mp.erase(it);
            else {
                int r = it->second;
                mp.erase(it);
                mp[right] = r;
                break;
            }
        }
    }
};

int main() {
    RangeModule r;
    r.addRange(10, 20);
    r.removeRange(14, 16);
    std::cout << std::boolalpha << r.queryRange(10, 14) << " (expected true)\n"
              << r.queryRange(13, 15) << " (expected false)\n"
              << r.queryRange(16, 17) << " (expected true)\n";
    return 0;
}
