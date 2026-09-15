// Random Pick Index — LC 398
#include <cstdlib>
#include <iostream>
#include <vector>

struct Solution {
    std::vector<int> a;
    explicit Solution(std::vector<int> nums) : a(std::move(nums)) {}
    int pick(int target) {
        int ans = -1, cnt = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != target)
                continue;
            ++cnt;
            if (std::rand() % cnt == 0)
                ans = i;
        }
        return ans;
    }
};

int main() {
    std::srand(3);
    Solution s({1, 2, 3, 3, 3});
    for (int i = 0; i < 5; ++i)
        std::cout << s.pick(3) << " ";
    std::cout << "(expected indices in {2,3,4})\n";
    return 0;
}
