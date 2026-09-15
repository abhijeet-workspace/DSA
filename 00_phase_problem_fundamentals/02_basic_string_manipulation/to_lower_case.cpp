// To Lower Case — LC 709
// Map each uppercase ASCII letter to lowercase; leave other chars unchanged.
#include <iostream>
#include <string>

std::string toLowerCase(std::string s) {
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
    }
    return s;
}

int main() {
    std::cout << toLowerCase("Hello") << " (expected hello)\n";
    std::cout << toLowerCase("here") << " (expected here)\n";
    return 0;
}
