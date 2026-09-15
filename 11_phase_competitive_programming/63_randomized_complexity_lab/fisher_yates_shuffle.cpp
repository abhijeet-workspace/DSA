// Fisher-Yates shuffle
#include <iostream>
#include <random>
#include <vector>

void shuffle(std::vector<int>& a, std::mt19937& rng) {
    for (int i = (int)a.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        std::swap(a[i], a[dist(rng)]);
    }
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::mt19937 rng{42};
    shuffle(a, rng);
    for (int x : a)
        std::cout << x << " ";
    std::cout << "(permutation of 1..4)\n";
    return 0;
}
