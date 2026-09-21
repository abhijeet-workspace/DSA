// Scope and Storage Duration — C++ basics
// Demo block scope, global vs local, and static local persistence.
#include <iostream>

int g = 1; // global: static storage, visible across this TU (external linkage by default)

void bumpStaticLocal() {
    static int calls = 0; // initialized once; survives across calls
    ++calls;
    std::cout << "static local calls=" << calls << '\n';
}

int main() {
    std::cout << "global g=" << g << '\n';

    int x = 10; // automatic (stack) local
    std::cout << "outer x=" << x << '\n';

    {
        int x = 99; // shadows outer x inside this block
        int y = 5;  // y dies at end of block
        std::cout << "inner x=" << x << " y=" << y << '\n';
    }
    // std::cout << y; // error: y out of scope
    std::cout << "outer x still=" << x << '\n';

    bumpStaticLocal();
    bumpStaticLocal();
    bumpStaticLocal();

    return 0;
}
