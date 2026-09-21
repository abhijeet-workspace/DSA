// Function Parameters — C++ basics
// Pass-by-value vs reference vs const-ref, plus default arguments.
#include <iostream>
#include <string>

void byValue(int n) { // copy; caller unchanged
    n += 10;
    (void)n; // mutated copy is intentionally discarded
}

void byRef(int& n) { // alias; caller mutates
    n += 10;
}

void byConstRef(const std::string& s) { // no copy, no mutate
    std::cout << "const-ref size=" << s.size() << '\n';
}

int scale(int value, int factor = 2) { // default argument
    return value * factor;
}

int main() {
    int a = 5;
    byValue(a);
    std::cout << "after byValue: " << a << '\n'; // still 5

    byRef(a);
    std::cout << "after byRef: " << a << '\n'; // 15

    byConstRef("hello");

    std::cout << "scale(7)=" << scale(7) << " scale(7,3)=" << scale(7, 3) << '\n';

    return 0;
}
