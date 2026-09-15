# Step By Step Directions

## 1. Problem Statement
[LeetCode 2096](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) — directions start→dest using U/L/R.

- LCA = deepest common prefix of root→start and root→dest paths.

## 2. Intuition
Find both root paths; strip LCA prefix; invert start remainder to U; append dest remainder.

## 3. Brute Force → Optimal
- Build parent map + climb. Path strings are clean for binary trees.

## 4. Data Structure / Approach Justification
**Chosen:** path-to-root strings + LCA prefix.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
DFS build paths; common prefix; synthesize.

## 6. Dry Run
`3→6` → `UURL`.

## 7. Time & Space Complexity
**O(n)**.

## 8. Trade-offs & Alternatives
Parent pointers + LCA node then rebuild.

## 9. Common Mistakes / Edge Cases
Forgetting to convert start suffix to U.

## 10. Interview Follow-ups / Variations
LC 235/236.

## 11. Tags
`lca`, `binary-tree`, `leetcode-2096`, `difficulty:medium`

