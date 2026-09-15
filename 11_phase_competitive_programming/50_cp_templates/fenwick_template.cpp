// Fenwick (BIT) template — prefix sums + point add
#include <iostream>
#include <vector>

struct Fenwick {
    int n;
    std::vector<long long> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, long long v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }
    long long sumPrefix(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
    long long rangeSum(int l, int r) const { // 1-based inclusive
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

int main() {
    Fenwick fw(5);
    for (int i = 1; i <= 5; ++i)
        fw.add(i, i);                      // 1..5
    const long long q = fw.rangeSum(2, 4); // 2+3+4=9
    std::cout << "range[2,4]=" << q << " expected=9\n";
    std::cout << (q == 9 ? "OK\n" : "FAIL\n");
    return q == 9 ? 0 : 1;
}
