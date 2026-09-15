# All Paths From Source to Target

## 1. Problem Statement
[LeetCode 797](https://leetcode.com/problems/all-paths-from-source-to-target/) — directed acyclic graph as adjacency list. Return all paths from node `0` to node `n-1`.

- **Inputs:** `graph` DAG.
- **Output:** list of paths.
- **Valid answer:** every path from 0 to n-1; order free.
- **Edges:** direct edge 0→n-1; many branches.

## 2. Intuition
DFS from 0 pushing nodes onto a path; when reaching `n-1`, snapshot path; backtrack. DAG ⇒ no visited set required for correctness (optional for speed).

## 3. Brute Force → Optimal
- **Brute/Optimal:** enumerate all paths — output-sensitive exponential.

## 4. Data Structure / Approach Justification
**Chosen:** backtracking DFS on adjacency list.

- **vs BFS with path copies:** more memory per frontier path.

## 5. Logic Walkthrough
Push `u`. If `u==target`, copy path. Else recurse neighbors. Pop.

## 6. Dry Run
`[[1,2],[3],[3],[]]` → `[0,1,3]` and `[0,2,3]`.

## 7. Time & Space Complexity
Time **O(2^n · n)** worst DAGs. Space **O(n)** recursion (+ output). Why: path enumeration (section 4).

## 8. Trade-offs & Alternatives
If cycles possible, need visited-on-path. Topo+DP counts paths faster when only counting.

## 9. Common Mistakes / Edge Cases
Using global visited (blocks other paths); forgetting backtrack pop.

## 10. Interview Follow-ups / Variations
Count paths; shortest path in DAG; with constraints.

## 11. Tags
`dag`, `dfs`, `backtracking`, `leetcode-797`, `difficulty:medium`
