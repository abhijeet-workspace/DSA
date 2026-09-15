// Mo with Hilbert-order sorting — same distinct answers, different visit order
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
    uint64_t h;
};

uint64_t hilbert(int x, int y, int maxn) {
    // Simplified Hilbert rank for teaching (bit-interleave style fallback if maxn small)
    int bits = 0;
    while ((1 << bits) < maxn)
        ++bits;
    if (bits == 0)
        bits = 1;
    uint64_t d = 0;
    for (int s = bits - 1; s >= 0; --s) {
        int rx = (x >> s) & 1, ry = (y >> s) & 1;
        d = (d << 2) | ((rx * 3) ^ ry);
        if (ry == 0) {
            if (rx == 1) {
                x = (1 << (s + 1)) - 1 - x;
                y = (1 << (s + 1)) - 1 - y;
            }
            std::swap(x, y);
        }
    }
    return d;
}

int main() {
    std::vector<int> a = {1, 2, 1, 3, 2, 2};
    const int n = (int)a.size();
    std::vector<Query> queries = {{0, 5, 0, 0}, {1, 2, 1, 0}, {2, 5, 2, 0}, {0, 0, 3, 0}};
    for (auto& qr : queries)
        qr.h = hilbert(qr.l, qr.r, n);
    std::sort(queries.begin(), queries.end(),
              [](const Query& A, const Query& B) { return A.h < B.h; });
    int maxV = 0;
    for (int x : a)
        maxV = std::max(maxV, x);
    std::vector<int> freq(maxV + 1, 0), answers(queries.size());
    int curL = 0, curR = -1, distinct = 0;
    auto add = [&](int i) {
        int v = a[i];
        if (freq[v]++ == 0)
            ++distinct;
    };
    auto remove = [&](int i) {
        int v = a[i];
        if (--freq[v] == 0)
            --distinct;
    };
    for (auto qr : queries) {
        while (curL > qr.l)
            add(--curL);
        while (curR < qr.r)
            add(++curR);
        while (curL < qr.l)
            remove(curL++);
        while (curR > qr.r)
            remove(curR--);
        answers[qr.idx] = distinct;
    }
    const std::vector<int> expected = {3, 2, 3, 1};
    bool ok = answers == expected;
    std::cout << "answers:";
    for (int x : answers)
        std::cout << " " << x;
    std::cout << "\nexpected: 3 2 3 1\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
