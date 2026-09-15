// Logger Rate Limiter — https://leetcode.com/problems/logger-rate-limiter/
// Print message only if not printed in the last 10 seconds.
#include <iostream>
#include <string>
#include <unordered_map>

class Logger {
    std::unordered_map<std::string, int> last_; // message -> last print timestamp

public:
    bool shouldPrintMessage(int timestamp, const std::string& message) {
        auto it = last_.find(message);
        if (it != last_.end() && timestamp - it->second < 10) {
            return false;
        }
        last_[message] = timestamp;
        return true;
    }
};

int main() {
    Logger log;
    std::cout << log.shouldPrintMessage(1, "foo") << " (expected 1)\n";
    std::cout << log.shouldPrintMessage(2, "bar") << " (expected 1)\n";
    std::cout << log.shouldPrintMessage(3, "foo") << " (expected 0)\n";
    std::cout << log.shouldPrintMessage(8, "bar") << " (expected 0)\n";
    std::cout << log.shouldPrintMessage(10, "foo") << " (expected 0)\n";
    std::cout << log.shouldPrintMessage(11, "foo") << " (expected 1)\n";
    return 0;
}
