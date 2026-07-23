// Practice Stack — blank vector-backed LIFO to extend
// Same skeleton as basics_stack; add top() / tests in main.
#include <iostream>
#include <vector>

template <typename T>
class Stack {
public:
    std::vector<T> elements;
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

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while (!s.empty()) {
        std::cout << s.elements.back() << ' ';
        s.pop();
    }
    std::cout << '\n';
    return 0;
}
