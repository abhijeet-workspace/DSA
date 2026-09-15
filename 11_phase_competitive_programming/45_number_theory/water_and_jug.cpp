// LC365 Water and Jug — Bézout / gcd
#include <iostream>
#include <numeric>

bool canMeasureWater(int x, int y, int target) {
    if (target == 0)
        return true;
    if (target > static_cast<long long>(x) + y)
        return false;
    if (x == 0 && y == 0)
        return false;
    return target % std::gcd(x, y) == 0;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "canMeasure(3,5,4)=" << canMeasureWater(3, 5, 4) << " (expected true)\n";
    std::cout << "canMeasure(2,6,5)=" << canMeasureWater(2, 6, 5) << " (expected false)\n";
    return 0;
}
