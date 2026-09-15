// XOR Queries of a Subarray — LC 1310
// Prefix XOR: query [L,R] = pref[R+1] ^ pref[L].
#include <iostream>
#include <vector>

std::vector<int> xorQueries(const std::vector<int>& arr, const std::vector<std::vector<int>>& queries) {
    const int n = static_cast<int>(arr.size());
    std::vector<int> pref(static_cast<size_t>(n + 1), 0);
    for (int i = 0; i < n; ++i)
        pref[static_cast<size_t>(i + 1)] = pref[static_cast<size_t>(i)] ^ arr[static_cast<size_t>(i)];

    std::vector<int> ans;
    ans.reserve(queries.size());
    for (const auto& q : queries) {
        int L = q[0];
        int R = q[1];
        ans.push_back(pref[static_cast<size_t>(R + 1)] ^ pref[static_cast<size_t>(L)]);
    }
    return ans;
}

int main() {
    auto a = xorQueries({1, 3, 4, 8}, {{0, 1}, {1, 2}, {0, 3}, {3, 3}});
    std::cout << "[";
    for (size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << (i + 1 < a.size() ? "," : "");
    std::cout << "] (expected [2,7,14,8])\n";

    auto b = xorQueries({4, 8, 2, 10}, {{2, 3}, {1, 3}, {0, 0}, {0, 3}});
    std::cout << "[";
    for (size_t i = 0; i < b.size(); ++i)
        std::cout << b[i] << (i + 1 < b.size() ? "," : "");
    std::cout << "] (expected [8,0,4,4])\n";
    return 0;
}
