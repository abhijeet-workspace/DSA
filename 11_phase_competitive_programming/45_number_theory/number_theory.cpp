// Number theory toolkit — sieve, gcd/extGCD, modpow, phi, CRT
// Times: sieve O(N log log N); gcd/pow O(log); phi O(√N); CRT O(K log M)
#include <iostream>
#include <vector>

using ll = long long;

std::vector<int> sieve(int n) {
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (!is_prime[p]) continue;
        for (int i = p * p; i <= n; i += p) is_prime[i] = false;
    }
    std::vector<int> primes;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) primes.push_back(p);
    }
    return primes;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// a*x + b*y = gcd(a, b)
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// Fermat inverse — mod must be prime
ll mod_inverse(ll n, ll mod) { return power(n, mod - 2, mod); }

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// x ≡ rem[i] (mod num[i]); moduli pairwise coprime
ll crt(const std::vector<ll>& num, const std::vector<ll>& rem) {
    ll prod = 1;
    const int k = static_cast<int>(num.size());
    for (int i = 0; i < k; ++i) prod *= num[i];

    ll result = 0;
    for (int i = 0; i < k; ++i) {
        ll pp = prod / num[i];
        ll inv_x, inv_y;
        ext_gcd(pp, num[i], inv_x, inv_y);
        inv_x = (inv_x % num[i] + num[i]) % num[i];
        result = (result + rem[i] * inv_x % prod * pp) % prod;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto primes = sieve(30);
    std::cout << "Primes <= 30:";
    for (int p : primes) std::cout << " " << p;
    std::cout << "\n";

    ll x, y;
    ll g = ext_gcd(35, 15, x, y);
    std::cout << "extGCD 35,15: 35*(" << x << ")+15*(" << y << ")=" << g << "\n";
    std::cout << "phi(12)=" << phi(12) << " (expected 4)\n";

    std::vector<ll> num = {3, 5, 7};
    std::vector<ll> rem = {2, 3, 2};
    std::cout << "CRT min x=" << crt(num, rem) << " (expected 23)\n";
    return 0;
}
