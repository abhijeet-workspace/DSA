# Random Flip Matrix (LC 519)

## 1. Problem Statement
Flip random `0` cells in an `m x n` matrix to `1` without rebuilding; reset supported.

- **Inputs:** dimensions; `flip` / `reset`.
- **Output:** random unflipped coordinates.
- **Valid answer:** [LC 519](https://leetcode.com/problems/random-flip-matrix/).
- **Edges:** last cell; reset after many flips.
- **Link:** [LC 519](https://leetcode.com/problems/random-flip-matrix/)

## 2. Intuition
Map matrix to `[0, m*n)`; Fisher–Yates style remap of picked indices to remaining suffix.

## 3. Brute Force → Optimal
- **Brute:** scan for zeros.
- **Remap:** O(1) flip with hashmap.

## 4. Data Structure / Approach Justification
**Chosen:** virtual Fisher–Yates with `unordered_map` remaps.

| Alternative | Note |
|-------------|------|
| Store all cells | Heavy |
| Rejection | Degrades as fill ↑ |

## 5. Logic Walkthrough
1. Pick r in [0, remaining).
2. Resolve through remap; map r→last remaining.
3. Convert id to (r,c).

## 6. Dry Run
2x2 flips return four distinct cells then reset.

## 7. Time & Space Complexity
**O(1)** amortized flip.

## 8. Trade-offs & Alternatives
Same family as blacklist pick.

## 9. Common Mistakes / Edge Cases
Not decreasing remaining; wrong row/col decode.

## 10. Interview Follow-ups / Variations
Weighted cells; 3D.

## 11. Tags
`fisher-yates`, `hashmap`, `lc-519`, `difficulty:medium`
