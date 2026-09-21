// Iterators — STL basics
// begin/end traversal, algorithm use, and iterator categories at a glance.
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> v = {4, 1, 3, 2};

    std::cout << "vector via iterators:";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';

    std::sort(v.begin(), v.end()); // needs random-access iterators
    std::cout << "sorted:";
    for (int x : v) {
        std::cout << ' ' << x;
    }
    std::cout << '\n';

    auto it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        std::cout << "find 3 at index " << (it - v.begin()) << '\n'; // random-access difference
    }

    std::list<int> lst = {10, 20, 30};
    std::cout << "list via iterators:";
    for (auto it2 = lst.begin(); it2 != lst.end(); ++it2) {
        std::cout << ' ' << *it2;
    }
    std::cout << '\n';
    // it2 - lst.begin(); // error: bidirectional, not random-access

    return 0;
}
