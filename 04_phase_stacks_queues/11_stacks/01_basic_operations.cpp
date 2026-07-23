// Basic Stack Operations — push, pop, top, size, empty
// Demo of std::stack LIFO primitives in O(1) each.
#include <iostream>
#include <stack>

int main() {
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40); // top = 40

    std::cout << "size=" << st.size() << " top=" << st.top()
              << " empty=" << (st.empty() ? "yes" : "no") << '\n';

    while (!st.empty()) {
        std::cout << "pop " << st.top() << '\n';
        st.pop();
    }
    std::cout << "after pops: size=" << st.size()
              << " empty=" << (st.empty() ? "yes" : "no") << '\n';
    return 0;
}
