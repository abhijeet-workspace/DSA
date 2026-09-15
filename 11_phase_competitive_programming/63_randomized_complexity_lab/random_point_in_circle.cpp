// Random Point in Circle — LC 478
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

struct Solution {
    double R, X, Y;
    std::mt19937 rng{42};
    std::uniform_real_distribution<double> U{0.0, 1.0};
    Solution(double radius, double x, double y) : R(radius), X(x), Y(y) {}
    std::vector<double> randPoint() {
        double r = R * std::sqrt(U(rng));
        double theta = 2.0 * M_PI * U(rng);
        return {X + r * std::cos(theta), Y + r * std::sin(theta)};
    }
};

int main() {
    Solution s(1.0, 0.0, 0.0);
    auto p = s.randPoint();
    std::cout << p[0] << " " << p[1] << " (inside unit circle)\n";
    return 0;
}
