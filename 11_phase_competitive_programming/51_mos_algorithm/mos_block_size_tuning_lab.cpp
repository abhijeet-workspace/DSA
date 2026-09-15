// Mo block-size tuning lab — measure move counts for different B
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};

long long moveCount(int n, std::vector<Query> queries, int block) {
    std::sort(queries.begin(), queries.end(), [block](const Query& A, const Query& B) {
        int ba = A.l / block, bb = B.l / block;
        if (ba != bb)
            return ba < bb;
        return A.r < B.r;
    });
    int curL = 0, curR = -1;
    long long moves = 0;
    for (auto qr : queries) {
        moves += std::abs(curL - qr.l) + std::abs(curR - qr.r);
        curL = qr.l;
        curR = qr.r;
    }
    return moves;
}

int main() {
    const int n = 100;
    std::vector<Query> queries;
    int idx = 0;
    for (int i = 0; i < 50; ++i) {
        int l = (i * 7) % n, r = (i * 13) % n;
        if (l > r)
            std::swap(l, r);
        queries.push_back({l, r, idx++});
    }
    long long mSqrt = moveCount(n, queries, std::max(1, (int)std::sqrt(n)));
    long long m1 = moveCount(n, queries, 1);
    long long mN = moveCount(n, queries, n);
    std::cout << "moves sqrt=" << mSqrt << " B=1=" << m1 << " B=n=" << mN << "\n";
    const bool ok = (mSqrt <= m1 && mSqrt <= mN);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
