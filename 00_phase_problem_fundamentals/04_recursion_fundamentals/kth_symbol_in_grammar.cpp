// K-th Symbol in Grammar — LC 779
#include <iostream>

int kthGrammar(int n, int k) {
    if (n == 1) return 0;
    int parent = kthGrammar(n - 1, (k + 1) / 2);
    // parent 0 → children 0,1 ; parent 1 → children 1,0
    bool leftChild = (k % 2 == 1);
    if (parent == 0) return leftChild ? 0 : 1;
    return leftChild ? 1 : 0;
}

int main() {
    std::cout << kthGrammar(1, 1) << " (expected 0)\n";
    std::cout << kthGrammar(2, 1) << " (expected 0)\n";
    std::cout << kthGrammar(2, 2) << " (expected 1)\n";
    std::cout << kthGrammar(3, 3) << " (expected 1)\n";
    return 0;
}
