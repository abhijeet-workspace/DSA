// MinHash lab — simplified Jaccard estimate
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<size_t> signature(const std::unordered_set<std::string>& S, int k) {
    std::vector<size_t> sig(k, SIZE_MAX);
    for (int i = 0; i < k; ++i) {
        for (const auto& s : S) {
            size_t h = std::hash<std::string>{}(s + "#" + std::to_string(i));
            sig[i] = std::min(sig[i], h);
        }
    }
    return sig;
}

double exactJ(const std::unordered_set<std::string>& A, const std::unordered_set<std::string>& B) {
    int inter = 0;
    for (auto& x : A)
        if (B.count(x))
            ++inter;
    int uni = (int)A.size() + (int)B.size() - inter;
    return uni ? double(inter) / uni : 1.0;
}

int main() {
    std::unordered_set<std::string> A = {"a", "b", "c", "d"};
    std::unordered_set<std::string> B = {"c", "d", "e"};
    int k = 64;
    auto sa = signature(A, k), sb = signature(B, k);
    int match = 0;
    for (int i = 0; i < k; ++i)
        if (sa[i] == sb[i])
            ++match;
    std::cout << "est=" << double(match) / k << " exact=" << exactJ(A, B) << "\n";
    return 0;
}
