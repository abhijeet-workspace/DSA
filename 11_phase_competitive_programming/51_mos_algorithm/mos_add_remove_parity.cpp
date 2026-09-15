// Mo — count values with odd frequency in range
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};

int main() {
    std::vector<int> a = {1, 2, 1, 2, 3};
    const int n = (int)a.size();
    std::vector<Query> queries = {{0, 4, 0}, {0, 3, 1}, {1, 2, 2}, {4, 4, 3}};
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
    int oddCount = 0;
    auto add = [&](int i) {
        int v = a[i];
        if (freq[v] % 2 == 0)
            ++oddCount;
        else
            --oddCount;
        ++freq[v];
    };
    auto remove = [&](int i) {
        int v = a[i];
        --freq[v];
        if (freq[v] % 2 == 0)
            --oddCount;
        else
            ++oddCount;
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
        answers[qr.idx] = oddCount;
    }
    auto brute = [&](int L, int R) {
        std::vector<int> fr(maxV + 1, 0);
        for (int i = L; i <= R; ++i)
            ++fr[a[i]];
        int c = 0;
        for (int f : fr)
            if (f % 2)
                ++c;
        return c;
    };
    std::vector<int> exp = {brute(0, 4), brute(0, 3), brute(1, 2), brute(4, 4)};
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
