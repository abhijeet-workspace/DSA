// Skip list range query
#include <iostream>
#include <limits>
#include <random>
#include <vector>

struct SkipList {
    static constexpr int MAXL = 8;
    struct Node {
        int key;
        std::vector<Node*> next;
        Node(int k, int h) : key(k), next(h, nullptr) {}
    };
    Node* head = new Node(std::numeric_limits<int>::min(), MAXL);
    std::mt19937 rng{3};
    int randomHeight() {
        int h = 1;
        while (h < MAXL && (rng() & 1))
            ++h;
        return h;
    }
    void insert(int key) {
        std::vector<Node*> upd(MAXL, head);
        Node* cur = head;
        for (int lvl = MAXL - 1; lvl >= 0; --lvl) {
            while (cur->next[lvl] && cur->next[lvl]->key < key)
                cur = cur->next[lvl];
            upd[lvl] = cur;
        }
        if (cur->next[0] && cur->next[0]->key == key)
            return;
        int h = randomHeight();
        Node* n = new Node(key, h);
        for (int lvl = 0; lvl < h; ++lvl) {
            n->next[lvl] = upd[lvl]->next[lvl];
            upd[lvl]->next[lvl] = n;
        }
    }
    std::vector<int> range(int L, int R) const {
        Node* cur = head;
        for (int lvl = MAXL - 1; lvl >= 0; --lvl)
            while (cur->next[lvl] && cur->next[lvl]->key < L)
                cur = cur->next[lvl];
        cur = cur->next[0];
        std::vector<int> out;
        while (cur && cur->key <= R) {
            out.push_back(cur->key);
            cur = cur->next[0];
        }
        return out;
    }
};

int main() {
    SkipList sl;
    for (int x : {1, 2, 3, 4, 5})
        sl.insert(x);
    for (int x : sl.range(2, 4))
        std::cout << x << " ";
    std::cout << "(expected 2 3 4)\n";
    return 0;
}
