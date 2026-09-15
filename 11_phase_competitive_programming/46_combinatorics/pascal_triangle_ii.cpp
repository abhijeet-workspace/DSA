// Pascal's Triangle II — LC 119
#include <iostream>
#include <vector>
std::vector<int> getRow(int rowIndex) {
    std::vector<int> row(rowIndex + 1, 0);
    row[0] = 1;
    for (int i = 1; i <= rowIndex; ++i)
        for (int j = i; j >= 1; --j)
            row[j] += row[j - 1];
    return row;
}
int main() {
    auto r = getRow(3);
    std::cout << r[0] << r[1] << r[2] << r[3] << " (expected 1331)\n";
    return 0;
}
