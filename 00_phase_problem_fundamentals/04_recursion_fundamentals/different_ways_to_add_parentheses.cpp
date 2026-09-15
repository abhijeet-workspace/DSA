// Different Ways to Add Parentheses — LC 241
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<int> diffWaysToCompute(const std::string& expression) {
    std::vector<int> ways;
    bool pureNumber = true;
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            pureNumber = false;
            auto left = diffWaysToCompute(expression.substr(0, i));
            auto right = diffWaysToCompute(expression.substr(i + 1));
            for (int a : left) {
                for (int b : right) {
                    if (c == '+') ways.push_back(a + b);
                    else if (c == '-') ways.push_back(a - b);
                    else ways.push_back(a * b);
                }
            }
        }
    }
    if (pureNumber) ways.push_back(std::stoi(expression));
    return ways;
}

int main() {
    auto a = diffWaysToCompute("2-1-1");
    std::cout << a.size() << " ways for 2-1-1 (expected 2):";
    for (int x : a) std::cout << " " << x;
    std::cout << " (expected values 0 2 in some order)\n";
    auto b = diffWaysToCompute("2*3-4*5");
    std::cout << b.size() << " ways for 2*3-4*5 (expected 5)\n";
    return 0;
}
