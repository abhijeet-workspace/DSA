// Accounts Merge — https://leetcode.com/problems/accounts-merge/
// Merge accounts that share any email; sort emails per person.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

struct DSU {
    std::vector<int> parent;
    explicit DSU(int n) : parent(static_cast<size_t>(n)) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[static_cast<size_t>(i)] == i) {
            return i;
        }
        return parent[static_cast<size_t>(i)] = find(parent[static_cast<size_t>(i)]);
    }
    void unite(int i, int j) {
        const int ri = find(i);
        const int rj = find(j);
        if (ri != rj) {
            parent[static_cast<size_t>(ri)] = rj; // link components
        }
    }
};

std::vector<std::vector<std::string>> accountsMerge(
    const std::vector<std::vector<std::string>>& accounts) {
    const int n = static_cast<int>(accounts.size());
    DSU dsu(n);
    std::unordered_map<std::string, int> emailToAcc;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < static_cast<int>(accounts[static_cast<size_t>(i)].size()); ++j) {
            const std::string& email = accounts[static_cast<size_t>(i)][static_cast<size_t>(j)];
            auto it = emailToAcc.find(email);
            if (it != emailToAcc.end()) {
                dsu.unite(i, it->second); // shared email → same person
            } else {
                emailToAcc[email] = i;
            }
        }
    }
    std::unordered_map<int, std::vector<std::string>> merged;
    for (const auto& [email, accIdx] : emailToAcc) {
        merged[dsu.find(accIdx)].push_back(email);
    }
    std::vector<std::vector<std::string>> result;
    for (auto& [root, emails] : merged) {
        std::sort(emails.begin(), emails.end());
        std::vector<std::string> account = {accounts[static_cast<size_t>(root)][0]};
        account.insert(account.end(), emails.begin(), emails.end());
        result.push_back(std::move(account));
    }
    return result;
}

int main() {
    const std::vector<std::vector<std::string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"},
    };
    const auto merged = accountsMerge(accounts);
    for (const auto& acc : merged) {
        std::cout << acc[0] << ":";
        for (size_t i = 1; i < acc.size(); ++i) {
            std::cout << " " << acc[i];
        }
        std::cout << "\n";
    }
    return 0;
}
