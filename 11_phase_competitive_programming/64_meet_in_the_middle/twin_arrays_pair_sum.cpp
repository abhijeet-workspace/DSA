// Twin arrays pair sum — MITM building block
#include <iostream>
#include <unordered_map>
#include <vector>

long long countPairs(const std::vector<int>& A, const std::vector<int>& B, int T) {
    std::unordered_map<int, int> freq;
    for (int x : A)
        ++freq[x];
    long long ans = 0;
    for (int y : B) {
        auto it = freq.find(T - y);
        if (it != freq.end())
            ans += it->second;
    }
    return ans;
}

int main() {
    std::cout << countPairs({1, 2, 3}, {3, 2}, 4) << " (expected 2)\n";
    return 0;
}
