// Mo — count unordered pairs (i,j) in range with a[i]==a[j], i<j
// When freq goes f→f+1, add f new pairs.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};

int main() {
    std::vector<int> a = {1, 2, 1, 1, 2};
    const int n = (int)a.size();
    std::vector<Query> queries = {{0, 4, 0}, {0, 2, 1}, {1, 4, 2}, {3, 3, 3}};
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
    long long pairs = 0;
    auto add = [&](int i) {
        int v = a[i];
        pairs += freq[v];
        ++freq[v];
    };
    auto remove = [&](int i) {
        int v = a[i];
        --freq[v];
        pairs -= freq[v];
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
        answers[qr.idx] = pairs;
    }
    auto brute = [&](int L, int R) {
        long long c = 0;
        for (int i = L; i <= R; ++i)
            for (int j = i + 1; j <= R; ++j)
                if (a[i] == a[j])
                    ++c;
        return c;
    };
    std::vector<long long> exp = {brute(0, 4), brute(0, 2), brute(1, 4), brute(3, 3)};
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
