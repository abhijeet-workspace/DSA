# 3Sum Closest

## 1. Problem Statement
[LeetCode 16](https://leetcode.com/problems/3sum-closest/) — find three integers in `nums` such that the sum is closest to `target`. Return that sum (guaranteed unique closest).

- **Inputs:** `vector<int> nums` (`n ≥ 3`), `int target`.
- **Output:** Closest three-sum value.
- **Edges:** Exact hit (`sum == target`); all zeros; negatives; duplicates.

## 2. Intuition
After sorting, fix one index and run opposite two pointers like 3Sum. Track the running best by absolute distance to `target`; move pointers by comparing `sum` to `target`.

## 3. Brute Force → Optimal
- **Brute:** all triplets — O(N³).
- **Optimal:** sort + fix + two pointers — O(N²).

## 4. Data Structure / Approach Justification
**Chosen:** sorted array + opposite pointers (same skeleton as 3Sum / Two Sum II).

| Alternative | Why it loses here |
|-------------|-------------------|
| Hash / meet-in-middle | Extra space; awkward for “closest” |
| Binary search per pair | O(N² log N), more code |

## 5. Logic Walkthrough
1. Sort `nums`; initialize `best` to first three sum.
2. For each `i`, set `L=i+1`, `R=n-1`.
3. Update `best` if `|sum-target|` improves; if equal return early.
4. `sum < target` → `++L`; else `--R`.

## 6. Dry Run
`[-1,2,1,-4]`, target `1` → sorted `[-4,-1,1,2]`; best ends at `-1+2+1=2`.

## 7. Time & Space Complexity
- **Time:** O(N²) after O(N log N) sort
- **Space:** O(1) auxiliary (sort may use O(log N))

## 8. Trade-offs & Alternatives
Same pattern as 3Sum; here we optimize distance instead of collecting unique zero-sums. Skip-duplicate logic optional because answer is a sum, not a triplet list.

## 9. Common Mistakes / Edge Cases
Forgetting to update `best` every step; comparing signed difference instead of absolute; `n < 3` (constraints forbid).

## 10. Interview Follow-ups / Variations
3Sum (15); 4Sum; k-sum closest; count triplets within distance.

## 11. Tags
`two-pointers`, `sorting`, `array`, `leetcode-16`, `difficulty:medium`
