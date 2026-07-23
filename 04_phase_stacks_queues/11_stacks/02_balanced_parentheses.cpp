// Balanced Parentheses — stack matching for (), [], {}
// Return true iff brackets are correctly nested and paired.
#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool isBalanced(const std::string& expr) {
    std::stack<char> st;
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch); // unmatched open
            continue;
        }
        if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) {
                return false; // close with no open
            }
            const char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false; // mismatch
            }
        }
    }
    return st.empty(); // leftover opens → false
}

int main() {
    const std::vector<std::string> tests = {
        "({[]})", "({[}])", "(())", "((()))", "([)]",
        "{[()]}", "(((", ")))", "[{()}]", "[({})]",
    };
    for (const auto& expr : tests) {
        std::cout << '"' << expr << "\" -> "
                  << (isBalanced(expr) ? "BALANCED" : "NOT BALANCED") << '\n';
    }
    return 0;
}
