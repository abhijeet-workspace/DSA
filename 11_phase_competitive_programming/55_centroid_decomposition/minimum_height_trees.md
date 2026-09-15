# Minimum Height Trees

## 1. Problem Statement
[LeetCode 310](https://leetcode.com/problems/minimum-height-trees/) — find all roots that minimize tree height. These roots are exactly the **tree centroids** (one or two).

- **Inputs:** `n`, `edges`.
- **Output:** all MHT roots (1 or 2 nodes).
- **Edges:** `n=1`; path of even/odd length.

## 2. Intuition
Leaf peeling: repeatedly remove degree-1 nodes; the last ≤2 nodes are centroids / MHT roots.

## 3. Brute Force → Optimal
- **Brute:** height from every root — O(N²).
- **Optimal:** topological leaf trim — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** Kahn-style leaf peeling.

| Alternative | Note |
|-------------|------|
| Size-walk centroid find | Same answer, different API |
| Full CD | Overkill |

## 5. Logic Walkthrough
Enqueue leaves; peel layers until ≤2 nodes remain.

## 6. Dry Run
`n=4` star at 1 → `{1}`; longer chain example → `{3,4}`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Connects centroid theory to a popular LC problem.

## 9. Common Mistakes / Edge Cases
Forgetting `n=1`; peeling until 0 instead of ≤2.

## 10. Interview Follow-ups / Variations
Return the minimum height value; weighted trees.

## 11. Tags
`leetcode-310`, `centroid`, `leaf-peeling`, `difficulty:medium`
