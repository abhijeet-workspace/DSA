// Namespaces — C++ basics
// Nested namespaces, using-declarations, and why to avoid using-directives in headers.
#include <iostream>

namespace math {
int add(int a, int b) {
    return a + b;
}

namespace detail { // nested
int twice(int x) {
    return x * 2;
}
} // namespace detail
} // namespace math

namespace util {
void greet() {
    std::cout << "hello from util\n";
}
} // namespace util

int main() {
    std::cout << "math::add(2,3)=" << math::add(2, 3) << '\n';
    std::cout << "math::detail::twice(4)=" << math::detail::twice(4) << '\n';

    using util::greet; // using-declaration: one name
    greet();

    // using namespace util; // using-directive: pulls all names — avoid in headers
    return 0;
}
