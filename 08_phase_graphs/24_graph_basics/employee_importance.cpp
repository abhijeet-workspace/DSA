// Employee Importance — https://leetcode.com/problems/employee-importance/
// Each employee has id, importance, and subordinates; return total importance of id's subtree.
#include <iostream>
#include <unordered_map>
#include <vector>

struct Employee {
    int id;
    int importance;
    std::vector<int> subordinates;
};

int dfs(int id, const std::unordered_map<int, Employee*>& mp) {
    const Employee* e = mp.at(id);
    int sum = e->importance;
    for (int s : e->subordinates) sum += dfs(s, mp);
    return sum;
}

int getImportance(const std::vector<Employee*>& employees, int id) {
    std::unordered_map<int, Employee*> mp;
    for (Employee* e : employees) mp[e->id] = e;
    return dfs(id, mp);
}

int main() {
    Employee a{1, 5, {2, 3}};
    Employee b{2, 3, {}};
    Employee c{3, 3, {}};
    std::cout << getImportance({&a, &b, &c}, 1) << " (expected 11)\n";
    return 0;
}
