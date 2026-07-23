// Valid Parentheses — https://leetcode.com/problems/valid-parentheses/
// Return true if (), {}, [] are correctly ordered and nested.
#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
            continue;
        }
        if (st.empty()) {
            return false;
        }
        const char top = st.top();
        st.pop();
        if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
            (c == ']' && top != '[')) {
            return false;
        }
    }
    return st.empty();
}

int main() {
    std::cout << std::boolalpha
              << isValid("()[]{}") << " (expected true)\n"
              << isValid("(]") << " (expected false)\n"
              << isValid("({[]})") << " (expected true)\n";
    return 0;
}
