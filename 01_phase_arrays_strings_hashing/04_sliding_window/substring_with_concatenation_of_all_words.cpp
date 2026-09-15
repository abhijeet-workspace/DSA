// Substring with Concatenation of All Words — LC 30
// Slide fixed windows of totalLen; inside, chunk by wordLen and match counts.
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words) {
    std::vector<int> ans;
    if (words.empty())
        return ans;
    const int wordLen = static_cast<int>(words[0].size());
    const int wordCount = static_cast<int>(words.size());
    const int totalLen = wordLen * wordCount;
    const int n = static_cast<int>(s.size());
    if (n < totalLen)
        return ans;

    std::unordered_map<std::string, int> need;
    for (const auto& w : words)
        ++need[w];

    for (int offset = 0; offset < wordLen; ++offset) {
        int left = offset;
        int matched = 0;
        std::unordered_map<std::string, int> window;
        for (int right = offset; right + wordLen <= n; right += wordLen) {
            const std::string w =
                s.substr(static_cast<size_t>(right), static_cast<size_t>(wordLen));
            if (need.count(w)) {
                ++window[w];
                if (window[w] <= need[w])
                    ++matched;
                while (window[w] > need[w]) {
                    const std::string leftWord =
                        s.substr(static_cast<size_t>(left), static_cast<size_t>(wordLen));
                    if (window[leftWord] <= need[leftWord])
                        --matched;
                    --window[leftWord];
                    left += wordLen;
                }
                if (matched == wordCount) {
                    ans.push_back(left);
                    const std::string leftWord =
                        s.substr(static_cast<size_t>(left), static_cast<size_t>(wordLen));
                    --window[leftWord];
                    --matched;
                    left += wordLen;
                }
            } else {
                window.clear();
                matched = 0;
                left = right + wordLen;
            }
        }
    }
    return ans;
}

int main() {
    auto print = [](const std::vector<int>& v) {
        std::cout << '[';
        for (size_t i = 0; i < v.size(); ++i) {
            if (i)
                std::cout << ',';
            std::cout << v[i];
        }
        std::cout << ']';
    };
    print(findSubstring("barfoothefoobarman", {"foo", "bar"}));
    std::cout << " (expected [0,9])\n";
    print(findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "word"}));
    std::cout << " (expected [])\n";
    print(findSubstring("barfoofoobarthefoobarman", {"bar", "foo", "the"}));
    std::cout << " (expected [6,9,12])\n";
    return 0;
}
