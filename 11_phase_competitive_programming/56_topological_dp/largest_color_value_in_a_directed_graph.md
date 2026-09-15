# Largest Color Value in a Directed Graph

## 1. Problem Statement
[LeetCode 1857](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/) — on a digraph with node colors `a..z`, return the maximum frequency of a single color on any valid path, or `-1` if a cycle exists.

- **Inputs:** `colors` string, `edges`.
- **Output:** max color frequency on a path, or `-1`.
- **Edges:** self-loop; DAG with one color dominating.

## 2. Intuition
`dp[v][c]` = best count of color `c` on any path ending at `v`; propagate in topo order; cycle ⇒ incomplete Kahn.

## 3. Brute Force → Optimal
- **Brute:** enumerate paths — exponential.
- **Optimal:** topo DP with 26 colors — O((V+E)·26).

## 4. Data Structure / Approach Justification
**Chosen:** Kahn + per-node color frequency vector.

| Alternative | Note |
|-------------|------|
| DFS memo + cycle colors | Same asymptotics |
| Path enumeration | Too slow |

## 5. Logic Walkthrough
Init sources; when processing `u`, bump its color; push maxes to successors; if not all nodes processed → cycle.

## 6. Dry Run
`colors=abaca` sample → `3`; self-loop → `-1`.

## 7. Time & Space Complexity
Time **O((V+E)·Σ)** with Σ=26. Space **O(V·Σ)**.

## 8. Trade-offs & Alternatives
Classic hard topo-DP interview problem.

## 9. Common Mistakes / Edge Cases
Forgetting to detect cycles; updating dp after bumping incorrectly.

## 10. Interview Follow-ups / Variations
Weighted nodes; longest path with custom score.

## 11. Tags
`leetcode-1857`, `topological-dp`, `dag`, `difficulty:hard`
