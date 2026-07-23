// Skip list lab — insert + contains
// Random tower heights give expected O(log N) search.
#include <iostream>
#include <limits>
#include <random>
#include <vector>

struct SkipList {
    static constexpr int MAXL = 8;

    struct Node {
        int key;
        std::vector<Node*> next;
        explicit Node(int k, int h) : key(k), next(static_cast<size_t>(h), nullptr) {}
    };

    Node* head = new Node(std::numeric_limits<int>::min(), MAXL);
    std::mt19937 rng{42};

    int randomHeight() {
        int h = 1;
        while (h < MAXL && (rng() & 1)) {
            ++h;
        }
        return h;
    }

    bool contains(int key) const {
        Node* cur = head;
        for (int lvl = MAXL - 1; lvl >= 0; --lvl) {
            while (cur->next[static_cast<size_t>(lvl)] &&
                   cur->next[static_cast<size_t>(lvl)]->key < key) {
                cur = cur->next[static_cast<size_t>(lvl)];
            }
        }
        cur = cur->next[0];
        return cur && cur->key == key;
    }

    void insert(int key) {
        std::vector<Node*> update(static_cast<size_t>(MAXL), head);
        Node* cur = head;
        for (int lvl = MAXL - 1; lvl >= 0; --lvl) {
            while (cur->next[static_cast<size_t>(lvl)] &&
                   cur->next[static_cast<size_t>(lvl)]->key < key) {
                cur = cur->next[static_cast<size_t>(lvl)];
            }
            update[static_cast<size_t>(lvl)] = cur;
        }
        if (cur->next[0] && cur->next[0]->key == key) {
            return; // duplicate
        }
        const int h = randomHeight();
        Node* n = new Node(key, h);
        for (int lvl = 0; lvl < h; ++lvl) {
            n->next[static_cast<size_t>(lvl)] =
                update[static_cast<size_t>(lvl)]->next[static_cast<size_t>(lvl)];
            update[static_cast<size_t>(lvl)]->next[static_cast<size_t>(lvl)] = n;
        }
    }
};

int main() {
    SkipList sl;
    sl.insert(1);
    sl.insert(3);
    sl.insert(7);
    std::cout << std::boolalpha << sl.contains(3) << " (expected true)\n"
              << sl.contains(2) << " (expected false)\n";
    return 0;
}
