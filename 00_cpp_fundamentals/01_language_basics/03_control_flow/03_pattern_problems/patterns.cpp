// Pattern Problems — C++ basics
// Nested-loop catalogue: 19 patterns printed in a non-interactive demo.
#include <iostream>
#include <algorithm>

void printSolidRectangle(int n, int m);
void printHollowRectangle(int n, int m);
void printRightAngledTriangle(int n);
void printInvertedRightAngledTriangle(int n);
void printNumberPyramid1(int n);
void printNumberPyramid2(int n);
void printCenteredFullPyramid(int n);
void printInvertedCenteredFullPyramid(int n);
void printDiamond(int n);
void printHalfDiamond(int n);
void printBinaryTriangle(int n);
void printAlphabetTriangle1(int n);
void printAlphabetTriangle2(int n);
void printHollowDiamond(int n);
void printButterfly(int n);
void printNumberCrown(int n);
void printFloydsTriangle(int n);
void printPascalsTriangle(int n);
void printSpiralMatrix(int n);

int main() {
    int size = 4; // default pattern height
    std::cout << "Executing sequential demo of all patterns...\n\n";

    std::cout << "\n--- Pattern 1: Solid Rectangle ---\n";
    printSolidRectangle(4, 6);
    std::cout << "\n--- Pattern 2: Hollow Rectangle ---\n";
    printHollowRectangle(4, 6);
    std::cout << "\n--- Pattern 3: Right-Angled Triangle ---\n";
    printRightAngledTriangle(size);
    std::cout << "\n--- Pattern 4: Inverted Right-Angled Triangle ---\n";
    printInvertedRightAngledTriangle(size);
    std::cout << "\n--- Pattern 5: Number Pyramid I ---\n";
    printNumberPyramid1(size);
    std::cout << "\n--- Pattern 6: Number Pyramid II ---\n";
    printNumberPyramid2(size);
    std::cout << "\n--- Pattern 7: Centered Full Pyramid ---\n";
    printCenteredFullPyramid(size);
    std::cout << "\n--- Pattern 8: Inverted Centered Full Pyramid ---\n";
    printInvertedCenteredFullPyramid(size);
    std::cout << "\n--- Pattern 9: Diamond Pattern ---\n";
    printDiamond(size);
    std::cout << "\n--- Pattern 10: Half Diamond / Right Arrow ---\n";
    printHalfDiamond(size);
    std::cout << "\n--- Pattern 11: Binary Number Triangle ---\n";
    printBinaryTriangle(size);
    std::cout << "\n--- Pattern 12: Alphabet Triangle I ---\n";
    printAlphabetTriangle1(size);
    std::cout << "\n--- Pattern 13: Alphabet Triangle II ---\n";
    printAlphabetTriangle2(size);
    std::cout << "\n--- Pattern 14: Hollow Diamond ---\n";
    printHollowDiamond(size);
    std::cout << "\n--- Pattern 15: Butterfly Pattern ---\n";
    printButterfly(size);
    std::cout << "\n--- Pattern 16: Number Crown / Number Bridge ---\n";
    printNumberCrown(size);
    std::cout << "\n--- Pattern 17: Floyd's Triangle ---\n";
    printFloydsTriangle(size);
    std::cout << "\n--- Pattern 18: Pascal's Triangle ---\n";
    printPascalsTriangle(size);
    std::cout << "\n--- Pattern 19: Spiral Number Matrix ---\n";
    printSpiralMatrix(size);
    return 0;
}

void printSolidRectangle(int n, int m) {
    for (int i = 0; i < n; i++) { // rows
        for (int j = 0; j < m; j++) { // cols
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void printHollowRectangle(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) { // border only
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

void printRightAngledTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) { // i stars on row i
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void printInvertedRightAngledTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) { // shrinking width
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void printNumberPyramid1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << " "; // 1..i
        }
        std::cout << "\n";
    }
}

void printNumberPyramid2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << i << " "; // repeat row index
        }
        std::cout << "\n";
    }
}

void printCenteredFullPyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) { // leading spaces
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) { // odd star count
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void printInvertedCenteredFullPyramid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) { // growing spaces
            std::cout << " ";
        }
        for (int j = 0; j < 2 * (n - i) - 1; j++) { // shrinking stars
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void printDiamond(int n) {
    printCenteredFullPyramid(n); // top half
    printInvertedCenteredFullPyramid(n); // bottom half
}

void printHalfDiamond(int n) {
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = (i <= n) ? i : (2 * n - i); // up then down
        for (int j = 1; j <= stars; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void printBinaryTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        int startVal = (i % 2 == 0) ? 0 : 1; // row start bit
        for (int j = 1; j <= i; j++) {
            std::cout << startVal << " ";
            startVal = 1 - startVal; // toggle 0/1
        }
        std::cout << "\n";
    }
}

void printAlphabetTriangle1(int n) {
    for (int i = 1; i <= n; i++) {
        for (char ch = 'A'; ch < 'A' + i; ch++) { // A.. prefix
            std::cout << ch << " ";
        }
        std::cout << "\n";
    }
}

void printAlphabetTriangle2(int n) {
    for (int i = 1; i <= n; i++) {
        char ch = static_cast<char>('A' + i - 1); // row letter
        for (int j = 1; j <= i; j++) {
            std::cout << ch << " ";
        }
        std::cout << "\n";
    }
}

void printHollowDiamond(int n) {
    for (int i = 0; i < n; i++) { // top half
        for (int j = 0; j < n - i; j++) std::cout << "*";
        for (int j = 0; j < 2 * i; j++) std::cout << " ";
        for (int j = 0; j < n - i; j++) std::cout << "*";
        std::cout << "\n";
    }
    for (int i = 0; i < n; i++) { // bottom half
        for (int j = 0; j <= i; j++) std::cout << "*";
        for (int j = 0; j < 2 * (n - i - 1); j++) std::cout << " ";
        for (int j = 0; j <= i; j++) std::cout << "*";
        std::cout << "\n";
    }
}

void printButterfly(int n) {
    for (int i = 1; i <= n; i++) { // top wings
        for (int j = 1; j <= i; j++) std::cout << "*";
        for (int j = 1; j <= 2 * (n - i); j++) std::cout << " ";
        for (int j = 1; j <= i; j++) std::cout << "*";
        std::cout << "\n";
    }
    for (int i = n; i >= 1; i--) { // bottom wings
        for (int j = 1; j <= i; j++) std::cout << "*";
        for (int j = 1; j <= 2 * (n - i); j++) std::cout << " ";
        for (int j = 1; j <= i; j++) std::cout << "*";
        std::cout << "\n";
    }
}

void printNumberCrown(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) std::cout << j; // left ascent
        for (int j = 1; j <= 2 * (n - i); j++) std::cout << " "; // bridge gap
        for (int j = i; j >= 1; j--) std::cout << j; // right descent
        std::cout << "\n";
    }
}

void printFloydsTriangle(int n) {
    int counter = 1; // global increasing id
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << counter << " ";
            counter++;
        }
        std::cout << "\n";
    }
}

void printPascalsTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) std::cout << " "; // center
        int val = 1; // C(i,0)
        for (int j = 0; j <= i; j++) {
            std::cout << val << " ";
            val = val * (i - j) / (j + 1); // next binomial
        }
        std::cout << "\n";
    }
}

void printSpiralMatrix(int n) {
    int size = 2 * n - 1; // odd grid side
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int bottom = size - 1 - i;
            int right = size - 1 - j;
            int minDistance = std::min({top, left, bottom, right}); // shell depth
            std::cout << (n - minDistance) << " ";
        }
        std::cout << "\n";
    }
}
