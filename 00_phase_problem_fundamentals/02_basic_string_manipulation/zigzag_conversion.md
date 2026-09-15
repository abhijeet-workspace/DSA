# Zigzag Conversion

## 1. Problem Statement
[LeetCode 6](https://leetcode.com/problems/zigzag-conversion/) — Write `s` in a zigzag pattern on `numRows` rows, then read row by row.

- **Inputs:** `string s`, `int numRows`.
- **Output:** Row-concatenated string.
- **Edges:** `numRows = 1`; `numRows >= n`; short strings.

## 2. Intuition
Simulate a cursor that walks down the rows then up, appending each character to the current row bucket. Finally concatenate buckets.

## 3. Brute Force → Optimal
Building an explicit 2D grid of spaces works but wastes memory. Row-bucket simulation is O(N) time and O(N) space for the answer.

## 4. Data Structure / Approach Justification
**Chosen:** `vector<string> rows` + bouncing index `r` with direction `dir`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Full matrix of size `numRows × N` | Sparse / wasteful |
| Closed-form index formulas | Faster constants; opaque for learning |

This is **row-bucket simulation** — the skill this medium is meant to train — not lookup-table/greedy mapping (e.g. Integer to Roman).

## 5. Logic Walkthrough
1. If `numRows == 1` (or ≥ n), return `s`.
2. For each char: append to `rows[r]`; bounce `dir` at top/bottom; `r += dir`.
3. Concatenate all rows.

## 6. Dry Run
`PAYPALISHIRING`, `numRows=3` → rows `PAHN` / `APLSIIG` / `YIR` → `PAHNAPLSIIGYIR`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N)

## 8. Trade-offs & Alternatives
Math formulas by cycle length `2*(numRows-1)` avoid storing rows until the end; simulation interviews better.

## 9. Common Mistakes / Edge Cases
Forgetting to flip direction; `numRows = 1` infinite bounce; appending in column order instead of row order.

## 10. Interview Follow-ups / Variations
Return the visual grid; zigzag by columns.

## 11. Tags
`string`, `simulation`, `leetcode-6`, `difficulty:medium`
