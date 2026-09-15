// Max Chunks To Make Sorted II — https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Duplicates allowed: stack of chunk maxima; merge left while new value is smaller.
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int maxChunksToSorted(std::vector<int>& arr) {
    std::stack<int> st;
    for (int x : arr) {
        if (st.empty() || x >= st.top()) {
            st.push(x);
        } else {
            const int mx = st.top();
            st.pop();
            while (!st.empty() && st.top() > x)
                st.pop();
            st.push(mx);
        }
    }
    return static_cast<int>(st.size());
}

int main() {
    std::vector<int> a = {2, 1, 3, 4, 4};
    std::vector<int> b = {5, 4, 3, 2, 1};
    std::vector<int> c = {1, 1, 0, 0, 1};
    std::cout << maxChunksToSorted(a) << " (expected 4)\n"
              << maxChunksToSorted(b) << " (expected 1)\n"
              << maxChunksToSorted(c) << " (expected 2)\n";
    return 0;
}
