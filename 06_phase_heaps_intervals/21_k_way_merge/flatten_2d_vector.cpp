// Flatten 2D Vector — https://leetcode.com/problems/flatten-2d-vector/ (premium)
// Iterator over vector<vector<int>> skipping empties (multi-pointer).
#include <iostream>
#include <vector>

class Vector2D {
    const std::vector<std::vector<int>>* data;
    size_t r = 0, c = 0;

    void advanceToNext() {
        while (r < data->size() && c >= (*data)[r].size()) {
            ++r;
            c = 0;
        }
    }

public:
    explicit Vector2D(std::vector<std::vector<int>>& vec) : data(&vec) { advanceToNext(); }

    int next() {
        int val = (*data)[r][c++];
        advanceToNext();
        return val;
    }

    bool hasNext() { return r < data->size(); }
};

int main() {
    std::vector<std::vector<int>> vec = {{1, 2}, {}, {3}, {4, 5}};
    Vector2D it(vec);
    while (it.hasNext()) std::cout << it.next() << " ";
    std::cout << "(expected 1 2 3 4 5)\n";
    return 0;
}
