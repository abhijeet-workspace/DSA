// Mo — range product modulo prime (remove via modular inverse)
// Prefer prefix products in contests; this teaches removable non-sum aggregator.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};
long long modPow(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    a %= mod;
    while (e) {
        if (e & 1)
            r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    const long long MOD = 1'000'000'007;
    std::vector<long long> a = {2, 3, 5, 7, 11};
    const int n = (int)a.size();
    std::vector<Query> queries = {{0, 4, 0}, {1, 3, 1}, {2, 2, 2}, {0, 1, 3}};
    const int q = (int)queries.size();
    const int block = std::max(1, (int)std::sqrt(n));
    std::sort(queries.begin(), queries.end(), [block](const Query& A, const Query& B) {
        int ba = A.l / block, bb = B.l / block;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (A.r > B.r) : (A.r < B.r);
    });
    long long prod = 1;
    int curL = 0, curR = -1;
    std::vector<long long> answers(q);
    auto add = [&](int i) { prod = prod * a[i] % MOD; };
    auto remove = [&](int i) { prod = prod * modPow(a[i], MOD - 2, MOD) % MOD; };
    for (auto qr : queries) {
        while (curL > qr.l)
            add(--curL);
        while (curR < qr.r)
            add(++curR);
        while (curL < qr.l)
            remove(curL++);
        while (curR > qr.r)
            remove(curR--);
        answers[qr.idx] = prod;
    }
    auto brute = [&](int L, int R) {
        long long p = 1;
        for (int i = L; i <= R; ++i)
            p = p * a[i] % MOD;
        return p;
    };
    std::vector<long long> exp = {brute(0, 4), brute(1, 3), brute(2, 2), brute(0, 1)};
    bool ok = answers == exp;
    std::cout << "answers:";
    for (auto x : answers)
        std::cout << " " << x;
    std::cout << "\nexpected:";
    for (auto x : exp)
        std::cout << " " << x;
    std::cout << "\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
