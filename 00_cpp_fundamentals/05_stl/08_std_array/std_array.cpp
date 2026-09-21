// std::array — STL fixed-size contiguous array
// Contrast with C arrays: size, bounds-checked at(), and copy semantics.
#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::array<int, 4> a = {4, 1, 3, 2};
    std::cout << "size=" << a.size() << " front=" << a.front() << " back=" << a.back() << '\n';

    std::cout << "elements:";
    for (int x : a) {
        std::cout << ' ' << x;
    }
    std::cout << '\n';

    std::cout << "at(2)=" << a.at(2) << '\n'; // throws std::out_of_range if bad
    // a.at(99);

    std::sort(a.begin(), a.end());
    std::cout << "sorted:";
    for (int x : a) {
        std::cout << ' ' << x;
    }
    std::cout << '\n';

    std::array<int, 4> b = a; // deep copy of elements (value semantics)
    b[0] = 99;
    std::cout << "a[0]=" << a[0] << " b[0]=" << b[0] << '\n';

    int raw[4] = {1, 2, 3, 4};
    // raw = ...; // C arrays are not assignable
    std::cout << "raw[0]=" << raw[0] << " (C array has no .size())\n";

    return 0;
}
