// C++17 Features — structured bindings, optional, variant, string_view, init-if
// Type-safe absence/unions and zero-copy string views for cleaner DSA code.
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <optional>
#include <variant>
#include <algorithm>
#include <utility>

std::pair<int, std::string> getStudentInfo() {
    return {101, "Alice"};
}

std::optional<std::string> fetchUserFromDatabase(bool exists) {
    if (exists) return "Abhijeet";
    return std::nullopt; // no value
}

void printStringView(std::string_view sv) {
    std::cout << "string_view contents: " << sv << " | size: " << sv.length() << "\n";
}

int main() {
    std::cout << "=== C++17/20 Features Demonstration ===\n\n";

    auto [id, name] = getStudentInfo(); // structured binding
    std::cout << "Structured Bindings: ID = " << id << ", Name = " << name << "\n\n";

    std::vector<int> vec = {10, 20, 30, 40};
    if (auto it = std::find(vec.begin(), vec.end(), 30); it != vec.end()) { // init-if
        std::cout << "Found element " << *it << " using init-if statement!\n\n";
    }

    auto userOpt = fetchUserFromDatabase(true);
    if (userOpt.has_value()) {
        std::cout << "User found: " << userOpt.value() << "\n";
    }
    auto missingOpt = fetchUserFromDatabase(false);
    std::cout << "Missing user optional fallback: "
              << missingOpt.value_or("Guest_User") << "\n\n";

    std::variant<int, double, std::string> myVar;
    myVar = 10;
    std::cout << "Variant holds int: " << std::get<int>(myVar) << "\n";
    myVar = 3.14159;
    std::cout << "Variant holds double: " << std::get<double>(myVar) << "\n";
    myVar = "Modern C++";

    std::visit([](auto&& arg) {
        std::cout << "Variant visitor active. Type/value: " << arg << "\n";
    }, myVar);
    std::cout << "\n";

    std::string longString = "This is a very long string stored on the heap.";
    printStringView(longString); // no copy
    printStringView(std::string_view(longString).substr(0, 10));

    return 0;
}
