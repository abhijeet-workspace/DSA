// String Ops with Stack — reverse, palindrome, decimal→binary
// Three classic LIFO demos on characters / remainders.
#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::string reverseString(const std::string& str) {
    std::stack<char> st;
    for (char ch : str) {
        st.push(ch);
    }
    std::string reversed;
    while (!st.empty()) {
        reversed.push_back(st.top());
        st.pop();
    }
    return reversed;
}

bool isPalindrome(const std::string& str) {
    std::stack<char> st;
    const int n = static_cast<int>(str.size());
    for (int i = 0; i < n / 2; ++i) {
        st.push(str[static_cast<size_t>(i)]);
    }
    const int start = (n % 2 == 0) ? n / 2 : n / 2 + 1; // skip middle if odd
    for (int i = start; i < n; ++i) {
        if (st.empty() || st.top() != str[static_cast<size_t>(i)]) {
            return false;
        }
        st.pop();
    }
    return st.empty();
}

std::string decimalToBinary(int num) {
    if (num == 0) {
        return "0";
    }
    std::stack<int> st;
    while (num > 0) {
        st.push(num % 2);
        num /= 2;
    }
    std::string binary;
    while (!st.empty()) {
        binary.push_back(static_cast<char>('0' + st.top()));
        st.pop();
    }
    return binary;
}

int main() {
    for (const std::string s : {"Hello", "World", "DataStructure", "abc"}) {
        std::cout << "rev \"" << s << "\" -> \"" << reverseString(s) << "\"\n";
    }
    for (const std::string s : {"racecar", "hello", "level", "abcba", "noon", "world"}) {
        std::cout << "pal \"" << s << "\" -> "
                  << (isPalindrome(s) ? "yes" : "no") << '\n';
    }
    for (int num : {5, 10, 15, 32, 100, 255}) {
        std::cout << "bin " << num << " -> " << decimalToBinary(num) << '\n';
    }
    return 0;
}
