// Evaluate RPN — https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Stack evaluates postfix tokens; operators pop two operands.
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<long> st;
    for (const auto& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            const long b = st.top();
            st.pop();
            const long a = st.top();
            st.pop();
            if (t == "+") {
                st.push(a + b);
            } else if (t == "-") {
                st.push(a - b);
            } else if (t == "*") {
                st.push(a * b);
            } else {
                st.push(a / b); // trunc toward zero
            }
        } else {
            st.push(std::stol(t));
        }
    }
    return static_cast<int>(st.top());
}

int main() {
    const std::vector<std::string> t = {"2", "1", "+", "3", "*"};
    std::cout << evalRPN(t) << " (expected 9)\n";
    return 0;
}
