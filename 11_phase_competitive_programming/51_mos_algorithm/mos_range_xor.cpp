// Mo — range XOR (teaching). Prefer prefix XOR in contests.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    const int n = (int)a.size();
    std::vector<Query> queries = {{0, 4, 0}, {1, 3, 1}, {2, 2, 2}, {0, 1, 3}};
    const int q = (int)queries.size();
    const int block = std::max(1, (int)std::sqrt(n));
    std::sort(queries.begin(), queries.end(), [block](const Query& A, const Query& B) {
        int ba = A.l / block, bb = B.l / block;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (A.r > B.r) : (A.r < B.r);
    });
    int x = 0, curL = 0, curR = -1;
    std::vector<int> answers(q);
    auto add = [&](int i) { x ^= a[i]; };
    auto remove = [&](int i) { x ^= a[i]; };
    for (auto qr : queries) {
        while (curL > qr.l)
            add(--curL);
        while (curR < qr.r)
            add(++curR);
        while (curL < qr.l)
            remove(curL++);
        while (curR > qr.r)
            remove(curR--);
        answers[qr.idx] = x;
    }
    const std::vector<int> expected = {0x1 ^ 0x2 ^ 0x3 ^ 0x4 ^ 0x5, 0x2 ^ 0x3 ^ 0x4, 3, 0x1 ^ 0x2};
    bool ok = answers == expected;
    std::cout << "answers:";
    for (int v : answers)
        std::cout << " " << v;
    std::cout << "\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
