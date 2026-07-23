// Treap insert / find / erase — CP classic
// BST by key, heap by random priority; split + merge.
#include <iostream>
#include <random>

struct Treap {
    struct Node {
        int key;
        int prio;
        Node* L = nullptr;
        Node* R = nullptr;
        Node(int k, int p) : key(k), prio(p) {}
    };

    Node* root = nullptr;
    std::mt19937 rng{123};

    int rp() { return std::uniform_int_distribution<int>()(rng); }

    void split(Node* t, int key, Node*& a, Node*& b) {
        if (!t) {
            a = b = nullptr;
            return;
        }
        if (t->key < key) {
            split(t->R, key, t->R, b);
            a = t;
        } else {
            split(t->L, key, a, t->L);
            b = t;
        }
    }

    Node* merge(Node* a, Node* b) {
        if (!a || !b) {
            return a ? a : b;
        }
        if (a->prio < b->prio) {
            a->R = merge(a->R, b);
            return a;
        }
        b->L = merge(a, b->L);
        return b;
    }

    void insert(int key) {
        Node *a = nullptr, *b = nullptr;
        split(root, key, a, b);
        root = merge(merge(a, new Node(key, rp())), b);
    }

    bool find(int key) const {
        for (Node* t = root; t;) {
            if (key == t->key) {
                return true;
            }
            t = key < t->key ? t->L : t->R;
        }
        return false;
    }

    void erase(int key) {
        Node *a = nullptr, *b = nullptr, *c = nullptr;
        split(root, key, a, b);
        split(b, key + 1, b, c); // isolate key in b (lab: leak node)
        root = merge(a, c);
    }
};

int main() {
    Treap tr;
    tr.insert(2);
    tr.insert(1);
    tr.insert(3);
    std::cout << std::boolalpha << tr.find(1) << " (expected true)\n";
    tr.erase(2);
    std::cout << tr.find(2) << " (expected false)\n";
    return 0;
}
