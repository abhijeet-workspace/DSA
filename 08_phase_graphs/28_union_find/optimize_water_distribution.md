# Optimize Water Distribution in a Village

## 1. Problem Statement
[LeetCode 1168](https://leetcode.com/problems/optimize-water-distribution-in-a-village/) — `n` houses; cost to dig well at i or build pipes between houses; minimize cost so every house gets water.

- **Inputs:** `wells[0..n-1]`, `pipes` as `[house1, house2, cost]`.
- **Output:** minimum total cost.
- **Valid answer:** connected via wells/pipes network.
- **Edges:** only wells; cheap pipes spanning all.

## 2. Intuition
Virtual node 0 connected to house i with cost `wells[i-1]`; then MST on n+1 nodes (Kruskal).

## 3. Brute Force → Optimal
- **Brute:** subset of wells + MST on rest — exponential.
- **Optimal:** Kruskal/Prim with virtual node — O(E log E).

## 4. Data Structure / Approach Justification
**Chosen:** edge list + Union-Find Kruskal.

- **vs Prim from 0:** also natural.

## 5. Logic Walkthrough
Add well edges (0,i); sort all edges; unite until n edges accepted; sum costs.

## 6. Dry Run
wells [1,2,2], pipe 1-2 cost1, 2-3 cost1 → dig well1 + two pipes = 3.

## 7. Time & Space Complexity
Time **O(E log E)**. Space **O(n+E)**.

## 8. Trade-offs & Alternatives
Prim with binary heap similar.

## 9. Common Mistakes / Edge Cases
1-index houses; forgetting virtual node; stopping at n+1 edges.

## 10. Interview Follow-ups / Variations
Min cost to connect all points; connecting cities with min cost.

## 11. Tags
`union-find`, `mst`, `graph`, `leetcode-1168`, `difficulty:hard`
