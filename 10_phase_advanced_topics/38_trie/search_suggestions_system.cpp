// Search Suggestions System — https://leetcode.com/problems/search-suggestions-system/
// Sort products; for each prefix binary-search lower_bound, take up to 3 matches.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string> products,
                                                        const std::string& searchWord) {
    std::sort(products.begin(), products.end());
    std::vector<std::vector<std::string>> ans;
    std::string prefix;
    auto it = products.begin();
    for (char c : searchWord) {
        prefix.push_back(c);
        it = std::lower_bound(it, products.end(), prefix);
        std::vector<std::string> suggestions;
        for (auto j = it; j != products.end() && suggestions.size() < 3; ++j) {
            if (j->compare(0, prefix.size(), prefix) != 0)
                break;
            suggestions.push_back(*j);
        }
        ans.push_back(std::move(suggestions));
    }
    return ans;
}

static void printAns(const std::vector<std::vector<std::string>>& ans) {
    std::cout << "[";
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << "[";
        for (size_t j = 0; j < ans[i].size(); ++j) {
            if (j)
                std::cout << ", ";
            std::cout << ans[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]";
}

int main() {
    const auto a1 =
        suggestedProducts({"mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse");
    printAns(a1);
    std::cout << " (expected [[mobile, moneypot, monitor], [mobile, moneypot, monitor], "
                 "[mouse, mousepad], [mouse, mousepad], [mouse, mousepad]])\n";

    const auto a2 = suggestedProducts({"havana"}, "havana");
    printAns(a2);
    std::cout << " (expected [[havana], [havana], [havana], [havana], [havana], [havana]])\n";
    return 0;
}
