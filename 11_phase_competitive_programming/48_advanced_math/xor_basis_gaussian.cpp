#include <iostream>
#include <vector>
struct XorBasis {
    std::vector<int> b;
    XorBasis(int bits = 31) : b(bits, 0) {}
    void insert(int x) {
        for (int i = (int)b.size() - 1; i >= 0; --i) {
            if (((x >> i) & 1) == 0)
                continue;
            if (!b[i]) {
                b[i] = x;
                return;
            }
            x ^= b[i];
        }
    }
    int maxXor() {
        int ans = 0;
        for (int i = (int)b.size() - 1; i >= 0; --i)
            ans = std::max(ans, ans ^ b[i]);
        return ans;
    }
};
int main() {
    XorBasis xb;
    for (int x : {1, 2, 4, 7})
        xb.insert(x);
    std::cout << xb.maxXor() << " (expected 7)\n";
}