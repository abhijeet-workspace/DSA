// FFT multiply — convolution via Cooley–Tukey DFT
// Time O(N log N), space O(N); pad length to power of two
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using cd = std::complex<double>;
using ll = long long;
constexpr double PI = 3.14159265358979323846;

void fft(std::vector<cd>& a, bool invert) {
    const int n = static_cast<int>(a.size());
    if (n == 1) return;
    std::vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; ++i) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    const double ang = 2 * PI / n * (invert ? -1.0 : 1.0);
    cd w(1), wn(std::cos(ang), std::sin(ang));
    for (int i = 0; 2 * i < n; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

std::vector<ll> multiply(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < static_cast<int>(a.size() + b.size())) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);
    std::vector<ll> res(n);
    for (int i = 0; i < n; ++i) res[i] = std::llround(fa[i].real());
    return res;
}

int main() {
    auto prod = multiply({1, 2, 3}, {2, 3});
    std::cout << "coeffs:";
    for (int i = 0; i < 4; ++i) std::cout << " " << prod[i];
    std::cout << " (expected 2 7 12 9)\n";
    return 0;
}
