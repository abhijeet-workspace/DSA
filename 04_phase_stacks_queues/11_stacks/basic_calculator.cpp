// Basic Calculator — https://leetcode.com/problems/basic-calculator/
// Stack saves (result, sign) across parentheses; only + / - / nesting.
#include <iostream>
#include <stack>
#include <string>

int calculate(const std::string& s) {
    std::stack<long> st;
    long result = 0;
    long num = 0;
    int sign = 1;

    for (std::size_t i = 0; i < s.size(); ++i) {
        const char c = s[i];
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            result += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            st.push(result);
            st.push(sign);
            result = 0;
            num = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            const long prev_sign = st.top();
            st.pop();
            const long prev_result = st.top();
            st.pop();
            result = prev_sign * result + prev_result;
            sign = 1;
        }
        // spaces: ignore
    }
    result += sign * num;
    return static_cast<int>(result);
}

int main() {
    std::cout << calculate("1 + 1") << " (expected 2)\n";
    std::cout << calculate(" 2-1 + 2 ") << " (expected 3)\n";
    std::cout << calculate("(1+(4+5+2)-3)+(6+8)") << " (expected 23)\n";
    std::cout << calculate("-(2+3)") << " (expected -5)\n";
    return 0;
}
