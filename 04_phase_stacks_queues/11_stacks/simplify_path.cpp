// Simplify Path — https://leetcode.com/problems/simplify-path/
// Unix absolute path: stack of directory names; skip ".", pop on "..".
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string simplifyPath(const std::string& path) {
    std::vector<std::string> stack;
    std::stringstream ss(path);
    std::string token;
    while (std::getline(ss, token, '/')) {
        if (token.empty() || token == ".") {
            continue; // ignore empty segments and current dir
        }
        if (token == "..") {
            if (!stack.empty()) {
                stack.pop_back(); // go up one level
            }
        } else {
            stack.push_back(token);
        }
    }
    if (stack.empty()) {
        return "/";
    }
    std::string result;
    for (const auto& dir : stack) {
        result += "/" + dir;
    }
    return result;
}

int main() {
    std::cout << simplifyPath("/home/") << " (expected /home)\n";
    std::cout << simplifyPath("/../") << " (expected /)\n";
    std::cout << simplifyPath("/home//foo/") << " (expected /home/foo)\n";
    std::cout << simplifyPath("/a/./b/../../c/") << " (expected /c)\n";
    return 0;
}
