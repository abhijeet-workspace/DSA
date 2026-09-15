# Number of Provinces

## 1. Problem Statement
[LeetCode 547](https://leetcode.com/problems/number-of-provinces/) — `isConnected[i][j]=1` means cities `i` and `j` are directly linked. A province is a connected component. Return the number of provinces.

- **Inputs:** `n×n` symmetric adjacency matrix.
- **Output:** component count.
- **Valid answer:** number of connected components.
- **Edges:** `n=1`; fully connected; identity (all isolated).

## 2. Intuition
Union every linked pair; remaining DSU roots = provinces. DFS/BFS from each unvisited city also works.

## 3. Brute Force → Optimal
- **Brute:** DFS from each city with visited — **O(n²)** matrix scan.
- **Optimal:** same **O(n²)**; DSU is natural for matrix / online unions.

## 4. Data Structure / Approach Justification
**Chosen:** DSU with component counter.

- **vs DFS:** same complexity; DSU matches Union-Find chapter.
- **vs BFS:** identical to DFS here.

## 5. Logic Walkthrough
`DSU(n)`. For `i<j` with edge, `unite`. Return `components`.

## 6. Dry Run
`[[1,1,0],[1,1,0],[0,0,1]]`: unite 0-1 → 2 components.

## 7. Time & Space Complexity
Time **O(n² α(n))**. Space **O(n)**. Why: matrix edges examined once (section 4).

## 8. Trade-offs & Alternatives
DFS if you already think in graphs. DSU shines when edges arrive online.

## 9. Common Mistakes / Edge Cases
Double-counting undirected edges into wrong math; forgetting diagonal is self.

## 10. Interview Follow-ups / Variations
Number of islands; accounts merge; redundant connection.

## 11. Tags
`union-find`, `connected-components`, `graph`, `leetcode-547`, `difficulty:medium`
