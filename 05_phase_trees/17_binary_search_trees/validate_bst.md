# Validate Binary Search Tree

## Problem Statement
[LeetCode 98](https://leetcode.com/problems/validate-binary-search-tree/) — return true iff `root` is a valid BST (strict: all left `<` node `<` all right).

- **Inputs:** `TreeNode* root`.
- **Output:** boolean.
- **Valid answer:** true only if every node respects its full ancestor range.
- **Edges:** `INT_MIN` / `INT_MAX` values; single node; duplicates (invalid under strict BST).

## Intuition
Parent vs child alone is not enough. Pass tightening `(lo, hi)` bounds so every node must satisfy `lo < val < hi`.

## Brute Force → Optimal
- **Brute:** collect inorder, check strictly increasing — O(N) time/space.
- **Optimal:** DFS with bounds (or inorder prev pointer) — O(N) / O(H).

## Data Structure / Approach Justification
**Chosen:** recursive bounds DFS with `long long` limits.

- **vs inorder + prev:** also O(N); easy to miss first-node init.
- **vs parent-only checks:** incorrect on cases like `[5,1,4,null,null,3,6]`.

## Logic Walkthrough
Empty → true. If `val` not in `(lo, hi)` → false. Left: `(lo, val)`; right: `(val, hi)`.

## Dry Run
`[2,1,3]`: 2 in (−∞,∞); 1 in (−∞,2); 3 in (2,∞) → true.

`[5,1,4]`: 4 must be in (5,∞) but 4 < 5 → false.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: visit each node once with inherited bounds (section 4).

## Trade-offs & Alternatives
Inorder streaming uses one `prev` variable. Use `long long` (or nullable bounds) to avoid `INT_MIN`/`INT_MAX` pitfalls.

## Common Mistakes / Edge Cases
Only checking immediate children; using `int` bounds that collide with node values; allowing equals when the problem is strict.

## Interview Follow-ups / Variations
Allow equals (multiset BST)? Recover BST from two swapped nodes (99)? Count valid BST shapes?

## Tags
`bst`, `dfs`, `bounds`, `validation`, `leetcode-98`, `difficulty:medium`
