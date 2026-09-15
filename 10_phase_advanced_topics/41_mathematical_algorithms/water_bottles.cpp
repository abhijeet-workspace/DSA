// Water Bottles — https://leetcode.com/problems/water-bottles/
// Drink, exchange empties for full, repeat.
#include <iostream>

int numWaterBottles(int numBottles, int numExchange) {
    int drunk = 0;
    int empty = 0;
    while (numBottles > 0) {
        drunk += numBottles;
        empty += numBottles;
        numBottles = empty / numExchange;
        empty %= numExchange;
    }
    return drunk;
}

int main() {
    std::cout << numWaterBottles(9, 3) << " (expected 13)\n"
              << numWaterBottles(15, 4) << " (expected 19)\n";
    return 0;
}
