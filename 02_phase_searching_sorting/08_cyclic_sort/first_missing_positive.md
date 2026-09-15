# First Missing Positive

## 1. Problem Statement
[LeetCode 41](https://leetcode.com/problems/first-missing-positive/) — find the smallest missing positive integer in unsorted `nums` using O(1) extra space.

- **Inputs:** `vector<int> nums` (may contain negatives, zeros, large values).
- **Output:** smallest positive integer not present.
- **Valid answer:** in `[1, n+1]`.
- **Edges:** all negatives; already has `1..n`; duplicates; zeros.

## 2. Intuition
Only values in `[1, n]` can affect the answer. Cyclic-sort those into index `v - 1`, then scan for the first hole.

## 3. Brute Force → Optimal
- **Brute:** hash set of positives, probe `1,2,...` — O(N) time, O(N) space.
- **Optimal:** in-place cyclic placement — O(N) time, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** swap `v` into `nums[v-1]` only when `1 ≤ v ≤ n` and not already home.

- **vs sort:** O(N log N), unnecessary when range of interest is `1..n`.
- **vs bool array:** uses O(N) space.

Also appears in fundamentals topic 1 with indexing/marking framing; here the pedagogy is **cyclic placement**.

## 5. Logic Walkthrough
Place valid positives. Then for `i` in `0..n-1`, if `nums[i] != i+1` return `i+1`; else return `n+1`.

## 6. Dry Run
`nums = [3,4,-1,1]`:
- place → `[1,-1,3,4]`
- scan: index `1` ≠ `2` → return `2`

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
Hash set is clearer but fails the O(1)-space constraint. Sorting is simpler for interviews that ignore complexity.

## 9. Common Mistakes / Edge Cases
Swapping when `v` equals `nums[v-1]` (infinite loop); treating `0` as positive; forgetting answer can be `n+1`.

## 10. Interview Follow-ups / Variations
Missing number with `[0,n]`; find duplicate; stream of positives with limited memory.

## 11. Tags
`cyclic-sort`, `array`, `in-place`, `leetcode-41`, `difficulty:hard`
