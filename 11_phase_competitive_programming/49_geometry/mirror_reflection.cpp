// LC858 Mirror Reflection
#include <iostream>

int mirrorReflection(int p, int q) {
    int a = p, b = q;
    while (a % 2 == 0 && b % 2 == 0) {
        a /= 2;
        b /= 2;
    }
    if (a % 2 == 0 && b % 2 == 1)
        return 2;
    if (a % 2 == 1 && b % 2 == 1)
        return 1;
    return 0;
}

int main() {
    std::cout << "mirrorReflection(2,1)=" << mirrorReflection(2, 1) << " (expected 2)\n";
    std::cout << "mirrorReflection(3,2)=" << mirrorReflection(3, 2) << " (expected 1)\n";
    return 0;
}
