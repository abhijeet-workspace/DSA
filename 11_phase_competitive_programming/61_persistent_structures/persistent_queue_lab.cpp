// Persistent queue lab — two persistent stacks (simplified)
#include <iostream>
#include <vector>

struct SNode {
    int val;
    int prev;
};
std::vector<SNode> SP = {{-1, -1}};

int spush(int ver, int x) {
    SP.push_back({x, ver});
    return (int)SP.size() - 1;
}
int spop(int ver) {
    return ver ? SP[ver].prev : 0;
}
int stop(int ver) {
    return ver ? SP[ver].val : -1;
}

struct QVer {
    int front, back;
};
std::vector<QVer> Q = {{0, 0}};

int reverse_to_front(int front, int back) {
    while (back) {
        front = spush(front, stop(back));
        back = spop(back);
    }
    return front;
}

int enq(int qid, int x) {
    auto [f, b] = Q[qid];
    b = spush(b, x);
    Q.push_back({f, b});
    return (int)Q.size() - 1;
}

int deq(int qid) {
    auto [f, b] = Q[qid];
    if (!f)
        f = reverse_to_front(f, b), b = 0;
    if (!f) {
        Q.push_back({0, 0});
        return (int)Q.size() - 1;
    }
    f = spop(f);
    Q.push_back({f, b});
    return (int)Q.size() - 1;
}

int front(int qid) {
    auto [f, b] = Q[qid];
    if (!f) {
        // peek without committing version: local reverse
        std::vector<int> tmp;
        int bb = b;
        while (bb) {
            tmp.push_back(stop(bb));
            bb = spop(bb);
        }
        return tmp.empty() ? -1 : tmp.back();
    }
    return stop(f);
}

int main() {
    int q0 = 0;
    int q1 = enq(q0, 1);
    int q2 = enq(q1, 2);
    int q3 = deq(q2);
    std::cout << "front q2=" << front(q2) << " (expected 1)\n";
    std::cout << "front q3=" << front(q3) << " (expected 2)\n";
    return 0;
}
