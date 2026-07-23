// Union Basics — C++ fundamentals
// Show that union members share storage: writing one field overwrites another.
#include <iostream>

union Data {
    int intVal; // shares storage
    float floatVal; // shares storage
    char charVal; // shares storage
};

int main() {
    Data d; // one active member at a time

    d.intVal = 10; // activate int
    std::cout << "After setting intVal = 10:" << std::endl;
    std::cout << "  d.intVal: " << d.intVal << std::endl;

    d.floatVal = 3.14f; // overwrite same bytes as float
    std::cout << "\nAfter setting floatVal = 3.14 (intVal is now corrupted):" << std::endl;
    std::cout << "  d.floatVal: " << d.floatVal << std::endl;
    std::cout << "  d.intVal (corrupted): " << d.intVal << std::endl;

    d.charVal = 'A'; // overwrite again as char
    std::cout << "\nAfter setting charVal = 'A' (floatVal is now corrupted):" << std::endl;
    std::cout << "  d.charVal: " << d.charVal << std::endl;
    std::cout << "  d.floatVal (corrupted): " << d.floatVal << std::endl;

    return 0;
}
