// Insert Delete GetRandom O(1) — LC 380
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

struct RandomizedSet {
    std::vector<int> a;
    std::unordered_map<int, int> pos;
    bool insert(int val) {
        if (pos.count(val))
            return false;
        pos[val] = (int)a.size();
        a.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!pos.count(val))
            return false;
        int i = pos[val];
        int last = a.back();
        a[i] = last;
        pos[last] = i;
        a.pop_back();
        pos.erase(val);
        return true;
    }
    int getRandom() { return a[std::rand() % a.size()]; }
};

int main() {
    std::srand(1);
    RandomizedSet s;
    s.insert(1);
    s.insert(2);
    s.remove(1);
    std::cout << "rand=" << s.getRandom() << " (expected 2)\n";
    return 0;
}
