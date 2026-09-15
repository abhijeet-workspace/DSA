// LFU Cache — https://leetcode.com/problems/lfu-cache/
// O(1) get/put cache; evict least frequently used, then least recently used among ties.
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

class LFUCache {
    int capacity_;
    int minFreq_ = 0;
    std::unordered_map<int, std::pair<int, int>> keyToValFreq_; // key -> {val, freq}
    std::unordered_map<int, std::list<int>> freqToKeys_;
    std::unordered_map<int, std::list<int>::iterator> keyIter_;

    void touch(int key) {
        int freq = keyToValFreq_[key].second;
        freqToKeys_[freq].erase(keyIter_[key]);
        if (freqToKeys_[freq].empty()) {
            freqToKeys_.erase(freq);
            if (minFreq_ == freq) {
                ++minFreq_;
            }
        }
        ++keyToValFreq_[key].second;
        freqToKeys_[freq + 1].push_front(key);
        keyIter_[key] = freqToKeys_[freq + 1].begin();
    }

public:
    explicit LFUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (!capacity_ || !keyToValFreq_.count(key)) {
            return -1;
        }
        touch(key);
        return keyToValFreq_[key].first;
    }

    void put(int key, int value) {
        if (!capacity_) {
            return;
        }
        if (keyToValFreq_.count(key)) {
            keyToValFreq_[key].first = value;
            touch(key);
            return;
        }
        if (static_cast<int>(keyToValFreq_.size()) == capacity_) {
            int evict = freqToKeys_[minFreq_].back();
            freqToKeys_[minFreq_].pop_back();
            if (freqToKeys_[minFreq_].empty()) {
                freqToKeys_.erase(minFreq_);
            }
            keyToValFreq_.erase(evict);
            keyIter_.erase(evict);
        }
        keyToValFreq_[key] = {value, 1};
        freqToKeys_[1].push_front(key);
        keyIter_[key] = freqToKeys_[1].begin();
        minFreq_ = 1;
    }
};

int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    std::cout << lfu.get(1) << " (expected 1)\n";
    lfu.put(3, 3); // evicts 2
    std::cout << lfu.get(2) << " (expected -1)\n";
    std::cout << lfu.get(3) << " (expected 3)\n";
    lfu.put(4, 4); // evicts 1
    std::cout << lfu.get(1) << " (expected -1)\n";
    std::cout << lfu.get(3) << " (expected 3)\n";
    std::cout << lfu.get(4) << " (expected 4)\n";
    return 0;
}
