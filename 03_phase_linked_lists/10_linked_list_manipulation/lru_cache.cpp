// LRU Cache — https://leetcode.com/problems/lru-cache/
// O(1) get/put cache that evicts least recently used keys.
#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity_;
    std::unordered_map<int, Node*> map_;
    Node* head_; // MRU side sentinel
    Node* tail_; // LRU side sentinel

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head_->next;
        node->next->prev = node;
        head_->next = node;
        node->prev = head_;
    }

public:
    explicit LRUCache(int capacity) : capacity_(capacity) {
        head_ = new Node(-1, -1);
        tail_ = new Node(-1, -1);
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        Node* curr = head_;
        while (curr) {
            Node* tmp = curr->next;
            delete curr;
            curr = tmp;
        }
    }

    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end()) {
            return -1;
        }
        Node* node = it->second;
        remove(node); // detach
        insertAtHead(node); // mark most recent
        return node->value;
    }

    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            Node* node = it->second;
            node->value = value;
            remove(node);
            insertAtHead(node);
            return;
        }
        if (static_cast<int>(map_.size()) == capacity_) {
            Node* lru = tail_->prev; // least recent
            remove(lru);
            map_.erase(lru->key);
            delete lru;
        }
        Node* node = new Node(key, value);
        map_[key] = node;
        insertAtHead(node);
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << "get 1: " << lru.get(1) << " (expected 1)\n";
    lru.put(3, 3); // evicts 2
    std::cout << "get 2: " << lru.get(2) << " (expected -1)\n";
    lru.put(4, 4); // evicts 1
    std::cout << "get 1: " << lru.get(1) << " (expected -1)\n";
    std::cout << "get 3: " << lru.get(3) << " (expected 3)\n";
    std::cout << "get 4: " << lru.get(4) << " (expected 4)\n";
    return 0;
}
