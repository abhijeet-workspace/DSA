// LC1232 Check If It Is a Straight Line
#include <iostream>
#include <vector>

bool checkStraightLine(std::vector<std::vector<int>>& c) {
    int n = static_cast<int>(c.size());
    long long dx = c[1][0] - c[0][0];
    long long dy = c[1][1] - c[0][1];
    for (int i = 2; i < n; ++i) {
        long long dx2 = c[i][0] - c[0][0];
        long long dy2 = c[i][1] - c[0][1];
        if (dx * dy2 - dy * dx2 != 0)
            return false;
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    std::vector<std::vector<int>> b = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    std::cout << std::boolalpha;
    std::cout << "line A=" << checkStraightLine(a) << " (expected true)\n";
    std::cout << "line B=" << checkStraightLine(b) << " (expected false)\n";
    return 0;
}
