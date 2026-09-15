# Find Center of Star Graph

## 1. Problem Statement
[LeetCode 1791](https://leetcode.com/problems/find-center-of-star-graph/) — undirected star with `n` nodes labeled `1..n` given as `edges` (`n-1` edges). Return the center node.

- **Inputs:** `edges` length `n-1`.
- **Output:** center label.
- **Valid answer:** unique center of degree `n-1`.
- **Edges:** smallest star `n=3`.

## 2. Intuition
The center is the only node shared by any two edges. Inspect the first two edges.

## 3. Brute Force → Optimal
- **Brute:** build degree array O(n).
- **Optimal:** O(1) compare endpoints of two edges.

## 4. Data Structure / Approach Justification
**Chosen:** constant-time endpoint intersection.

- **vs full adjacency:** unnecessary given star structure.

## 5. Logic Walkthrough
Let first edge be `(a,b)`. If second edge contains `a`, return `a`; else return `b`.

## 6. Dry Run
Edges `(1,2),(2,3),(4,2)` → center **2**.

## 7. Time & Space Complexity
Time **O(1)**. Space **O(1)**. Why: star property (section 4).

## 8. Trade-offs & Alternatives
Degree count is clearer for teaching general graphs.

## 9. Common Mistakes / Edge Cases
Assuming 0-index labels; scanning all edges unnecessarily.

## 10. Interview Follow-ups / Variations
Find the judge; validate star; max degree node.

## 11. Tags
`graph`, `degree`, `leetcode-1791`, `difficulty:easy`
