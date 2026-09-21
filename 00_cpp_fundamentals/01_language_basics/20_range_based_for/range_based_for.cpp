// Range-based for — C++ basics
// Iterate arrays, vectors, and strings with for ( : ) and const auto&.
#include <iostream>
#include <string>
#include <vector>

int main() {
    int arr[] = {1, 2, 3, 4};
    std::cout << "array:";
    for (int x : arr) { // copy each element
        std::cout << ' ' << x;
    }
    std::cout << '\n';

    std::vector<int> v = {10, 20, 30};
    std::cout << "vector:";
    for (int& x : v) { // mutate via reference
        x += 1;
        std::cout << ' ' << x;
    }
    std::cout << '\n';

    std::string s = "hi";
    std::cout << "string chars:";
    for (char c : s) {
        std::cout << ' ' << c;
    }
    std::cout << '\n';

    std::cout << "const auto& vector:";
    for (const auto& x : v) { // read-only, no copy of large types
        std::cout << ' ' << x;
    }
    std::cout << '\n';

    return 0;
}
