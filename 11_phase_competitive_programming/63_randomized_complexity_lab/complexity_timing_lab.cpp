// Complexity timing lab — O(N) vs O(N log N) vs O(N²)
// Wall-time trends; sink prevents dead-code elimination.
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

static long long sink = 0;

long long linear_sum(const std::vector<int>& a) {
    long long s = 0;
    for (int x : a) {
        s += x;
    }
    sink ^= s;
    return s;
}

void nlogn_sort(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    sink ^= a.empty() ? 0 : a.back();
}

long long quadratic(const std::vector<int>& a) {
    long long s = 0;
    const int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            s += a[static_cast<size_t>(i)] ^ a[static_cast<size_t>(j)];
        }
    }
    sink ^= s;
    return s;
}

template <class F>
double ms(F&& f) {
    const auto t0 = std::chrono::steady_clock::now();
    f();
    const auto t1 = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}

int main() {
    for (int n : {2000, 4000, 8000}) {
        std::vector<int> a(static_cast<size_t>(n));
        std::iota(a.begin(), a.end(), 1);
        const double t1 = ms([&] { linear_sum(a); });
        const double t2 = ms([&] { nlogn_sort(a); });
        const double t3 = ms([&] { quadratic(a); });
        std::cout << "N=" << n << "  O(N)=" << t1 << "ms  O(NlogN)=" << t2
                  << "ms  O(N^2)=" << t3 << "ms\n";
    }
    std::cout << "sink=" << sink << " (ignore; prevents DCE)\n";
    return 0;
}
