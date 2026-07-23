// Reconstruct Itinerary — https://leetcode.com/problems/reconstruct-itinerary/
// Euler path in a directed multigraph; Hierholzer DFS, lexical edge order.
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> tickets) {
    std::map<std::string, std::multiset<std::string>> g;
    for (auto& t : tickets) {
        g[t[0]].insert(t[1]); // multiset keeps lexical order
    }
    std::vector<std::string> route;
    std::function<void(std::string)> dfs = [&](std::string u) {
        while (!g[u].empty()) {
            std::string v = *g[u].begin();
            g[u].erase(g[u].begin()); // consume edge
            dfs(v);
        }
        route.push_back(u); // post-order
    };
    dfs("JFK");
    std::reverse(route.begin(), route.end());
    return route;
}

int main() {
    auto r = findItinerary({{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}});
    for (const auto& s : r) {
        std::cout << s << " ";
    }
    std::cout << "(expected JFK MUC LHR SFO SJC)\n";
    return 0;
}
