// Restore IP Addresses — https://leetcode.com/problems/restore-ip-addresses/
// Insert dots into digit string to form all valid IPv4 addresses.
#include <iostream>
#include <string>
#include <vector>

bool isValidSegment(const std::string& segment) {
    if (segment.empty() || segment.size() > 3) return false;
    if (segment[0] == '0' && segment.size() > 1) return false; // no leading zero
    int val = 0;
    for (char ch : segment) val = val * 10 + (ch - '0');
    return val >= 0 && val <= 255;
}

void backtrack(const std::string& s, int start, int segmentCount,
               std::string current, std::vector<std::string>& result) {
    if (start == static_cast<int>(s.size()) && segmentCount == 4) {
        current.pop_back(); // drop trailing '.'
        result.push_back(current);
        return;
    }
    if (segmentCount >= 4 || start >= static_cast<int>(s.size())) return;

    for (int len = 1; len <= 3 && start + len <= static_cast<int>(s.size()); ++len) {
        const std::string seg = s.substr(static_cast<size_t>(start),
                                         static_cast<size_t>(len));
        if (!isValidSegment(seg)) continue;
        backtrack(s, start + len, segmentCount + 1, current + seg + ".", result);
    }
}

std::vector<std::string> restoreIpAddresses(const std::string& s) {
    std::vector<std::string> result;
    backtrack(s, 0, 0, "", result);
    return result;
}

int main() {
    const std::string s = "25525511135";
    const auto result = restoreIpAddresses(s);
    std::cout << "IPs for \"" << s << "\" (" << result.size()
              << " expected 2):\n";
    for (const auto& ip : result) std::cout << ip << "\n";
    return 0;
}
