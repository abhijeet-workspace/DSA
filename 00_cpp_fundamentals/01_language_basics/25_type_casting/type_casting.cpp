// Type Casting — C++ basics
// Contrast implicit conversion, C-style cast, static_cast, and dynamic_cast.
#include <iostream>
#include <string>

class Base {
  public:
    virtual ~Base() = default; // needed for dynamic_cast / RTTI
    virtual std::string name() const {
        return "Base";
    }
};

class Derived : public Base {
  public:
    std::string name() const override {
        return "Derived";
    }
    int extra() const {
        return 42;
    }
};

int main() {
    double d = 3.7;
    int truncated = d; // implicit: fractional part dropped
    std::cout << "implicit double->int: " << truncated << '\n';

    int n = 65;
    char c = static_cast<char>(n); // explicit, related conversion
    std::cout << "static_cast<char>(65)='" << c << "'\n";

    int* p = reinterpret_cast<int*>(0x1); // dangerous bit-pattern cast — do not dereference
    std::cout << "reinterpret_cast pointer value=" << p << " (not dereferenced)\n";

    Derived der;
    Base* b = &der; // implicit upcast
    if (Derived* dp = dynamic_cast<Derived*>(b)) { // safe downcast with RTTI
        std::cout << "dynamic_cast ok: " << dp->name() << " extra=" << dp->extra() << '\n';
    }

    Base plain;
    Base* bp = &plain;
    if (dynamic_cast<Derived*>(bp) == nullptr) {
        std::cout << "dynamic_cast failed for pure Base*\n";
    }

    // C-style cast (avoid in modern C++): (int)d
    std::cout << "C-style (int)3.7=" << (int)d << '\n';

    return 0;
}
