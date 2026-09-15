#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
int main() {
    std::vector<int> a = {5, 1, 5, 2, 9};
    std::vector<int> v = a;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::vector<int> r1(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        r1[i] = int(std::lower_bound(v.begin(), v.end(), a[i]) - v.begin()) + 1;
    std::map<int, int> mp;
    int r = 0;
    for (int x : v)
        mp[x] = ++r;
    std::vector<int> r2(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        r2[i] = mp[a[i]];
    bool ok = r1 == r2;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
