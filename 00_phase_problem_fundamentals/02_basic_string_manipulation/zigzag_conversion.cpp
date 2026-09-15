// Zigzag Conversion — LC 6
// Simulate walking rows 0..numRows-1 then back; append row buckets.
#include <iostream>
#include <string>
#include <vector>

std::string convert(const std::string& s, int numRows) {
    if (numRows == 1 || numRows >= static_cast<int>(s.size()))
        return s;
    std::vector<std::string> rows(static_cast<size_t>(numRows));
    int r = 0;
    int dir = 1;
    for (char c : s) {
        rows[static_cast<size_t>(r)].push_back(c);
        if (r == 0)
            dir = 1;
        else if (r == numRows - 1)
            dir = -1;
        r += dir;
    }
    std::string ans;
    ans.reserve(s.size());
    for (const auto& row : rows)
        ans += row;
    return ans;
}

int main() {
    std::cout << convert("PAYPALISHIRING", 3) << " (expected PAHNAPLSIIGYIR)\n";
    std::cout << convert("PAYPALISHIRING", 4) << " (expected PINALSIGYAHRPI)\n";
    return 0;
}
