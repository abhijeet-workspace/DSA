// Impartial games — Nim XOR + Sprague-Grundy (subtraction game)
// Nim O(piles); Grundy O(n · |moves|) with memo
#include <iostream>
#include <unordered_set>
#include <vector>

bool first_wins_nim(const std::vector<int>& piles) {
    int x = 0;
    for (int p : piles) x ^= p;
    return x != 0; // nonzero xor → N-position
}

int mex(const std::unordered_set<int>& s) {
    int m = 0;
    while (s.count(m)) ++m;
    return m;
}

// Subtraction game: remove a move from `moves` if pile >= move
int grundy(int n, const std::vector<int>& moves, std::vector<int>& memo) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    std::unordered_set<int> reach;
    for (int mv : moves) {
        if (n >= mv) reach.insert(grundy(n - mv, moves, memo));
    }
    return memo[n] = mex(reach);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "Nim {3,4,5} first wins? "
              << (first_wins_nim({3, 4, 5}) ? "YES" : "NO") << " (expected YES)\n";
    std::cout << "Nim {1,2,3} first wins? "
              << (first_wins_nim({1, 2, 3}) ? "YES" : "NO") << " (expected NO)\n";

    std::vector<int> moves = {1, 3, 4};
    std::vector<int> memo(11, -1);
    std::cout << "Grundy subtraction {1,3,4}:";
    for (int i = 0; i <= 10; ++i) std::cout << " " << grundy(i, moves, memo);
    std::cout << "\n";
    return 0;
}
