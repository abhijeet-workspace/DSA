// Dynamic Memory — C++ fundamentals
// Allocate heap ints with malloc/new, write values, then free/delete.
#include <cstdlib>
#include <iostream>

int main() {
    int* p = static_cast<int*>(std::malloc(sizeof(int))); // C heap alloc
    *p = 10; // write through pointer
    std::cout << "C malloc: " << *p << std::endl;
    std::free(p); // C free

    int* q = new int(20); // C++ heap alloc + init
    std::cout << "C++ new: " << *q << std::endl;
    delete q; // C++ free

    return 0;
}
