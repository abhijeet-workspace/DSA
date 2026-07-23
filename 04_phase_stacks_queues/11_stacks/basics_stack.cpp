// Basics Stack — minimal vector-backed LIFO template
// Custom Stack<T> with push/pop/empty; demo via public storage.
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Stack {
public:
    std::vector<T> elements; // public for teaching visibility
    void push(const T& v) { elements.push_back(v); }
    void pop() {
        if (elements.empty()) {
            std::cout << "Stack is empty, cannot pop\n";
            return;
        }
        elements.pop_back();
    }
    bool empty() const { return elements.empty(); }
};

template <typename T>
static void print_vec(const std::vector<T>& v, const std::string& name) {
    std::cout << name << " (size=" << v.size() << ", cap=" << v.capacity() << "): ";
    for (const auto& x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    Stack<int> s;
    s.elements = {10, 20, 30};
    s.push(40);
    s.push(50);
    s.pop();
    s.pop();
    s.push(70);
    print_vec(s.elements, "Stack elements");
    s.elements.shrink_to_fit();
    print_vec(s.elements, "After shrink");
    return 0;
}
