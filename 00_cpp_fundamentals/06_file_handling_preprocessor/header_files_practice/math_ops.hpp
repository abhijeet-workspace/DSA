// math_ops.hpp
// Header-only template utilities: must be defined in header
#pragma once

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// Example of inline variable (C++17): single definition across translation units
inline constexpr const char *math_library = "simple-header-template";
