// Jump Game III — https://leetcode.com/problems/jump-game-iii/
// From start index, jump ±arr[i]; return true if can reach a 0.
#include <iostream>
#include <queue>
#include <vector>

bool canReach(std::vector<int> arr, int start) {
    const int n = static_cast<int>(arr.size());
    std::queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (arr[static_cast<size_t>(i)] == 0)
            return true;
        if (arr[static_cast<size_t>(i)] < 0)
            continue; // visited marker
        int jump = arr[static_cast<size_t>(i)];
        arr[static_cast<size_t>(i)] = -1;
        if (i + jump < n)
            q.push(i + jump);
        if (i - jump >= 0)
            q.push(i - jump);
    }
    return false;
}

int main() {
    std::cout << std::boolalpha << canReach({4, 2, 3, 0, 3, 1, 2}, 5) << " (expected true)\n";
    std::cout << canReach({4, 2, 3, 0, 3, 1, 2}, 0) << " (expected true)\n";
    return 0;
}
