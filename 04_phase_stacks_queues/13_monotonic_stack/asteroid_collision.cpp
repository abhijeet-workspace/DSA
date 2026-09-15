// Asteroid Collision — https://leetcode.com/problems/asteroid-collision/
// Positive = right, negative = left. Same-direction never collide; opposite may.
#include <iostream>
#include <vector>

std::vector<int> asteroidCollision(const std::vector<int>& asteroids) {
    std::vector<int> st;
    for (int a : asteroids) {
        bool alive = true;
        while (alive && !st.empty() && st.back() > 0 && a < 0) {
            if (st.back() < -a) {
                st.pop_back();
                continue;
            }
            if (st.back() == -a) {
                st.pop_back();
            }
            alive = false;
        }
        if (alive) {
            st.push_back(a);
        }
    }
    return st;
}

int main() {
    const auto res = asteroidCollision({5, 10, -5});
    std::cout << "Survivors:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 5 10)\n";

    const auto res2 = asteroidCollision({8, -8});
    std::cout << "Equal clash size: " << res2.size() << " (expected 0)\n";
    return 0;
}
