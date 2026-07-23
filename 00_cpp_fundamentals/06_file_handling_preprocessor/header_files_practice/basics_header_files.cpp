// Header Files Basics — local teaching demo
// Build: g++ -std=c++17 basics_header_files.cpp widget.cpp pimpl_widget.cpp -o basics_header_files
#include <iostream>
#include <string>

#include "config.h"
#include "basics.h"
#include "utils.h"
#include "math_ops.hpp"
#include "widget.h"
#include "pimpl_widget.h"

int main() {
    std::cout << "== Header files: basics -> advanced demo ==\n";

    std::cout << "PROJECT: " << PROJECT_NAME << "\n"; // from config.h

    std::cout << "GLOBAL_CONST (defined in widget.cpp) = " << GLOBAL_CONST << "\n";

    std::cout << greet("World") << " square_constexpr(5)=" << square_constexpr(5) << "\n";

    std::cout << shout(std::string("hello header")) << " (shout from utils.h)\n";

    std::cout << "add<int>(2,3)=" << add<int>(2, 3)
              << ", multiply<double>(2.5, 4)=" << multiply<double>(2.5, 4) << "\n";
    std::cout << "math library (inline constexpr variable) = " << math_library << "\n";

    Widget w("MyWidget"); // impl in widget.cpp
    std::cout << "Widget name: " << w.name() << ", id=" << w.id() << "\n";

    PimplWidget pw("HiddenWidget"); // impl hidden via PIMPL
    std::cout << "PimplWidget name: " << pw.name() << "\n";

    LOG_DEBUG("This debug line prints only when compiled with -DDEBUG");

    std::cout << "\nBest practices:\n"
              << " - Avoid putting 'using namespace std;' in headers.\n"
              << " - Prefer forward declarations in headers when possible.\n"
              << " - Keep headers idempotent (include guards or #pragma once).\n"
              << " - Put templates and inline functions in headers; large implementations in .cpp files.\n";

    return 0;
}
