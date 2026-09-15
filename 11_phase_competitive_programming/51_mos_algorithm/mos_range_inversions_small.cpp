// Mo — range inversion count for small values via Fenwick inside add/remove
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};
struct Fenwick {
    int n;
    std::vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }
    int sum(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

int main() {
    std::vector<int> a = {3, 1, 2, 4, 1}; // 1-based ranks already small
    const int n = (int)a.size();
    int maxV = 0;
    for (int x : a)
        maxV = std::max(maxV, x);
    std::vector<Query> queries = {{0, 4, 0}, {0, 2, 1}, {2, 4, 2}, {1, 1, 3}};
    const int q = (int)queries.size();
    const int block = std::max(1, (int)std::sqrt(n));
    std::sort(queries.begin(), queries.end(), [block](const Query& A, const Query& B) {
        int ba = A.l / block, bb = B.l / block;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (A.r > B.r) : (A.r < B.r);
    });
    Fenwick fw(maxV);
    long long inv = 0;
    auto addLeft =
        [&](int i) { // insert at left: count smaller? actually inversions: pairs i<j a[i]>a[j]
            // when expanding left (new index i < curL), new element is leftmost:
            // inversions added = # of values in window < a[i]? No: pairs (i,j) with i<j, a[i]>a[j]
            // new i is smallest index, so j>i all window: count how many a[j] < a[i]
            inv += fw.sum(a[i] - 1);
            fw.add(a[i], 1);
        };
    auto addRight = [&](int i) {
        // new i is rightmost: count how many in window > a[i]
        inv += fw.sum(maxV) - fw.sum(a[i]);
        fw.add(a[i], 1);
    };
    auto removeLeft = [&](int i) {
        fw.add(a[i], -1);
        inv -= fw.sum(a[i] - 1);
    };
    auto removeRight = [&](int i) {
        fw.add(a[i], -1);
        inv -= fw.sum(maxV) - fw.sum(a[i]);
    };
    int curL = 0, curR = -1;
    std::vector<long long> answers(q);
    for (auto qr : queries) {
        while (curL > qr.l)
            addLeft(--curL);
        while (curR < qr.r)
            addRight(++curR);
        while (curL < qr.l)
            removeLeft(curL++);
        while (curR > qr.r)
            removeRight(curR--);
        answers[qr.idx] = inv;
    }
    auto brute = [&](int L, int R) {
        long long c = 0;
        for (int i = L; i <= R; ++i)
            for (int j = i + 1; j <= R; ++j)
                if (a[i] > a[j])
                    ++c;
        return c;
    };
    std::vector<long long> exp = {brute(0, 4), brute(0, 2), brute(2, 4), brute(1, 1)};
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
