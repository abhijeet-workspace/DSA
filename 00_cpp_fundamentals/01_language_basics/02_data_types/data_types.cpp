// Data Types — C++ basics
// Declare common built-in types, print them, then mutate one value.
#include <iostream>

int main() {
    int age = 20;           // integer
    float marks = 87.5f;    // single-precision float
    double pi = 3.14159;    // double-precision floating point
    char grade = 'A';       // character
    bool isPass = true;     // boolean

    std::cout << age << " " << marks << " " << pi << " " << grade << " "
              << isPass << std::endl; // print initial values

    age = 30; // mutate age
    std::cout << "New Age: " << age << std::endl; // print updated age
    return 0;
}
