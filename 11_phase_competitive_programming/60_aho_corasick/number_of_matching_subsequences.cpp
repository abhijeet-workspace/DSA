// Number of Matching Subsequences — LC 792
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int numMatchingSubseq(const std::string& s, const std::vector<std::string>& words) {
    std::vector<std::queue<std::pair<int, int>>> buckets(26);
    for (int i = 0; i < (int)words.size(); ++i) {
        if (!words[i].empty())
            buckets[words[i][0] - 'a'].push({i, 0});
    }
    int ans = 0;
    for (char ch : s) {
        auto& q = buckets[ch - 'a'];
        int sz = (int)q.size();
        while (sz--) {
            auto [wi, off] = q.front();
            q.pop();
            ++off;
            if (off == (int)words[wi].size())
                ++ans;
            else
                buckets[words[wi][off] - 'a'].push({wi, off});
        }
    }
    return ans;
}

int main() {
    int ans = numMatchingSubseq("abcde", {"a", "bb", "acd", "ace"});
    std::cout << "count=" << ans << " (expected 3)\n";
    return 0;
}
