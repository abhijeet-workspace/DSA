// Keys and Rooms — https://leetcode.com/problems/keys-and-rooms/
// rooms[i] holds keys; start in room 0; can you visit all rooms?
#include <iostream>
#include <queue>
#include <vector>

bool canVisitAllRooms(const std::vector<std::vector<int>>& rooms) {
    const int n = static_cast<int>(rooms.size());
    std::vector<char> vis(static_cast<size_t>(n), 0);
    std::queue<int> q;
    q.push(0);
    vis[0] = 1;
    int seen = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int k : rooms[static_cast<size_t>(u)]) {
            if (!vis[static_cast<size_t>(k)]) {
                vis[static_cast<size_t>(k)] = 1;
                ++seen;
                q.push(k);
            }
        }
    }
    return seen == n;
}

int main() {
    std::cout << std::boolalpha
              << canVisitAllRooms({{1}, {2}, {3}, {}}) << " (expected true)\n";
    std::cout << canVisitAllRooms({{1, 3}, {3, 0, 1}, {2}, {0}}) << " (expected false)\n";
    return 0;
}
