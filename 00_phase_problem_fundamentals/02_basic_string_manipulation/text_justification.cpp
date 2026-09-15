// Text Justification — LC 68
// Pack words into lines of width maxWidth with full justification rules.
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fullJustify(const std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> ans;
    const int n = static_cast<int>(words.size());
    int i = 0;
    while (i < n) {
        int j = i;
        int lineLen = 0; // sum of word lengths only
        while (j < n &&
               lineLen + static_cast<int>(words[static_cast<size_t>(j)].size()) + (j - i) <=
                   maxWidth) {
            lineLen += static_cast<int>(words[static_cast<size_t>(j)].size());
            ++j;
        }
        const int gaps = j - i - 1;
        const int spaces = maxWidth - lineLen;
        std::string line;
        line.reserve(static_cast<size_t>(maxWidth));

        const bool lastLine = (j == n);
        if (gaps == 0 || lastLine) {
            for (int k = i; k < j; ++k) {
                if (k > i)
                    line.push_back(' ');
                line += words[static_cast<size_t>(k)];
            }
            line.append(static_cast<size_t>(maxWidth - static_cast<int>(line.size())), ' ');
        } else {
            const int base = spaces / gaps;
            int extra = spaces % gaps;
            for (int k = i; k < j; ++k) {
                line += words[static_cast<size_t>(k)];
                if (k < j - 1) {
                    int put = base + (extra > 0 ? 1 : 0);
                    if (extra > 0)
                        --extra;
                    line.append(static_cast<size_t>(put), ' ');
                }
            }
        }
        ans.push_back(std::move(line));
        i = j;
    }
    return ans;
}

int main() {
    auto lines = fullJustify({"This", "is", "an", "example", "of", "text", "justification."}, 16);
    for (const auto& L : lines)
        std::cout << "[" << L << "]\n";
    // expected:
    // [This    is    an]
    // [example  of text]
    // [justification.  ]
    return 0;
}
