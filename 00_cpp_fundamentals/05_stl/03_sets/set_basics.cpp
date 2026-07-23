// set / unordered_set / multiset
// Unique sorted, hashed unique, and sorted-with-duplicates demos.
#include <iostream>
#include <set>
#include <unordered_set>

void demonstrateSet() {
    std::cout << "--- std::set (Sorted Unique Elements) ---" << std::endl;

    std::set<int> s;
    s.insert(40);
    s.insert(10);
    s.insert(30);
    s.insert(10); // duplicate ignored

    std::cout << "Set contents: ";
    for (int val : s) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto it = s.find(30);
    if (it != s.end()) {
        std::cout << "Element 30 found in Set!" << std::endl;
    } else {
        std::cout << "Element 30 not found." << std::endl;
    }
}

void demonstrateUnorderedSet() {
    std::cout << "\n--- std::unordered_set (Hash-Based Unique Elements) ---" << std::endl;

    std::unordered_set<int> us;
    us.insert(50);
    us.insert(20);
    us.insert(80);
    us.insert(20); // duplicate ignored

    std::cout << "Unordered Set contents: ";
    for (int val : us) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    if (us.count(20)) {
        std::cout << "Element 20 exists in Unordered Set." << std::endl;
    }
}

void demonstrateMultiset() {
    std::cout << "\n--- std::multiset (Sorted Duplicate Elements) ---" << std::endl;

    std::multiset<int> ms = {10, 40, 30, 10, 30};

    std::cout << "Multiset contents: ";
    for (int val : ms) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Occurrences of 10: " << ms.count(10) << std::endl;

    ms.erase(30); // erase all 30s
    std::cout << "After deleting 30: ";
    for (int val : ms) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto it = ms.find(10);
    if (it != ms.end()) {
        ms.erase(it); // erase one
    }
    std::cout << "After deleting single instance of 10: ";
    for (int val : ms) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== STL: Sets ===" << std::endl;
    demonstrateSet();
    demonstrateUnorderedSet();
    demonstrateMultiset();
    return 0;
}
