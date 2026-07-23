// Function Overloading — compile-time polymorphism
// Same name `add` with different parameter lists; compiler picks overload.
#include <iostream>

class Calculator {
public:
    int add(int a, int b) { // two ints
        return a + b;
    }

    int add(int a, int b, int c) { // three ints
        return a + b + c;
    }

    float add(float a, float b) { // two floats
        return a + b;
    }
};

int main() {
    Calculator calc;
    std::cout << "Add two integers: " << calc.add(5, 10) << std::endl;
    std::cout << "Add three integers: " << calc.add(5, 10, 15) << std::endl;
    std::cout << "Add two floats: " << calc.add(2.5f, 3.7f) << std::endl;
    return 0;
}
