// Time Mo (simplified teaching) — offline range distinct with point updates
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, t, idx;
};
struct Update {
    int pos, prev, next;
};

int main() {
    std::vector<int> a = {1, 2, 1, 3};
    std::vector<Update> ups = {{1, 2, 5}}; // a[1]: 2 -> 5
    std::vector<Query> qs = {{0, 3, 0, 0}, {0, 3, 1, 1}, {1, 1, 1, 2}};
    const int n = (int)a.size(), q = (int)qs.size();
    int B = std::max(1, (int)std::cbrt(n * 1.0 * std::max(1, (int)ups.size()) + 1));
    std::sort(qs.begin(), qs.end(), [B](const Query& A, const Query& Bq) {
        int ta = A.t / B, tb = Bq.t / B;
        if (ta != tb)
            return ta < tb;
        int ba = A.l / B, bb = Bq.l / B;
        if (ba != bb)
            return ba < bb;
        return A.r < Bq.r;
    });
    std::vector<int> cur = a;
    const int maxV = 10;
    std::vector<int> freq(maxV + 1, 0), answers(q);
    int curL = 0, curR = -1, curT = 0, distinct = 0;
    auto add = [&](int i) {
        int v = cur[i];
        if (freq[v]++ == 0)
            ++distinct;
    };
    auto remove = [&](int i) {
        int v = cur[i];
        if (--freq[v] == 0)
            --distinct;
    };
    auto setPos = [&](int p, int val) {
        if (curL <= p && p <= curR) {
            int old = cur[p];
            if (--freq[old] == 0)
                --distinct;
            cur[p] = val;
            if (freq[val]++ == 0)
                ++distinct;
        } else {
            cur[p] = val;
        }
    };
    for (auto qr : qs) {
        while (curT < qr.t) {
            setPos(ups[curT].pos, ups[curT].next);
            ++curT;
        }
        while (curT > qr.t) {
            --curT;
            setPos(ups[curT].pos, ups[curT].prev);
        }
        while (curL > qr.l)
            add(--curL);
        while (curR < qr.r)
            add(++curR);
        while (curL < qr.l)
            remove(curL++);
        while (curR > qr.r)
            remove(curR--);
        answers[qr.idx] = distinct;
    }
    auto run = [&](int t, int L, int R) {
        auto b = a;
        for (int i = 0; i < t; ++i)
            b[ups[i].pos] = ups[i].next;
        std::vector<int> fr(maxV + 1, 0);
        int d = 0;
        for (int i = L; i <= R; ++i)
            if (fr[b[i]]++ == 0)
                ++d;
        return d;
    };
    std::vector<int> exp = {run(0, 0, 3), run(1, 0, 3), run(1, 1, 1)};
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
