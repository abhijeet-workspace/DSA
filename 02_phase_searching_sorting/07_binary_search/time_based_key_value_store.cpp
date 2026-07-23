// Time Based Key-Value Store — https://leetcode.com/problems/time-based-key-value-store/
// set appends (timestamp, value); get binary-searches latest timestamp <= query.
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;

public:
    void set(const std::string& key, const std::string& value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    std::string get(const std::string& key, int timestamp) {
        const auto it = store.find(key);
        if (it == store.end()) {
            return "";
        }
        const auto& v = it->second;
        int lo = 0;
        int hi = static_cast<int>(v.size()) - 1;
        int ans = -1;
        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            if (v[static_cast<size_t>(mid)].first <= timestamp) {
                ans = mid;
                lo = mid + 1; // latest feasible
            } else {
                hi = mid - 1;
            }
        }
        return ans == -1 ? "" : v[static_cast<size_t>(ans)].second;
    }
};

int main() {
    TimeMap tm;
    tm.set("foo", "bar", 1);
    std::cout << tm.get("foo", 1) << " (expected bar)\n"
              << tm.get("foo", 3) << " (expected bar)\n";
    tm.set("foo", "bar2", 4);
    std::cout << tm.get("foo", 4) << " (expected bar2)\n";
    return 0;
}
