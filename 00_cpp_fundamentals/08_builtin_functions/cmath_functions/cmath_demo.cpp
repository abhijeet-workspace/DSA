// Cmath Demo — <cmath> & <cstdlib>
// Distance, amortized loan payment, and quadratic roots using math builtins.
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::hypot(x2 - x1, y2 - y1); // sqrt(dx^2 + dy^2) without overflow risk
}

double calculateMonthlyPayment(double principal, double annualRate, int months) {
    double monthlyRate = annualRate / 12.0 / 100.0; // convert APR to monthly fraction
    double numerator = monthlyRate * std::pow(1 + monthlyRate, months);
    double denominator = std::pow(1 + monthlyRate, months) - 1;
    return principal * (numerator / denominator); // M = P * r(1+r)^n / ((1+r)^n - 1)
}

void solveQuadratic(double a, double b, double c) {
    double discriminant = std::pow(b, 2) - 4 * a * c; // b^2 - 4ac
    if (discriminant < 0) {
        std::cout << "Roots are imaginary.\n";
    } else {
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Roots: x1 = " << root1 << ", x2 = " << root2 << "\n";
    }
}

int main() {
    std::cout << "=== Built-in Functions: <cmath> & <cstdlib> ===\n";

    std::cout << "Absolute value of -42: " << std::abs(-42) << "\n";
    std::cout << "Ceil of 3.14: " << std::ceil(3.14)
              << " | Floor of 3.14: " << std::floor(3.14)
              << " | Round of 3.6: " << std::round(3.6) << "\n";
    std::cout << "Floating remainder of 5.5 / 2.0: " << std::fmod(5.5, 2.0) << "\n";
    std::cout << "Min(10, 20): " << std::min(10, 20)
              << " | Max(10, 20): " << std::max(10, 20) << "\n";

    std::cout << "\n1. Coordinate Distance:\n";
    std::cout << "   Distance between (0,0) and (3,4): "
              << calculateDistance(0, 0, 3, 4) << "\n";

    std::cout << "\n2. Monthly Loan Payment:\n";
    double principal = 100000.0;
    double rate = 5.0;
    int term = 360;
    std::cout << "   Monthly payment on $100k at 5% rate for 30 years: $"
              << calculateMonthlyPayment(principal, rate, term) << "\n";

    std::cout << "\n3. Solving Quadratic Equation (1*x^2 - 5*x + 6 = 0):\n";
    solveQuadratic(1, -5, 6);

    return 0;
}
