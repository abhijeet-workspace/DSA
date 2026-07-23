// basics.h
// Demonstrates include guards, declarations vs definitions, inline and constexpr

#ifndef BASICS_H
#define BASICS_H

#include <string>

// Declarations (in header) - definitions in .cpp when not inline
extern const int GLOBAL_CONST; // declaration of an external constant

// Inline function (header-only, no multiple-definition issues)
inline std::string greet(const std::string &name) {
    return "Hello, " + name + "!";
}

// Constexpr example: usable at compile time
constexpr int square_constexpr(int x) { return x * x; }

#endif // BASICS_H
