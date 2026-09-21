// References — C++ fundamentals
// Show aliases, reseating rules, and pass-by-reference mutation.
#include <iostream>

void addTen(int& n) { // reference parameter aliases caller
    n += 10;
}

int main() {
    int x = 5;
    int& ref = x; // ref is another name for x; must bind at init
    ref = 8;
    std::cout << "x=" << x << " ref=" << ref << '\n'; // both 8

    // int& bad; // error: references must be initialized
    // ref = y; // this assigns through ref to x; does NOT reseat ref

    int y = 100;
    ref = y; // assigns 100 into x (still bound to x)
    std::cout << "after ref=y: x=" << x << " y=" << y << '\n';

    addTen(x);
    std::cout << "after addTen(x): x=" << x << '\n';

    const int& cref = 42; // const ref can bind to temporary
    std::cout << "cref=" << cref << '\n';

    return 0;
}
