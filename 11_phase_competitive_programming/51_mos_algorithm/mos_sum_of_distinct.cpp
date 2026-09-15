// Mo — sum of distinct values in range
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};

int main() {
    std::vector<int> a = {1, 2, 1, 3, 2};
    const int n = (int)a.size();
    std::vector<Query> queries = {{0, 4, 0}, {1, 2, 1}, {2, 4, 2}, {0, 0, 3}};
    const int q = (int)queries.size();
    const int block = std::max(1, (int)std::sqrt(n));
    std::sort(queries.begin(), queries.end(), [block](const Query& A, const Query& B) {
        int ba = A.l / block, bb = B.l / block;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (A.r > B.r) : (A.r < B.r);
    });
    int maxV = 0;
    for (int x : a)
        maxV = std::max(maxV, x);
    std::vector<int> freq(maxV + 1, 0);
    long long sumDist = 0;
    auto add = [&](int i) {
        int v = a[i];
        if (freq[v]++ == 0)
            sumDist += v;
    };
    auto remove = [&](int i) {
        int v = a[i];
        if (--freq[v] == 0)
            sumDist -= v;
    };
    int curL = 0, curR = -1;
    std::vector<long long> answers(q);
    for (auto qr : queries) {
        while (curL > qr.l)
            add(--curL);
        while (curR < qr.r)
            add(++curR);
        while (curL < qr.l)
            remove(curL++);
        while (curR > qr.r)
            remove(curR--);
        answers[qr.idx] = sumDist;
    }
    const std::vector<long long> expected = {6, 3, 6, 1}; // 1+2+3, 2+1, 1+3+2, 1
    bool ok = answers == expected;
    std::cout << "answers:";
    for (auto x : answers)
        std::cout << " " << x;
    std::cout << "\nexpected: 6 3 6 1\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
