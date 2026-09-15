// Evaluate Division — LeetCode 399
// Weighted graph: equations a/b=w as edges; query path product.
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool dfs(const std::string& u, const std::string& t, double cur,
         std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& g,
         std::unordered_set<std::string>& seen, double& out) {
    if (u == t) {
        out = cur;
        return true;
    }
    seen.insert(u);
    for (auto& [v, w] : g[u])
        if (!seen.count(v) && dfs(v, t, cur * w, g, seen, out))
            return true;
    return false;
}

std::vector<double> calcEquation(const std::vector<std::vector<std::string>>& equations,
                                 const std::vector<double>& values,
                                 const std::vector<std::vector<std::string>>& queries) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> g;
    for (size_t i = 0; i < equations.size(); ++i) {
        const auto& a = equations[i][0];
        const auto& b = equations[i][1];
        g[a].push_back({b, values[i]});
        g[b].push_back({a, 1.0 / values[i]});
    }
    std::vector<double> ans;
    for (const auto& q : queries) {
        if (!g.count(q[0]) || !g.count(q[1])) {
            ans.push_back(-1.0);
            continue;
        }
        std::unordered_set<std::string> seen;
        double out = -1.0;
        if (!dfs(q[0], q[1], 1.0, g, seen, out))
            out = -1.0;
        ans.push_back(out);
    }
    return ans;
}

int main() {
    auto a =
        calcEquation({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}});
    std::cout << a[0] << " " << a[1] << " " << a[2] << " (expected 6 0.5 -1)\n";
    return 0;
}
