# Evaluate Division

## 1. Problem Statement
[LeetCode 399](https://leetcode.com/problems/evaluate-division/) — given equations `ai / bi = values[i]`, answer queries `xj / yj` as a double, or `-1` if undetermined.

- **Inputs:** equations, values, queries.
- **Output:** vector of doubles.
- **Valid answer:** path product in the weighted graph; `-1` if disconnected/unknown variable.
- **Edges:** self query; missing variables; multiple components.

## 2. Intuition
Build bidirectional weighted graph (`a→b` weight `v`, `b→a` weight `1/v`). DFS/BFS multiply edge weights along a path.

## 3. Brute Force → Optimal
- **Brute:** DFS per query — fine for small graphs.
- **Optimal:** Union-Find with weights / Floyd for dense.

## 4. Data Structure / Approach Justification
**Chosen:** adjacency map + DFS product.

- **vs UF with ratio to parent:** faster multi-query.
- **vs BFS:** same.

## 5. Logic Walkthrough
Build graph. For each query, if nodes missing → -1; else DFS from src to dst accumulating product.

## 6. Dry Run
`a/b=2`, `b/c=3` → `a/c=6`, `b/a=0.5`.

## 7. Time & Space Complexity
Time **O(Q·(V+E))**. Space **O(V+E)**. Why: per-query traversal (section 4).

## 8. Trade-offs & Alternatives
Weighted Union-Find for nearly online equations.

## 9. Common Mistakes / Edge Cases
Forgetting reverse edges; not handling `a/a`; dividing by zero values (constraints avoid).

## 10. Interview Follow-ups / Variations
Update equations online; detect inconsistency.

## 11. Tags
`dfs`, `graph`, `weighted`, `leetcode-399`, `difficulty:medium`
