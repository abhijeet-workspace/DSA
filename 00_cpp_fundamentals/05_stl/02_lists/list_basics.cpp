// List Basics — STL linked lists
// Demo std::list (doubly linked) and std::forward_list (singly linked).
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <list>

void demonstrateList() {
    std::cout << "--- std::list (Doubly-Linked List) ---" << std::endl;
    std::list<int> l = {10, 20, 30};

    l.push_back(40); // O(1) back
    l.push_front(5); // O(1) front

    std::cout << "Forward Traversal: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse Traversal: ";
    for (auto it = l.rbegin(); it != l.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Front element: " << l.front() << ", Back element: " << l.back()
              << std::endl;

    auto it = l.begin();
    std::advance(it, 2); // move to index 2
    l.insert(it, 15); // O(1) splice at iterator

    std::cout << "After inserting 15 at index 2: ";
    for (int val : l) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    l.remove(20); // find+erase value
    std::cout << "After removing 20: ";
    for (int val : l) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void demonstrateForwardList() {
    std::cout << "\n--- std::forward_list (Singly-Linked List) ---" << std::endl;
    std::forward_list<int> fl = {100, 200, 300};

    fl.push_front(50);
    auto it = fl.begin();
    fl.insert_after(it, 75); // insert after first

    std::cout << "Singly Linked List Traversal: ";
    for (int val : fl) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    fl.pop_front();
    std::cout << "After pop_front: ";
    for (int val : fl) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== STL: Lists ===" << std::endl;
    demonstrateList();
    demonstrateForwardList();
    return 0;
}
