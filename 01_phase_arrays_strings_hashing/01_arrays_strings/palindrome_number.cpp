// Palindrome Number — https://leetcode.com/problems/palindrome-number/
// Reverse half the digits; compare to the remaining half.
#include <iostream>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int rev = 0;
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return x == rev || x == rev / 10; // even / odd length
}

int main() {
    std::cout << std::boolalpha << isPalindrome(121) << " (expected true)\n"
              << isPalindrome(-121) << " (expected false)\n"
              << isPalindrome(10) << " (expected false)\n";
    return 0;
}
