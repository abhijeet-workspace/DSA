// Const Correctness — C++ basics
// Demo const objects, const parameters, and const member functions.
#include <iostream>
#include <string>

class Counter {
  public:
    explicit Counter(int start) : value_(start) {}

    int value() const { // const method: may not mutate members
        return value_;
    }

    void bump() { // non-const: may mutate
        ++value_;
    }

  private:
    int value_;
};

void printName(const std::string& name) { // read-only view; no copy
    std::cout << "name=" << name << '\n';
}

int main() {
    const int maxScore = 100; // must initialize; cannot reassign
    std::cout << "maxScore=" << maxScore << '\n';

    int x = 10;
    const int* pToConst = &x; // pointer to const int: cannot change *pToConst
    // *pToConst = 20; // error
    std::cout << "*pToConst=" << *pToConst << '\n';

    int* const constPtr = &x; // const pointer: cannot reseat, can mutate *constPtr
    *constPtr = 20;
    std::cout << "x after *constPtr=20 -> " << x << '\n';

    printName("Ada");

    const Counter c(5);
    std::cout << "const Counter value=" << c.value() << '\n';
    // c.bump(); // error: non-const method on const object

    Counter mutableC(5);
    mutableC.bump();
    std::cout << "mutable Counter after bump=" << mutableC.value() << '\n';

    return 0;
}
