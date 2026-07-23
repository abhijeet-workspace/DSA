// utils.h
// Use #pragma once for simplicity (supported by most compilers)
#pragma once

#include <string>

// Simple header-only utility function (inline)
inline std::string shout(std::string s) {
    for (auto &c: s) c = toupper(static_cast<unsigned char>(c));
    return s + "!";
}

// Forward declaration example: avoid including heavy headers in other headers
class Heavy; // we don't define Heavy here, just show how to forward declare
