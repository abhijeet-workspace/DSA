// Find All Possible Recipes from Given Supplies
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<std::string> findAllRecipes(const std::vector<std::string>& recipes,
                                        const std::vector<std::vector<std::string>>& ingredients,
                                        const std::vector<std::string>& supplies) {
    std::unordered_set<std::string> have(supplies.begin(), supplies.end());
    std::unordered_map<std::string, int> indeg;
    std::unordered_map<std::string, std::vector<std::string>> graph; // ingredient -> recipes needing it
    for (size_t i = 0; i < recipes.size(); ++i) {
        indeg[recipes[i]] = static_cast<int>(ingredients[i].size());
        for (const auto& ing : ingredients[i]) graph[ing].push_back(recipes[i]);
    }
    std::queue<std::string> q;
    for (const auto& s : supplies) q.push(s);
    std::vector<std::string> made;
    while (!q.empty()) {
        std::string cur = q.front();
        q.pop();
        if (!graph.count(cur)) continue;
        for (const auto& rec : graph[cur]) {
            if (--indeg[rec] == 0) {
                made.push_back(rec);
                q.push(rec); // recipe becomes available as ingredient
            }
        }
    }
    return made;
}

int main() {
    const auto r = findAllRecipes({"bread"}, {{"yeast", "flour"}}, {"yeast", "flour", "corn"});
    for (const auto& x : r) std::cout << x << "\n"; // bread
    return 0;
}
