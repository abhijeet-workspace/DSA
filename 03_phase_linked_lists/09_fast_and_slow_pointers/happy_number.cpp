// Happy Number — https://leetcode.com/problems/happy-number/
// Return true if repeatedly replacing n with sum of squared digits reaches 1.
#include <iostream>

int getNext(int n) {
    int sum = 0;
    while (n > 0) { // peel digits
        const int d = n % 10;
        sum += d * d; // square and accumulate
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n); // one step ahead
    while (fast != 1 && slow != fast) { // 1 = happy; meet = cycle
        slow = getNext(slow); // tortoise
        fast = getNext(getNext(fast)); // hare
    }
    return fast == 1;
}

int main() {
    std::cout << "19 happy? " << (isHappy(19) ? "Yes" : "No")
              << " (expected Yes)\n";
    std::cout << "2 happy? " << (isHappy(2) ? "Yes" : "No")
              << " (expected No)\n";
    return 0;
}
