// Pointer Arithmetic — C++ fundamentals
// Show array decay, *(p+i), pointer increment, and const pointer variants.
#include <iostream>

void printFirst(const int* p, int n) { // array decays to pointer at call
    for (int i = 0; i < n; ++i) {
        std::cout << *(p + i) << ' '; // equivalent to p[i]
    }
    std::cout << '\n';
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int* p = arr; // decays to &arr[0]

    std::cout << "p[0]=" << p[0] << " *(p+1)=" << *(p + 1) << '\n';
    std::cout << "address p=" << p << " p+1=" << (p + 1) << '\n'; // +1 element, not +1 byte

    ++p; // now points at 20
    std::cout << "after ++p, *p=" << *p << '\n';

    printFirst(arr, 4);

    int x = 5;
    const int* pc = &x; // cannot mutate *pc
    int* const cp = &x; // cannot reseat cp
    std::cout << "*pc=" << *pc << " *cp=" << *cp << '\n';
    *cp = 7;
    std::cout << "x after *cp=7 -> " << x << '\n';

    return 0;
}
