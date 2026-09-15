// Pascal's Triangle — LC 118
#include <iostream>
#include <vector>
std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> a(numRows);
    for (int i = 0; i < numRows; ++i) {
        a[i].assign(i + 1, 1);
        for (int j = 1; j < i; ++j)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
    return a;
}
int main() {
    auto g = generate(5);
    std::cout << g[4][2] << " (expected 6)\n";
    return 0;
}
