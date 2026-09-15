# N-Queens II

## 1. Problem Statement
[LeetCode 52](https://leetcode.com/problems/n-queens-ii/) — return how many distinct solutions exist for placing `n` queens on an `n×n` board with no two attacking.

- **Inputs:** `int n`.
- **Output:** solution count.
- **Valid answer:** integer (same search as N-Queens I without storing boards).
- **Edges:** `n=1` → 1; `n=2,3` → 0; `n=4` → 2.

## 2. Intuition
Same row-by-row backtracking as N-Queens I; only increment a counter when `row==n`.

## 3. Brute Force → Optimal
- **Brute:** generate boards then count — wasteful memory.
- **Optimal:** count-only DFS with O(1) conflict arrays/bitmasks.

## 4. Data Structure / Approach Justification
**Chosen:** boolean arrays for columns and both diagonals.

- **vs scanning board:** slower validity checks.
- **vs bitmasks:** faster constants; arrays are readable.

## 5. Logic Walkthrough
At `row`, try each free column/diags; mark, recurse, unmark. At `row==n`, `count++`.

## 6. Dry Run
`n=4` → **2** solutions.

## 7. Time & Space Complexity
Time **O(n!)** pruned. Space **O(n)**. Why: permutation of columns with diagonal prune (section 4).

## 8. Trade-offs & Alternatives
Bitmask recursion is common in contests. Symmetry breaking can halve work.

## 9. Common Mistakes / Edge Cases
Wrong diagonal index formula; not unmarking; storing boards unnecessarily.

## 10. Interview Follow-ups / Variations
N-Queens I (return boards); bitmask version; count for large n with dancing links.

## 11. Tags
`backtracking`, `leetcode-52`, `difficulty:hard`
