# Evaluate Division

## 1. Problem Statement
[LeetCode 399](https://leetcode.com/problems/evaluate-division/) — equations `a/b=w` as weighted edges; answer queries as path products (or `-1`).

- **Inputs:** equations, values, queries.
- **Output:** doubles per query.
- **Edges:** unknown variable; `a/a`.

## 2. Intuition
Multiplicative weights; DFS/BFS/Union-Find with ratio; related to weighted shortest paths with `log` transform.

## 3. Brute Force → Optimal
- **Brute:** symbolic algebra.
- **Optimal:** graph DFS O(E) per query / UF.

## 4. Data Structure / Approach Justification
**Chosen:** bidirectional weighted graph + DFS product.

| Alternative | Note |
|-------------|------|
| log + APSP | Overkill |
| Union-Find weighted | Faster batches |

## 5. Logic Walkthrough
Build `a→b (w)`, `b→a (1/w)`; DFS multiply; missing node → -1.

## 6. Dry Run
`a/b=2,b/c=3` → `a/c=6`, `b/a=0.5`, unknown `-1`.

## 7. Time & Space Complexity
Time **O(Q·(V+E))** DFS. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Shows weighted graphs beyond classic additive APSP.

## 9. Common Mistakes / Edge Cases
Forgetting reverse edge; dividing instead of multiplying.

## 10. Interview Follow-ups / Variations
Update equations online.

## 11. Tags
`leetcode-399`, `weighted-graph`, `dfs`, `difficulty:medium`
