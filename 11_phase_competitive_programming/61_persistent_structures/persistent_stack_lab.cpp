// Persistent stack lab — versions as linked nodes
#include <iostream>
#include <vector>

struct Node {
    int val;
    int prev;
};
std::vector<Node> pool = {{-1, -1}}; // index 0 = empty sentinel

int push(int ver, int x) {
    pool.push_back({x, ver});
    return (int)pool.size() - 1;
}
int pop(int ver) {
    if (ver == 0)
        return 0;
    return pool[ver].prev;
}
int top(int ver) {
    return ver == 0 ? -1 : pool[ver].val;
}

int main() {
    int v0 = 0;
    int v1 = push(v0, 1);
    int v2 = push(v1, 2);
    int v3 = pop(v2);
    std::cout << "top v2=" << top(v2) << " (expected 2)\n";
    std::cout << "top v3=" << top(v3) << " (expected 1)\n";
    std::cout << "top v1=" << top(v1) << " (expected 1)\n";
    return 0;
}
