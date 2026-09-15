// Debug macro template — active only under -DLOCAL
#include <iostream>
#include <vector>

#ifdef LOCAL
#define debug(x) std::cerr << #x << " = " << (x) << "\n"
#else
#define debug(x)
#endif

int main() {
    int n = 4;
    debug(n);
    std::vector<int> a = {1, 2, 3};
    long long s = 0;
    for (int x : a)
        s += x;
    std::cout << "sum=" << s << " expected=6\n";
    std::cout << (s == 6 ? "OK\n" : "FAIL\n");
    return s == 6 ? 0 : 1;
}
