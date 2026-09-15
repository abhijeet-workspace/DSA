// String Matching in an Array — LC 1408
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> stringMatching(const std::vector<std::string>& words) {
    std::vector<std::string> ans;
    for (int i = 0; i < (int)words.size(); ++i) {
        for (int j = 0; j < (int)words.size(); ++j) {
            if (i == j)
                continue;
            if (words[j].find(words[i]) != std::string::npos) {
                ans.push_back(words[i]);
                break;
            }
        }
    }
    return ans;
}

int main() {
    auto ans = stringMatching({"mass", "as", "hero", "superhero"});
    for (auto& s : ans)
        std::cout << s << " ";
    std::cout << "(expected as hero)\n";
    return 0;
}
