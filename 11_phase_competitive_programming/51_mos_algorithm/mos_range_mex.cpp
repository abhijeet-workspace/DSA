// Mo — range MEX for small alphabet (values in 0..K)
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};

int main() {
    std::vector<int> a = {0, 1, 2, 0, 1, 3};
    const int n = (int)a.size(), K = 4; // values in 0..3, mex in 0..4
    std::vector<Query> queries = {{0, 5, 0}, {0, 2, 1}, {2, 4, 2}, {3, 5, 3}};
    const int q = (int)queries.size();
    const int block = std::max(1, (int)std::sqrt(n));
    std::sort(queries.begin(), queries.end(), [block](const Query& A, const Query& B) {
        int ba = A.l / block, bb = B.l / block;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (A.r > B.r) : (A.r < B.r);
    });
    std::vector<int> freq(K + 2, 0);
    int mex = 0;
    auto add = [&](int i) {
        int v = a[i];
        if (v <= K) {
            ++freq[v];
            while (freq[mex] > 0)
                ++mex;
        }
    };
    auto remove = [&](int i) {
        int v = a[i];
        if (v <= K) {
            --freq[v];
            if (freq[v] == 0 && v < mex)
                mex = v;
        }
    };
    int curL = 0, curR = -1;
    std::vector<int> answers(q);
    for (auto qr : queries) {
        while (curL > qr.l)
            add(--curL);
        while (curR < qr.r)
            add(++curR);
        while (curL < qr.l)
            remove(curL++);
        while (curR > qr.r)
            remove(curR--);
        answers[qr.idx] = mex;
    }
    auto brute = [&](int L, int R) {
        std::vector<char> seen(K + 2, 0);
        for (int i = L; i <= R; ++i)
            if (a[i] <= K)
                seen[a[i]] = 1;
        int m = 0;
        while (seen[m])
            ++m;
        return m;
    };
    std::vector<int> exp = {brute(0, 5), brute(0, 2), brute(2, 4), brute(3, 5)};
    bool ok = answers == exp;
    std::cout << "answers:";
    for (int x : answers)
        std::cout << " " << x;
    std::cout << "\nexpected:";
    for (int x : exp)
        std::cout << " " << x;
    std::cout << "\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
