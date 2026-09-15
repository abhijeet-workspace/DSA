# Unique Paths III

## 1. Problem Statement
[LeetCode 980](https://leetcode.com/problems/unique-paths-iii/) — grid cells: `1` start, `2` end, `0` empty, `-1` obstacle. Count paths from start to end that visit every non-obstacle cell exactly once.

- **Inputs:** `grid`.
- **Output:** path count.
- **Valid answer:** Hamiltonian paths on walkable cells ending at `2`.
- **Edges:** no path; single empty; obstacles blocking.

## 2. Intuition
DFS/backtracking from start; mark visited; when hitting end, accept iff zero walkable cells remain.

## 3. Brute Force → Optimal
- **Brute:** explore all walks — exponential; grid is tiny (≤20 empties).
- **Optimal:** same with visited marking; no poly algorithm expected.

## 4. Data Structure / Approach Justification
**Chosen:** in-place mark `-1` as visited during DFS.

- **vs bit DP on subsets of cells:** viable for ≤20 cells; heavier code.

## 5. Logic Walkthrough
Count walkable cells. DFS: if cell is end and `remain==0`, ++ways. Else mark visited, recurse 4-dir with `remain-1`, unmark.

## 6. Dry Run
Example grid with one obstacle → **2** paths.

## 7. Time & Space Complexity
Time **O(4^{RC})** pruned. Space **O(RC)** recursion. Why: Hamiltonian walk search (section 4).

## 8. Trade-offs & Alternatives
Bitmask DP if you flatten walkable cells to bits.

## 9. Common Mistakes / Edge Cases
Wrong remain count (forget start/end); not restoring cell; counting end early.

## 10. Interview Follow-ups / Variations
Unique Paths I/II (DP); shortest path covering all (TSP).

## 11. Tags
`backtracking`, `grid`, `leetcode-980`, `difficulty:hard`
