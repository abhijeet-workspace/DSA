# Minimum Cost to Connect Two Groups

## 1. Problem Statement
[LeetCode 1595](https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/) — connect two groups so every point has ≥1 edge; minimize total edge costs (multi-edges from a point allowed).

- **Inputs:** cost matrix size1×size2.
- **Output:** minimum total cost.
- **Edges:** 1×1; large costs.

## 2. Intuition
Bitmask DP over right coverage while assigning at least one edge per left; unfinished right vertices pay their cheapest left edge.

## 3. Brute Force → Optimal
- **Brute:** huge.
- **Optimal:** DP O(n·m·2^m) with m≤12.

## 4. Data Structure / Approach Justification
**Chosen:** mask DP + minRight completion.

| Alternative | Note |
|-------------|------|
| Min-cost matching variants | Different constraint (exactly-one) |

## 5. Logic Walkthrough
Process left points; OR bits for chosen rights; finally add `minRight` for uncovered rights.

## 6. Dry Run
LC sample → `4`.

## 7. Time & Space Complexity
Time **O(n·m·2^m)**. Space **O(2^m)**.

## 8. Trade-offs & Alternatives
Related to bipartite connectivity costs; not classical matching.

## 9. Common Mistakes / Edge Cases
Forgetting uncovered right penalties; requiring exactly one edge.

## 10. Interview Follow-ups / Variations
Exactly-one assignment → Hungarian.

## 11. Tags
`leetcode-1595`, `bitmask-dp`, `bipartite`, `difficulty:hard`
