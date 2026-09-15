// Word Break II — LC 140 (memo DFS; multi-pattern dictionary angle)
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, std::vector<std::string>> memo;
std::unordered_set<std::string> dict;
std::string S;

std::vector<std::string> dfs(int i) {
    if (memo.count(i))
        return memo[i];
    std::vector<std::string> res;
    if (i == (int)S.size()) {
        res.push_back("");
        return memo[i] = res;
    }
    for (int j = i + 1; j <= (int)S.size(); ++j) {
        std::string w = S.substr(i, j - i);
        if (!dict.count(w))
            continue;
        for (const auto& tail : dfs(j)) {
            res.push_back(tail.empty() ? w : w + " " + tail);
        }
    }
    return memo[i] = res;
}

int main() {
    S = "catsanddog";
    dict = {"cat", "cats", "and", "sand", "dog"};
    memo.clear();
    auto ans = dfs(0);
    for (auto& s : ans)
        std::cout << s << " | ";
    std::cout << "(expected two sentences)\n";
    return 0;
}
