// Strings Basics — C++ basics
// Compare C-style char[] with std::string length/size APIs.
#include <iostream>
#include <cstring>
#include <string>

int main() {
    char name[20] = "Rahul"; // C-style null-terminated string
    std::cout << "Length: " << std::strlen(name) << std::endl; // count until '\0'

    std::string city = "Delhi"; // C++ string object
    std::cout << "City: " << city << ", Size: " << city.size() << std::endl; // size() chars
    return 0;
}
