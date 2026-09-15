// Remove Duplicate Letters — https://leetcode.com/problems/remove-duplicate-letters/
// Smallest lexicographical subsequence with each distinct letter once.
#include <iostream>
#include <string>
#include <vector>

std::string removeDuplicateLetters(const std::string& s) {
    std::vector<int> last(26, -1);
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        last[static_cast<size_t>(s[static_cast<size_t>(i)] - 'a')] = i;
    }
    std::vector<char> st;
    std::vector<bool> in_stack(26, false);
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        const char c = s[static_cast<size_t>(i)];
        const int ci = c - 'a';
        if (in_stack[static_cast<size_t>(ci)]) {
            continue;
        }
        while (!st.empty() && st.back() > c &&
               last[static_cast<size_t>(st.back() - 'a')] > i) {
            in_stack[static_cast<size_t>(st.back() - 'a')] = false;
            st.pop_back();
        }
        st.push_back(c);
        in_stack[static_cast<size_t>(ci)] = true;
    }
    return std::string(st.begin(), st.end());
}

int main() {
    std::cout << removeDuplicateLetters("bcabc") << " (expected abc)\n";
    std::cout << removeDuplicateLetters("cbacdcbc") << " (expected acdb)\n";
    return 0;
}
