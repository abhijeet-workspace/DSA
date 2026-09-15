// Spiral Matrix II — LC 59
// Fill 1..n^2 into an n x n matrix in spiral order.
#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> a(static_cast<size_t>(n),
                                    std::vector<int>(static_cast<size_t>(n), 0));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int val = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j)
            a[static_cast<size_t>(top)][static_cast<size_t>(j)] = val++;
        ++top;
        for (int i = top; i <= bottom; ++i)
            a[static_cast<size_t>(i)][static_cast<size_t>(right)] = val++;
        --right;
        if (top <= bottom) {
            for (int j = right; j >= left; --j)
                a[static_cast<size_t>(bottom)][static_cast<size_t>(j)] = val++;
            --bottom;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                a[static_cast<size_t>(i)][static_cast<size_t>(left)] = val++;
            ++left;
        }
    }
    return a;
}

int main() {
    auto a = generateMatrix(3);
    for (const auto& row : a) {
        for (int x : row)
            std::cout << x << " ";
        std::cout << "\n";
    }
    // expected:
    // 1 2 3
    // 8 9 4
    // 7 6 5
    return 0;
}
