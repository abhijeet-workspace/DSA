// Final Value of Variable After Performing Operations — LC 2011
// Start at 0; ++X/X++ increment, --X/X-- decrement.
#include <iostream>
#include <string>
#include <vector>

int finalValueAfterOperations(const std::vector<std::string>& operations) {
    int x = 0;
    for (const std::string& op : operations) {
        // Middle char is '+' for increment, '-' for decrement in all four forms.
        if (op[1] == '+')
            ++x;
        else
            --x;
    }
    return x;
}

int main() {
    std::cout << finalValueAfterOperations({"--X", "X++", "X++"}) << " (expected 1)\n";
    return 0;
}
