// Persistent treap split/merge — path copying versions
#include <iostream>
#include <random>
#include <vector>

struct Node {
    int key, pri, L = -1, R = -1;
};
std::vector<Node> T;
std::mt19937 rng{42};

int neo(int key) {
    T.push_back({key, (int)rng(), -1, -1});
    return (int)T.size() - 1;
}
int copy_node(int v) {
    T.push_back(T[v]);
    return (int)T.size() - 1;
}

int merge(int a, int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (T[a].pri < T[b].pri) {
        int v = copy_node(a);
        T[v].R = merge(T[v].R, b);
        return v;
    } else {
        int v = copy_node(b);
        T[v].L = merge(a, T[v].L);
        return v;
    }
}

void split(int v, int key, int& a, int& b) {
    if (v == -1) {
        a = b = -1;
        return;
    }
    v = copy_node(v);
    if (T[v].key < key) {
        split(T[v].R, key, T[v].R, b);
        a = v;
    } else {
        split(T[v].L, key, a, T[v].L);
        b = v;
    }
}

int insert(int root, int key) {
    int a, b;
    split(root, key, a, b);
    return merge(merge(a, neo(key)), b);
}

bool find(int v, int key) {
    while (v != -1) {
        if (T[v].key == key)
            return true;
        v = key < T[v].key ? T[v].L : T[v].R;
    }
    return false;
}

int main() {
    int v0 = -1;
    int v1 = insert(v0, 1);
    int v2 = insert(v1, 2);
    int v3 = insert(v2, 3);
    std::cout << std::boolalpha;
    std::cout << "v2 has 3? " << find(v2, 3) << " (expected false)\n";
    std::cout << "v3 has 3? " << find(v3, 3) << " (expected true)\n";
    std::cout << "v1 has 1? " << find(v1, 1) << " (expected true)\n";
    return 0;
}
