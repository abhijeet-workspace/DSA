// Online Stock Span — https://leetcode.com/problems/online-stock-span/
// On each price, return consecutive days (including today) with price <= today's.
#include <iostream>
#include <stack>
#include <utility>

class StockSpanner {
  public:
    int next(int price) {
        int span = 1;
        while (!st_.empty() && st_.top().first <= price) {
            span += st_.top().second;
            st_.pop();
        }
        st_.push({price, span});
        return span;
    }

  private:
    std::stack<std::pair<int, int>> st_; // {price, span}, decreasing prices
};

int main() {
    StockSpanner sp;
    const int prices[] = {100, 80, 60, 70, 60, 75, 85};
    const int expected[] = {1, 1, 1, 2, 1, 4, 6};
    std::cout << "Spans:";
    for (int i = 0; i < 7; ++i) {
        const int got = sp.next(prices[i]);
        std::cout << ' ' << got;
        if (got != expected[i]) {
            std::cout << "\nMismatch at day " << i << " expected " << expected[i] << '\n';
            return 1;
        }
    }
    std::cout << " (expected 1 1 1 2 1 4 6)\n";
    return 0;
}
