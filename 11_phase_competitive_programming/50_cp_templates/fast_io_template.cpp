// Fast IO template — untie streams; demo sum of n ints
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::vector<int> a = {3, 1, 4, 1, 5};
    const long long sum = std::accumulate(a.begin(), a.end(), 0LL);
    std::cout << "sum=" << sum << " expected=14\n";
    std::cout << (sum == 14 ? "OK\n" : "FAIL\n");
    return sum == 14 ? 0 : 1;
}
