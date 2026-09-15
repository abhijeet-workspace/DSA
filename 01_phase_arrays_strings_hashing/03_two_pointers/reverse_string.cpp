// Reverse String — LC 344
// Swap characters from both ends until pointers meet.
#include <iostream>
#include <string>
#include <vector>

void reverseString(std::vector<char>& s) {
    int L = 0;
    int R = static_cast<int>(s.size()) - 1;
    while (L < R) {
        std::swap(s[static_cast<size_t>(L)], s[static_cast<size_t>(R)]);
        ++L;
        --R;
    }
}

int main() {
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    std::string out(s.begin(), s.end());
    std::cout << out << " (expected olleh)\n";
    std::vector<char> t = {'H', 'a', 'n', 'n', 'a', 'h'};
    reverseString(t);
    std::string out2(t.begin(), t.end());
    std::cout << out2 << " (expected hannaH)\n";
    return 0;
}
