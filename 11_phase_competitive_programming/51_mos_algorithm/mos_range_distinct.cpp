// Mo's algorithm — count distinct values in offline ranges [L, R]
// Freq table + distinct counter; add 0→1 / remove 1→0 flips distinct.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l;
    int r;
    int idx;
};

int main() {
    std::vector<int> a = {1, 2, 1, 3, 2};
    const int n = static_cast<int>(a.size());
    std::vector<Query> queries = {{0, 4, 0}, {1, 2, 1}, {2, 4, 2}, {0, 0, 3}};
    const int q = static_cast<int>(queries.size());
    const int block = std::max(1, static_cast<int>(std::sqrt(n)));

    std::sort(queries.begin(), queries.end(), [block](const Query& A, const Query& B) {
        const int ba = A.l / block;
        const int bb = B.l / block;
        if (ba != bb) {
            return ba < bb;
        }
        return (ba & 1) ? (A.r > B.r) : (A.r < B.r);
    });

    int maxVal = 0;
    for (int x : a) {
        maxVal = std::max(maxVal, x);
    }
    std::vector<int> freq(static_cast<size_t>(maxVal) + 1, 0);
    std::vector<int> answers(q);
    int curL = 0;
    int curR = -1;
    int distinct = 0;

    auto add = [&](int i) {
        const int v = a[static_cast<size_t>(i)];
        if (freq[static_cast<size_t>(v)] == 0) {
            ++distinct;
        }
        ++freq[static_cast<size_t>(v)];
    };
    auto remove = [&](int i) {
        const int v = a[static_cast<size_t>(i)];
        --freq[static_cast<size_t>(v)];
        if (freq[static_cast<size_t>(v)] == 0) {
            --distinct;
        }
    };

    for (const Query& qr : queries) {
        while (curL > qr.l) {
            add(--curL);
        }
        while (curR < qr.r) {
            add(++curR);
        }
        while (curL < qr.l) {
            remove(curL++);
        }
        while (curR > qr.r) {
            remove(curR--);
        }
        answers[static_cast<size_t>(qr.idx)] = distinct;
    }

    const std::vector<int> expected = {3, 2, 3, 1};
    const bool ok = (answers == expected);
    std::cout << "answers:";
    for (int x : answers) {
        std::cout << " " << x;
    }
    std::cout << "\nexpected: 3 2 3 1\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
