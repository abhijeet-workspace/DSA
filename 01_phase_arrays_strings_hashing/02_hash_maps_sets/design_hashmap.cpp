// Design HashMap — https://leetcode.com/problems/design-hashmap/
// Put / get / remove without using built-in map libraries (array of chains).
#include <iostream>
#include <list>
#include <utility>
#include <vector>

class MyHashMap {
    static constexpr int BUCKETS = 1009;
    std::vector<std::list<std::pair<int, int>>> buckets_;

    int hash(int key) const { return key % BUCKETS; }

  public:
    MyHashMap() : buckets_(BUCKETS) {}

    void put(int key, int value) {
        auto& bucket = buckets_[static_cast<size_t>(hash(key))];
        for (auto& p : bucket) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        bucket.emplace_back(key, value);
    }

    int get(int key) {
        const auto& bucket = buckets_[static_cast<size_t>(hash(key))];
        for (const auto& p : bucket) {
            if (p.first == key)
                return p.second;
        }
        return -1;
    }

    void remove(int key) {
        auto& bucket = buckets_[static_cast<size_t>(hash(key))];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap m;
    m.put(1, 1);
    m.put(2, 2);
    std::cout << m.get(1) << " (expected 1)\n";
    std::cout << m.get(3) << " (expected -1)\n";
    m.put(2, 1);
    std::cout << m.get(2) << " (expected 1)\n";
    m.remove(2);
    std::cout << m.get(2) << " (expected -1)\n";
    return 0;
}
