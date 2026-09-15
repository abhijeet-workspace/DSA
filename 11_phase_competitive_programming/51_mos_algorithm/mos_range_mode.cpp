// Mo — range mode (most frequent value); small values
// Maintain freq[] and freqOfFreq[]; track current mode frequency & a mode value.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Query {
    int l, r, idx;
};

int main() {
    std::vector<int> a = {1, 2, 2, 1, 3, 2};
    const int n = (int)a.size();
    std::vector<Query> queries = {{0, 5, 0}, {0, 2, 1}, {3, 5, 2}, {4, 4, 3}};
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
    std::vector<int> freq(maxV + 1, 0), freqOfFreq(n + 1, 0);
    int curMaxF = 0;
    int modeVal = -1;
    auto add = [&](int i) {
        int v = a[i], f = freq[v];
        if (f > 0)
            --freqOfFreq[f];
        ++freq[v];
        ++freqOfFreq[f + 1];
        if (f + 1 > curMaxF) {
            curMaxF = f + 1;
            modeVal = v;
        } else if (f + 1 == curMaxF)
            modeVal = std::min(modeVal, v);
    };
    auto remove = [&](int i) {
        int v = a[i], f = freq[v];
        --freqOfFreq[f];
        --freq[v];
        if (f - 1 > 0)
            ++freqOfFreq[f - 1];
        if (f == curMaxF && freqOfFreq[curMaxF] == 0) {
            --curMaxF;
            modeVal = -1;
            for (int x = 0; x <= maxV; ++x)
                if (freq[x] == curMaxF) {
                    modeVal = (modeVal == -1 ? x : std::min(modeVal, x));
                }
        } else if (f == curMaxF && v == modeVal) {
            modeVal = -1;
            for (int x = 0; x <= maxV; ++x)
                if (freq[x] == curMaxF) {
                    modeVal = (modeVal == -1 ? x : std::min(modeVal, x));
                }
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
        answers[qr.idx] = modeVal;
    }
    const std::vector<int> expected = {2, 2, 2, 3}; // ties -> smallest
    // verify expected manually: [0,5] mode 2; [0,2]={1,2,2} mode 2; [3,5]={1,3,2} all 1 -> min 1?
    // Wait [3,5]=1,3,2 all freq 1 -> modeVal min = 1. Fix expected. Recompute expected properly: We
    // will print and set expected to computed brute.
    auto brute = [&](int L, int R) {
        std::vector<int> fr(maxV + 1, 0);
        for (int i = L; i <= R; ++i)
            ++fr[a[i]];
        int bestF = 0, best = 0;
        for (int x = 0; x <= maxV; ++x)
            if (fr[x] > bestF || (fr[x] == bestF && x < best)) {
                bestF = fr[x];
                best = x;
            }
        return best;
    };
    std::vector<int> exp2 = {brute(0, 5), brute(0, 2), brute(3, 5), brute(4, 4)};
    bool ok = (answers == exp2);
    std::cout << "answers:";
    for (int x : answers)
        std::cout << " " << x;
    std::cout << "\nexpected:";
    for (int x : exp2)
        std::cout << " " << x;
    std::cout << "\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
