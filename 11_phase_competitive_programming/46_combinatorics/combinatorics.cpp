// Combinatorics — nCr, Catalan, Stirling2, inclusion-exclusion
// nCr O(1) after O(MAX) precompute; Stirling O(nk); IE O(1) for 3 sets
#include <iostream>
#include <vector>

using ll = long long;
constexpr int MOD = 1'000'000'007;
constexpr int MAX = 100005;

ll fact[MAX];
ll inv_fact[MAX];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX; ++i) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 1; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

// C(n) = (2n)! / ((n+1)! n!)
ll catalan(int n) {
    if (n <= 1) return 1;
    return fact[2 * n] * inv_fact[n + 1] % MOD * inv_fact[n] % MOD;
}

// S(n,k): partitions of n into k nonempty unlabeled subsets
ll stirling_second(int n, int k) {
    std::vector<std::vector<ll>> S(n + 1, std::vector<ll>(k + 1, 0));
    S[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
        }
    }
    return S[n][k];
}

ll gcd_ll(ll x, ll y) { return y == 0 ? x : gcd_ll(y, x % y); }
ll lcm_ll(ll x, ll y) { return x / gcd_ll(x, y) * y; }

// |A∪B∪C| for multiples of a,b,c in [1, limit]
ll count_divisible(ll limit, ll a, ll b, ll c) {
    return limit / a + limit / b + limit / c - limit / lcm_ll(a, b) - limit / lcm_ll(b, c) -
           limit / lcm_ll(a, c) + limit / lcm_ll(lcm_ll(a, b), c);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    precompute();
    std::cout << "5C2=" << nCr(5, 2) << " 10C3=" << nCr(10, 3) << "\n";
    std::cout << "Catalan(3)=" << catalan(3) << " (expected 5)\n";
    std::cout << "Catalan(5)=" << catalan(5) << " (expected 42)\n";
    std::cout << "S(4,2)=" << stirling_second(4, 2) << " (expected 7)\n";
    std::cout << "div by 3|5|7 <=100: " << count_divisible(100, 3, 5, 7) << " (expected 55)\n";
    return 0;
}
