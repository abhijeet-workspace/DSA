#include <iostream>
bool canWinNim(int n) {
    return n % 4 != 0;
}
int main() {
    std::cout << std::boolalpha << "canWinNim(4)=" << canWinNim(4) << " (expected false)\n"
              << "canWinNim(5)=" << canWinNim(5) << " (expected true)\n";
    return 0;
}
