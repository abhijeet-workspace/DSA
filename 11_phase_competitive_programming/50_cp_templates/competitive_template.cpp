// Competitive programming starter template — fast IO, aliases, mod helpers
// Compile with -DLOCAL to enable debug(...) macro
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

#define FAST_IO                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);     \
    std::cout.tie(nullptr)

using ll = long long;
using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vi = std::vector<int>;
using vll = std::vector<ll>;

constexpr int INF = 1e9 + 7;
constexpr ll LINF = 1e18 + 7;
constexpr int MOD = 1e9 + 7;

constexpr int dx[4] = {-1, 0, 1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

#ifdef LOCAL
#define debug(x...)            \
    std::cout << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void _print() { std::cout << "]\n"; }
template <typename T, typename... Args>
void _print(T t, Args... args) {
    std::cout << t;
    if (sizeof...(args)) std::cout << ", ";
    _print(args...);
}

template <typename T>
inline T gcd_t(T a, T b) {
    return b == 0 ? a : gcd_t(b, a % b);
}
template <typename T>
inline T lcm_t(T a, T b) {
    return (a / gcd_t(a, b)) * b;
}
inline ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
inline ll mod_sub(ll a, ll b, ll m = MOD) { return (a % m - b % m + m) % m; }
inline ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m) * (b % m) % m; }

void solve(int /*tc*/) {
    int n;
    if (!(std::cin >> n)) return;
    vi a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    debug(n);
    ll sum = std::accumulate(a.begin(), a.end(), 0LL);
    std::cout << sum << "\n";
}

int main() {
    FAST_IO;
    int t = 1;
    // std::cin >> t; // multi-test
    for (int tc = 1; tc <= t; ++tc) {
        // solve(tc);
    }
    std::cout << "Competitive Template compiled successfully!\n";
    return 0;
}
