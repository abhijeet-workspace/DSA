// Templates — generic programming (C++11/17)
// Function/class templates, specialization, fold expressions, if constexpr.
#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b; // type-generic comparison
}

template <typename T, int Size>
class StaticArray {
private:
    T arr[Size];
public:
    void set(int idx, T val) {
        if (idx >= 0 && idx < Size) arr[idx] = val;
    }
    T get(int idx) const {
        return (idx >= 0 && idx < Size) ? arr[idx] : T();
    }
    int getSize() const { return Size; }
};

template <>
double findMax<double>(double a, double b) {
    std::cout << "(Specialized double function called) ";
    return (a > b) ? a : b;
}

template <typename... Args>
auto sumAll(Args... args) {
    return (args + ...); // C++17 fold: sum pack
}

template <typename T>
void printTypeInfo(T val) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << val << " is an Integral Type.\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << val << " is a Floating Point Type.\n";
    } else {
        std::cout << val << " is a generic/other Type.\n";
    }
}

int main() {
    std::cout << "=== Templates & Generic Programming Demonstration ===\n\n";

    std::cout << "Max of 10 and 20: " << findMax(10, 20) << "\n";
    std::cout << "Max of 'a' and 'z': " << findMax('a', 'z') << "\n";
    std::cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << "\n\n";

    StaticArray<int, 5> intArray;
    intArray.set(0, 42);
    std::cout << "StaticArray<int, 5> at index 0: " << intArray.get(0) << "\n\n";

    std::cout << "Summing (1, 2, 3, 4, 5) using Fold Expression: "
              << sumAll(1, 2, 3, 4, 5) << "\n";
    std::cout << "Summing (1.5, 2.5, 3.5): " << sumAll(1.5, 2.5, 3.5) << "\n\n";

    printTypeInfo(100);
    printTypeInfo(3.14159);
    printTypeInfo("Hello templates");

    return 0;
}
