# Find Critical and Pseudo-Critical Edges in MST

## 1. Problem Statement
[LeetCode 1489](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/) — undirected weighted graph. An edge is critical if it appears in every MST; pseudo-critical if it appears in some but not all MSTs. Return both index lists (original edge order).

- **Inputs:** `n`, `edges` `[u,v,weight]`.
- **Output:** `{critical_indices, pseudo_critical_indices}`.
- **Valid answer:** based on MST weight comparisons with force-include / force-exclude.
- **Edges:** unique MST; many equal weights.

## 2. Intuition
Compute base MST weight. Exclude edge i: if MST weight rises (or disconnects), edge is critical. Else if forcing i still achieves base weight, it is pseudo-critical.

## 3. Brute Force → Optimal
- **Brute:** for each edge, Kruskal twice — O(E² α).
- **Optimal enough:** same under E≤n² constraints; bridge-like methods exist.

## 4. Data Structure / Approach Justification
**Chosen:** sort edges + DSU Kruskal variants with force in/out.

- **vs Tarjan on MST + sorting:** more complex.

## 5. Logic Walkthrough
Append original indices; sort by weight. Base MST. For each edge index in sorted list, test exclude then include.

## 6. Dry Run
LC sample marks some edges critical and others pseudo-critical.

## 7. Time & Space Complexity
Time **O(E² α(n))** roughly. Space **O(n+E)**. Why: E Kruskal runs (section 4).

## 8. Trade-offs & Alternatives
Build one MST then classify non-tree edges via replacement weights.

## 9. Common Mistakes / Edge Cases
Losing original indices after sort; treating all equal-weight edges as critical; disconnected exclude case.

## 10. Interview Follow-ups / Variations
Kruskal/Prim MST; redundant connection; min cost to connect points.

## 11. Tags
`mst`, `union-find`, `kruskal`, `leetcode-1489`, `difficulty:hard`
