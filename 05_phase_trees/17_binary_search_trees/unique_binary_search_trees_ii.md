# Unique Binary Search Trees II

## 1. Problem Statement
[LeetCode 95](https://leetcode.com/problems/unique-binary-search-trees-ii/) — generate all unique BSTs storing `1..n`.

- **Inputs:** `int n`.
- **Output:** `vector<TreeNode*>` roots.
- **Valid answer:** all Catalan-many shapes.
- **Edges:** n=1; n=3 → 5 trees.

## 2. Intuition
For range `[lo,hi]`, try each root; cartesian product of left forests × right forests.

## 3. Brute Force → Optimal
- **Brute/Optimal:** recurse ranges (memo optional) — output-sensitive O(Catalan·N).

## 4. Data Structure / Approach Justification
**Chosen:** `build(lo,hi)` returning vector of roots.

| Alternative | Why it loses here |
|-------------|-------------------|
| Count only (96) | Different problem |
| Deep copy sharing incorrectly | Corrupts trees |

## 5. Logic Walkthrough
Empty range → `{{nullptr}}`. For mid in lo..hi: combine every left with every right.

## 6. Dry Run
n=3: five shapes with roots 1,2,2,3,3 as on LC.

## 7. Time & Space Complexity
- **Time/Space:** proportional to number of trees × size
- Why: must emit each structure.

## 8. Trade-offs & Alternatives
Memoize `vector` per `(lo,hi)` to avoid recomputation.

## 9. Common Mistakes / Edge Cases
Returning empty vector instead of `{{nullptr}}` for empty range; sharing mutable nodes.

## 10. Interview Follow-ups / Variations
Count only (96); generate all full binary trees.

## 11. Tags
`bst`, `recursion`, `catalan`, `leetcode-95`, `difficulty:medium`
