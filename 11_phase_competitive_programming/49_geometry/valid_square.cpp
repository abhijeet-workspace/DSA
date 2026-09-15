// LC593 Valid Square
#include <algorithm>
#include <iostream>
#include <vector>

long long dist2(const std::vector<int>& a, const std::vector<int>& b) {
    long long dx = a[0] - b[0], dy = a[1] - b[1];
    return dx * dx + dy * dy;
}

bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3,
                 std::vector<int>& p4) {
    std::vector<std::vector<int>> p = {p1, p2, p3, p4};
    std::vector<long long> d;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            d.push_back(dist2(p[i], p[j]));
    std::sort(d.begin(), d.end());
    if (d[0] == 0)
        return false;
    return d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5] && d[4] > d[0];
}

int main() {
    std::vector<int> a{0, 0}, b{1, 1}, c{1, 0}, d{0, 1};
    std::cout << std::boolalpha;
    std::cout << "validSquare=" << validSquare(a, b, c, d) << " (expected true)\n";
    return 0;
}
