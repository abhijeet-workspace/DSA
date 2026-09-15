// Integer to English Words — LC 273 (Hard, recursive construction)
#include <functional>
#include <iostream>
#include <string>

std::string numberToWords(int num) {
    if (num == 0)
        return "Zero";
    static const char* below20[] = {"",        "One",     "Two",       "Three",    "Four",
                                    "Five",    "Six",     "Seven",     "Eight",    "Nine",
                                    "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                                    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    static const char* tens[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                                 "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    std::function<std::string(int)> under1000 = [&](int n) -> std::string {
        if (n == 0)
            return "";
        if (n < 20)
            return below20[n];
        if (n < 100) {
            std::string res = tens[n / 10];
            if (n % 10)
                res += std::string(" ") + below20[n % 10];
            return res;
        }
        std::string res = std::string(below20[n / 100]) + " Hundred";
        if (n % 100)
            res += " " + under1000(n % 100);
        return res;
    };

    std::function<std::string(int)> helper = [&](int n) -> std::string {
        if (n < 1000)
            return under1000(n);
        if (n < 1000000) {
            std::string res = under1000(n / 1000) + " Thousand";
            if (n % 1000)
                res += " " + under1000(n % 1000);
            return res;
        }
        if (n < 1000000000) {
            std::string res = helper(n / 1000000) + " Million";
            if (n % 1000000)
                res += " " + helper(n % 1000000);
            return res;
        }
        std::string res = under1000(n / 1000000000) + " Billion";
        if (n % 1000000000)
            res += " " + helper(n % 1000000000);
        return res;
    };

    return helper(num);
}

int main() {
    std::cout << numberToWords(123) << " (expected One Hundred Twenty Three)\n";
    std::cout << numberToWords(12345) << " (expected Twelve Thousand Three Hundred Forty Five)\n";
    std::cout
        << numberToWords(1234567)
        << " (expected One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven)\n";
    return 0;
}
