// Persistent list lab — cons/tail with sharing
#include <iostream>
#include <vector>

struct Node {
    int val;
    int next;
};
std::vector<Node> L = {{-1, -1}}; // 0 = nil

int cons(int head, int x) {
    L.push_back({x, head});
    return (int)L.size() - 1;
}
int tail(int head) {
    return head ? L[head].next : 0;
}
int nth(int head, int i) {
    while (head && i--)
        head = L[head].next;
    return head ? L[head].val : -1;
}

int main() {
    int v0 = 0;
    int v1 = cons(v0, 1);
    int v2 = cons(v1, 2);
    std::cout << "nth v2 0=" << nth(v2, 0) << " (expected 2)\n";
    std::cout << "nth v2 1=" << nth(v2, 1) << " (expected 1)\n";
    std::cout << "nth v1 0=" << nth(v1, 0) << " (expected 1)\n";
    return 0;
}
