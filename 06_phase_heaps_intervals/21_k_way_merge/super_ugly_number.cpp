// Super Ugly Number — https://leetcode.com/problems/super-ugly-number/
// Min-heap merge of prime multiples (generalized ugly number).
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

int nthSuperUglyNumber(int n, std::vector<int>& primes) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    std::unordered_set<long long> seen;
    pq.push(1);
    seen.insert(1);
    long long cur = 1;
    for (int i = 0; i < n; ++i) {
        cur = pq.top();
        pq.pop();
        for (int p : primes) {
            long long nxt = cur * p;
            if (!seen.count(nxt)) {
                seen.insert(nxt);
                pq.push(nxt);
            }
        }
    }
    return static_cast<int>(cur);
}

int main() {
    std::vector<int> primes = {2, 7, 13, 19};
    std::cout << nthSuperUglyNumber(12, primes) << " (expected 32)\n";
    return 0;
}
