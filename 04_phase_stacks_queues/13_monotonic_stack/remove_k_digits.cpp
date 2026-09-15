// Remove K Digits — https://leetcode.com/problems/remove-k-digits/
// Remove k digits to form the smallest possible integer (as string, no leading zeros).
#include <iostream>
#include <string>

std::string removeKdigits(const std::string& num, int k) {
    std::string st;
    for (char c : num) {
        while (k > 0 && !st.empty() && st.back() > c) {
            st.pop_back();
            --k;
        }
        st.push_back(c);
    }
    while (k > 0 && !st.empty()) {
        st.pop_back();
        --k;
    }
    // strip leading zeros
    std::size_t i = 0;
    while (i < st.size() && st[i] == '0') {
        ++i;
    }
    const std::string ans = st.substr(i);
    return ans.empty() ? "0" : ans;
}

int main() {
    std::cout << removeKdigits("1432219", 3) << " (expected 1219)\n";
    std::cout << removeKdigits("10200", 1) << " (expected 200)\n";
    std::cout << removeKdigits("10", 2) << " (expected 0)\n";
    return 0;
}
