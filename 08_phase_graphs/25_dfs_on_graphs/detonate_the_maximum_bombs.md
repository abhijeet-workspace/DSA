# Detonate the Maximum Bombs

## 1. Problem Statement
[LeetCode 2101](https://leetcode.com/problems/detonate-the-maximum-bombs/) — bombs `[x,y,r]`. Detonating `i` detonates any bomb whose center is within radius `r` of `i` (chain reaction). Return the maximum number of bombs that can detonate by choosing one start.

- **Inputs:** `bombs`.
- **Output:** max chain size.
- **Valid answer:** max reachable set in the directed range graph.
- **Edges:** one bomb; mutual range; asymmetric ranges.

## 2. Intuition
Build directed graph `i→j` if `j` is in range of `i`. DFS/BFS from each start; take maximum reachable count.

## 3. Brute Force → Optimal
- **Brute:** O(n) starts × O(n+E) — OK for n≤100.
- **Optimal:** same order; SCC condensation can help larger n.

## 4. Data Structure / Approach Justification
**Chosen:** adjacency lists + DFS from each node.

- **vs BFS:** identical.
- **vs SCC:** overkill for constraints.

## 5. Logic Walkthrough
For all pairs, add edge if distance² ≤ r². From each i, DFS count visited; track max.

## 6. Dry Run
Two overlapping bombs → **2**; far apart → **1**.

## 7. Time & Space Complexity
Time **O(n³)** worst (n starts × n² edges build/visits). Space **O(n²)**. Why: dense range checks (section 4).

## 8. Trade-offs & Alternatives
Use long long for distance to avoid overflow.

## 9. Common Mistakes / Edge Cases
Treating graph undirected; int overflow on dx*dx; radius vs diameter confusion.

## 10. Interview Follow-ups / Variations
Minimum bombs to detonate all; undirected circles.

## 11. Tags
`dfs`, `geometry`, `graph`, `leetcode-2101`, `difficulty:medium`
