// Evaluate Division — https://leetcode.com/problems/evaluate-division/
// Equations ai/bi=values[i]; answer queries as products along graph paths or -1.
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool dfs(const std::string& u, const std::string& target, double acc,
         std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& g,
         std::unordered_set<std::string>& vis, double& ans) {
    if (u == target) {
        ans = acc;
        return true;
    }
    vis.insert(u);
    for (const auto& [v, w] : g[u]) {
        if (vis.count(v))
            continue;
        if (dfs(v, target, acc * w, g, vis, ans))
            return true;
    }
    return false;
}

std::vector<double> calcEquation(const std::vector<std::vector<std::string>>& equations,
                                 const std::vector<double>& values,
                                 const std::vector<std::vector<std::string>>& queries) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> g;
    for (size_t i = 0; i < equations.size(); ++i) {
        const std::string &a = equations[i][0], &b = equations[i][1];
        g[a].push_back({b, values[i]});
        g[b].push_back({a, 1.0 / values[i]});
    }
    std::vector<double> out;
    for (const auto& q : queries) {
        if (!g.count(q[0]) || !g.count(q[1])) {
            out.push_back(-1.0);
            continue;
        }
        std::unordered_set<std::string> vis;
        double ans = -1.0;
        if (!dfs(q[0], q[1], 1.0, g, vis, ans))
            ans = -1.0;
        out.push_back(ans);
    }
    return out;
}

int main() {
    const auto r = calcEquation({{"a", "b"}, {"b", "c"}}, {2.0, 3.0},
                                {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}});
    for (double x : r)
        std::cout << x << " ";
    std::cout << "\n"; // 6 0.5 -1 1 -1
    return 0;
}
