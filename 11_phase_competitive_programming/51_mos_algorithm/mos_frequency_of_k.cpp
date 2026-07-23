// Mo's algorithm — frequency of value K in [L, R] (K per query)
// Maintain freq[] in the Mo window; answer is freq[K] after alignment.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l;
    int r;
    int k;
    int idx;
};

int main() {
    std::vector<int> a = {1, 2, 1, 1, 3};
    const int n = static_cast<int>(a.size());
    std::vector<Query> queries = {
        {0, 3, 1, 0}, {1, 4, 2, 1}, {0, 4, 3, 2}, {2, 2, 1, 3}, {0, 4, 9, 4},
    };
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
    const int freqSize = std::max(maxVal, 9) + 1; // room for out-of-range K=9
    std::vector<int> freq(static_cast<size_t>(freqSize), 0);
    std::vector<int> answers(q);
    int curL = 0;
    int curR = -1;

    auto add = [&](int i) { ++freq[static_cast<size_t>(a[static_cast<size_t>(i)])]; };
    auto remove = [&](int i) { --freq[static_cast<size_t>(a[static_cast<size_t>(i)])]; };

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
        if (qr.k >= 0 && qr.k < freqSize) {
            answers[static_cast<size_t>(qr.idx)] = freq[static_cast<size_t>(qr.k)];
        } else {
            answers[static_cast<size_t>(qr.idx)] = 0;
        }
    }

    const std::vector<int> expected = {3, 1, 1, 1, 0};
    const bool ok = (answers == expected);
    std::cout << "answers:";
    for (int x : answers) {
        std::cout << " " << x;
    }
    std::cout << "\nexpected: 3 1 1 1 0\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
