// Postfix Evaluation — evaluate digit/operator RPN string
// Push digits; on operator pop two operands, push result.
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

int evaluatePostfix(const std::string& expr) {
    std::stack<int> st;
    for (char ch : expr) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            st.push(ch - '0');
            continue;
        }
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            const int b = st.top();
            st.pop();
            const int a = st.top();
            st.pop();
            int result = 0;
            if (ch == '+') {
                result = a + b;
            } else if (ch == '-') {
                result = a - b;
            } else if (ch == '*') {
                result = a * b;
            } else {
                result = a / b; // trunc toward zero (int)
            }
            st.push(result);
        }
    }
    return st.top();
}

int main() {
    const std::vector<std::pair<std::string, int>> tests = {
        {"23+", 5},
        {"234*+", 14},
        {"234*+5-", 9},
        {"123+*", 5},
        {"12+34+*", 21},
        {"5678*+*", 310},
        {"321*-", 1},
        {"432/-", 3},
    };
    for (const auto& [expr, expected] : tests) {
        const int got = evaluatePostfix(expr);
        std::cout << '"' << expr << "\" -> " << got
                  << " (expected " << expected << ") "
                  << (got == expected ? "OK" : "FAIL") << '\n';
    }
    return 0;
}
