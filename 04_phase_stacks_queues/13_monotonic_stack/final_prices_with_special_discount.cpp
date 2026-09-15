// Final Prices With a Special Discount —
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/ Discount = next
// smaller-or-equal price to the right (0 if none).
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> finalPrices(std::vector<int> prices) {
    const int n = static_cast<int>(prices.size());
    std::stack<int> st; // indices, increasing prices (next smaller-or-equal)
    for (int i = 0; i < n; ++i) {
        while (!st.empty() &&
               prices[static_cast<size_t>(st.top())] >= prices[static_cast<size_t>(i)]) {
            prices[static_cast<size_t>(st.top())] -= prices[static_cast<size_t>(i)];
            st.pop();
        }
        st.push(i);
    }
    return prices;
}

int main() {
    const auto res = finalPrices({8, 4, 6, 2, 3});
    std::cout << "Final prices:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 4 2 4 2 3)\n";
    return 0;
}
