// Queue Reconstruction by Height — https://leetcode.com/problems/queue-reconstruction-by-height/
// Sort tallest first; insert each person at index k among taller/equal.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> people) {
    std::sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
        if (a[0] != b[0]) return a[0] > b[0]; // taller first
        return a[1] < b[1];                    // same height: smaller k first
    });
    std::vector<std::vector<int>> queue;
    queue.reserve(people.size());
    for (const auto& p : people) {
        queue.insert(queue.begin() + p[1], p); // k = # taller-or-equal already ahead
    }
    return queue;
}

int main() {
    const auto q1 = reconstructQueue({{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}});
    std::cout << "[";
    for (size_t i = 0; i < q1.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << "[" << q1[i][0] << ", " << q1[i][1] << "]";
    }
    std::cout << "] (expected [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]])\n";

    const auto q2 = reconstructQueue({{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}});
    std::cout << "[";
    for (size_t i = 0; i < q2.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << "[" << q2[i][0] << ", " << q2[i][1] << "]";
    }
    std::cout << "] (expected [[4, 0], [5, 0], [2, 2], [3, 2], [1, 4], [6, 0]])\n";
    return 0;
}
