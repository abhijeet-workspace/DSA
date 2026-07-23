// Keywords & Literals — C++ basics
// Demo reserved keywords, literals, const, and escape sequences.
#include <iostream>
#include <string>

int main() {
    const double PI = 3.14159265; // const keyword: immutable named value

    int decimal_literal = 42;                 // integer literal
    float float_literal = 0.5f;               // float literal with f suffix
    char char_literal = 'X';                  // character literal
    std::string string_literal = "Antigravity"; // string literal
    bool bool_literal = true;                 // boolean literal

    std::cout << "Decimal literal: " << decimal_literal << "\n"; // \n escape
    std::cout << "Tabbed\tText\tDemo" << std::endl;              // \t escape
    std::cout << "Constant PI value: " << PI << std::endl;
    std::cout << "float=" << float_literal
              << " char=" << char_literal
              << " string=" << string_literal
              << " bool=" << bool_literal << std::endl;
    return 0;
}
