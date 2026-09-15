// Insert Delete GetRandom O(1) — https://leetcode.com/problems/insert-delete-getrandom-o1/
// Support insert/remove/getRandom each in average O(1).
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

class RandomizedSet {
    std::vector<int> vals_;
    std::unordered_map<int, int> idx_; // value -> index in vals_

  public:
    bool insert(int val) {
        if (idx_.count(val))
            return false;
        idx_[val] = static_cast<int>(vals_.size());
        vals_.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = idx_.find(val);
        if (it == idx_.end())
            return false;
        const int i = it->second;
        const int last = vals_.back();
        vals_[static_cast<size_t>(i)] = last;
        idx_[last] = i;
        vals_.pop_back();
        idx_.erase(it);
        return true;
    }

    int getRandom() const {
        return vals_[static_cast<size_t>(std::rand() % static_cast<int>(vals_.size()))];
    }
};

int main() {
    RandomizedSet s;
    std::cout << s.insert(1) << " (expected 1)\n";
    std::cout << s.remove(2) << " (expected 0)\n";
    std::cout << s.insert(2) << " (expected 1)\n";
    std::cout << "random: " << s.getRandom() << " (1 or 2)\n";
    std::cout << s.remove(1) << " (expected 1)\n";
    std::cout << s.insert(2) << " (expected 0)\n";
    std::cout << s.getRandom() << " (expected 2)\n";
    return 0;
}
