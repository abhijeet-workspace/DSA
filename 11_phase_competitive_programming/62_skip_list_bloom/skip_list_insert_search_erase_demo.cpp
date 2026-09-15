// Skip list insert/search/erase demo
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
    std::mt19937 rng{7};

    int randomHeight() {
        int h = 1;
        while (h < MAXL && (rng() & 1))
            ++h;
        return h;
    }
    bool contains(int key) const {
        Node* cur = head;
        for (int lvl = MAXL - 1; lvl >= 0; --lvl)
            while (cur->next[lvl] && cur->next[lvl]->key < key)
                cur = cur->next[lvl];
        cur = cur->next[0];
        return cur && cur->key == key;
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
    void erase(int key) {
        std::vector<Node*> upd(MAXL, head);
        Node* cur = head;
        for (int lvl = MAXL - 1; lvl >= 0; --lvl) {
            while (cur->next[lvl] && cur->next[lvl]->key < key)
                cur = cur->next[lvl];
            upd[lvl] = cur;
        }
        Node* victim = cur->next[0];
        if (!victim || victim->key != key)
            return;
        for (int lvl = 0; lvl < (int)victim->next.size(); ++lvl)
            if (upd[lvl]->next[lvl] == victim)
                upd[lvl]->next[lvl] = victim->next[lvl];
        delete victim;
    }
};

int main() {
    SkipList sl;
    sl.insert(3);
    sl.insert(1);
    sl.insert(2);
    sl.erase(1);
    std::cout << std::boolalpha;
    std::cout << "has1=" << sl.contains(1) << " has2=" << sl.contains(2)
              << " (expected false true)\n";
    return 0;
}
