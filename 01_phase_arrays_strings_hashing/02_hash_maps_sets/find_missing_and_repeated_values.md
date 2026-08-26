# Find Missing and Repeated Values

## 1. Problem Statement
[LeetCode 2965](https://leetcode.com/problems/find-missing-and-repeated-values/) — `n × n` grid with values in `[1, n²]`. Every value appears once except `a` (twice) and `b` (missing). Return `[a, b]`.

- **Input:** `vector<vector<int>> grid` (`n == grid.length == grid[i].length`, `2 ≤ n ≤ 50`).
- **Output:** `{repeated, missing}`.
- **Edges:** repeated at corners; missing is `1` or `n²`; smallest `n = 2`.

## 2. Intuition
Domain is tiny (`≤ 2500`). Count frequencies: the value with count `2` is repeated; count `0` is missing.

## 3. Brute Force → Optimal
- **Brute:** for each candidate `1..n²`, scan the whole grid — O(n⁴).
- **Optimal (this file):** one pass count array — O(n²) time, O(n²) space.
- **O(1) space:** sum / sum-of-squares algebra (see alternatives).

## 4. Data Structure / Approach Justification
**Chosen:** `vector<int> cnt(n² + 1)` frequency table.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested scan per value | O(n⁴); unnecessary |
| `unordered_set` insert | Detects repeat early but still needs a second pass for missing |
| Math (Σ / Σ²) | O(1) space; overflow risk; less readable for Easy |

## 5. Logic Walkthrough
1. Allocate `cnt[0..n²]`.
2. For each cell `x`, `++cnt[x]`; when count hits `2`, record `repeated = x`.
3. Scan `v = 1..n²`; first `cnt[v] == 0` is `missing`.
4. Return `{repeated, missing}`.

## 6. Dry Run
`grid = [[1,3],[2,2]]` → counts: `1→1, 2→2, 3→1, 4→0` → **`[2, 4]`**.

`grid = [[9,1,7],[8,9,2],[3,4,6]]` → `9` twice, `5` absent → **`[9, 5]`**.

## 7. Time & Space Complexity
- **Time:** O(n²) — one grid pass + one `1..n²` scan.
- **Space:** O(n²) for the count array.
- Why: every cell and every domain value touched a constant number of times.

## 8. Trade-offs & Alternatives
Math: let `diff = Σgrid − Σ[1..m]` = `a − b`, `sq = Σgrid² − Σ[1..m]²` = `a² − b²`. Then `a + b = sq / diff`, solve for `a, b`. Use `long long` to avoid overflow. Same asymptotic time, O(1) extra space.

## 9. Common Mistakes / Edge Cases
Returning `{missing, repeated}`; off-by-one on `cnt` size (`n² + 1`); assuming values are 0-indexed.

## 10. Interview Follow-ups / Variations
Set Mismatch (LC 645); Find the Duplicate Number (287); Find All Numbers Disappeared (448); O(1)-space math version.

## 11. Tags
`frequency`, `hashing`, `matrix`, `leetcode-2965`, `easy`
