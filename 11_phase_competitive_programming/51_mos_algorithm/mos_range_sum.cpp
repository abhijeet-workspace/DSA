// Mo's algorithm — offline range sum (teaching)
// Block-sort queries; slide [L,R] with O(1) add/remove on window sum.
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
    std::vector<long long> a = {1, 2, 3, 4, 5};
    const int n = static_cast<int>(a.size());
    std::vector<Query> queries = {{0, 4, 0}, {1, 3, 1}, {2, 2, 2}, {0, 1, 3}};
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

    std::vector<long long> answers(q);
    int curL = 0;
    int curR = -1;
    long long sum = 0;
    auto add = [&](int i) { sum += a[static_cast<size_t>(i)]; };
    auto remove = [&](int i) { sum -= a[static_cast<size_t>(i)]; };

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
        answers[static_cast<size_t>(qr.idx)] = sum;
    }

    const std::vector<long long> expected = {15, 9, 3, 3};
    const bool ok = (answers == expected);
    std::cout << "answers:";
    for (long long x : answers) {
        std::cout << " " << x;
    }
    std::cout << "\nexpected: 15 9 3 3\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
