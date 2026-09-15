#include <iostream>
#include <vector>
std::vector<char> wins(int n, const std::vector<int>& S) {
    std::vector<char> w(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int s : S)
            if (s <= i && !w[i - s]) {
                w[i] = 1;
                break;
            }
    return w;
}
int main() {
    auto w = wins(10, {1, 2});
    std::cout << "win:";
    for (int i = 0; i <= 10; ++i)
        std::cout << " " << int(w[i]);
    std::cout << " (lose iff i%3==0)\n";
    return 0;
}
