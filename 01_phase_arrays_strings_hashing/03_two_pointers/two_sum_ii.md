# Two Sum II (Sorted)

## 1. Problem Statement
Find two indices in a **sorted** ascending array whose values sum to `target`. Return any valid pair of indices (0-based here).

- **Input:** sorted `nums`, integer `target`
- **Output:** `{i, j}` with `i < j`, or empty if none
- **Edges:** no solution; duplicates; negatives (still works if sorted)

## 2. Intuition
Sorted order means sum is monotonic in pointer moves: too small → advance left; too large → retreat right.

## 3. Brute Force → Optimal
- **Brute:** try all pairs — O(N²).
- **Optimal:** two opposite pointers — O(N) one pass.

## 4. Data Structure / Approach Justification
Plain index pair on a sorted `vector` — no hash map needed because order replaces lookup.

| Alternative | Why it loses here |
|-------------|-------------------|
| Hash map (unsorted Two Sum) | Extra O(N) space; sorting already given |
| Binary search per index | O(N log N), more code |

## 5. Logic Walkthrough
1. `L=0`, `R=n-1`.
2. Compare `nums[L]+nums[R]` to target.
3. Equal → return; less → `++L`; greater → `--R`.
4. Stop when `L >= R`.

## 6. Dry Run
`[1,2,4,5,6,7,10]`, target `9`:
`1+10=11` → `--R`; `1+7=8` → `++L`; `2+7=9` → `{1,5}`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
Hash map still works without sorting but uses O(N) space. Binary-search-per-i is valid but slower.

## 9. Common Mistakes / Edge Cases
Assuming unsorted input; off-by-one when returning 1-based LC indices; infinite loop if neither pointer moves.

## 10. Interview Follow-ups / Variations
Return 1-based indices (LC 167); count pairs; 3Sum / 4Sum.

## 11. Tags
`two-pointers`, `sorted-array`, `two-sum`, `O(n)`, `leetcode-167`
