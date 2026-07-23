// Operator overloading — compile-time polymorphism
// Overload +, ==, and << for Complex numbers.
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& obj) {
        Complex temp;
        temp.real = this->real + obj.real;
        temp.imag = this->imag + obj.imag;
        return temp;
    }

    bool operator==(const Complex& obj) {
        return (this->real == obj.real && this->imag == obj.imag);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
};

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

int main() {
    std::cout << "=== OOP Pillar 3: Operator Overloading ===" << std::endl;

    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3 = c1 + c2; // operator+

    std::cout << "Complex Number 1: " << c1 << std::endl;
    std::cout << "Complex Number 2: " << c2 << std::endl;
    std::cout << "Result of Addition: " << c3 << std::endl;

    Complex c4(3.5, 2.5);
    if (c1 == c4) {
        std::cout << "\nComplex Number 1 and Complex Number 4 are EQUAL." << std::endl;
    } else {
        std::cout << "\nComplex Number 1 and Complex Number 4 are NOT EQUAL." << std::endl;
    }

    return 0;
}
