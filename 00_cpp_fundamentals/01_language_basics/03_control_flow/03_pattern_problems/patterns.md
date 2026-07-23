# Pattern Problems

## 1. Problem Statement
Print a catalogue of 19 classic nested-loop patterns (rectangles, triangles, diamonds, Floyd/Pascal, spiral shells) for a fixed demo size.

- **Input:** none (non-interactive; `size = 4`, rectangles use 4×6)
- **Output:** each pattern labeled and printed sequentially
- **Valid answer:** shapes match the nested-loop formulas in `patterns.cpp`
- **Edges:** `n = 1` collapses most shapes to a single cell/row; hollow borders need `n,m >= 2` to show an interior

## 2. Intuition
Outer loop = rows. Inner loop(s) = spaces / stars / numbers for that row. Derive counts as functions of the row index `i` (and size `n`).

## 3. Brute Force → Optimal
- **Naive:** hardcode each line as a string literal.
- **This approach:** nested loops with closed-form column counts — scales to any `n` and trains 2D thinking for matrices/DP grids.

## 4. Data Structure / Approach Justification
No containers for most patterns — only loop indices. Pascal uses an iterative binomial `val`; spiral uses four boundary distances.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Prebuilt `vector<string>` art | Easy display; teaches no loop relations |
| Recursion per row | Unnecessary stack; same O(n²) output work |
| 2D buffer then print | Useful for spiral fill variants; extra O(n²) memory |

## 5. Logic Walkthrough
- `printSolidRectangle(n,m)` / hollow: full fill vs border test on `i`,`j`.
- Triangles: width `i` or `n-i+1`; number pyramids print `j` or `i`.
- Centered pyramids: spaces `n-i-1`, stars `2*i+1` (and inverted dual).
- `printDiamond` composes both centered halves.
- `printHalfDiamond`: `stars = i` then `2*n-i`.
- Binary / alphabet triangles toggle bits or walk `'A'..`.
- Hollow diamond / butterfly / crown: left block + gap + right block.
- Floyd: rising `counter`; Pascal: `val = val*(i-j)/(j+1)`.
- Spiral: `size=2*n-1`, cell = `n - min(top,left,bottom,right)`.

## 6. Dry Run
`printRightAngledTriangle(4)`:

| i | stars printed |
|---|---------------|
| 1 | `*` |
| 2 | `**` |
| 3 | `***` |
| 4 | `****` |

`printFloydsTriangle(3)` with `counter`: rows `1` / `2 3` / `4 5 6`.

## 7. Time & Space Complexity
- **Time:** O(n²) characters for typical n×n-style patterns (spiral O(n²) cells on side `2n-1`)
- **Space:** O(1) extra (aside from output stream)
- Why: each cell visited a constant number of times; no grid allocation

## 8. Trade-offs & Alternatives
- Build a `vector<string>` when you need to edit patterns after generation.
- Prefer formula-per-cell (spiral) when fills are symmetric shells.
- Keep demos non-interactive so `compile_all` / CI never block on `cin`.

## 9. Common Mistakes / Edge Cases
- Off-by-one in space/star counts
- Forgetting newline after each row
- Integer division order in Pascal update (`val * (i-j) / (j+1)` must stay integral)
- Using `using namespace std;` (avoided here)
- Confusing 0-based vs 1-based row formulas across helpers

## 10. Interview Follow-ups / Variations
- Generate only the k-th row of Pascal in O(k)
- Fill a matrix in spiral order (LeetCode-style) instead of shell distances
- Mirror patterns for left-aligned vs right-aligned triangles

## 11. Tags
`cpp-basics`, `nested-loops`, `patterns`, `beginner`
