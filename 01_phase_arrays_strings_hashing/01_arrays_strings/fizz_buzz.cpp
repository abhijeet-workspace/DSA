// Fizz Buzz — LC 412
// 3 → Fizz, 5 → Buzz, 15 → FizzBuzz, else the number.
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> ans;
    ans.reserve(static_cast<size_t>(n));
    for (int i = 1; i <= n; ++i) {
        if (i % 15 == 0)
            ans.emplace_back("FizzBuzz");
        else if (i % 3 == 0)
            ans.emplace_back("Fizz");
        else if (i % 5 == 0)
            ans.emplace_back("Buzz");
        else
            ans.push_back(std::to_string(i));
    }
    return ans;
}

int main() {
    for (const auto& s : fizzBuzz(5))
        std::cout << s << " ";
    std::cout << "\n"; // expected 1 2 Fizz 4 Buzz
    return 0;
}
