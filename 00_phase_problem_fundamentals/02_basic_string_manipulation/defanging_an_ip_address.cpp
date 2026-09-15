// Defanging an IP Address — LC 1108
// Replace every '.' with "[.]".
#include <iostream>
#include <string>

std::string defangIPaddr(const std::string& address) {
    std::string ans;
    ans.reserve(address.size() + 6);
    for (char c : address) {
        if (c == '.')
            ans += "[.]";
        else
            ans.push_back(c);
    }
    return ans;
}

int main() {
    std::cout << defangIPaddr("1.1.1.1") << " (expected 1[.]1[.]1[.]1)\n";
    return 0;
}
