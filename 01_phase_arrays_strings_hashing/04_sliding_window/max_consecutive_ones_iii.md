# Max Consecutive Ones III

## 1. Problem Statement
[LeetCode 1004](https://leetcode.com/problems/max-consecutive-ones-iii/) — given a binary array and integer `k`, return the maximum number of consecutive `1`s you can achieve if you may flip at most `k` zeros to ones.

- **Input:** `nums` (0/1), `k`
- **Output:** max length of a valid window
- **Valid answer:** longest contiguous stretch after ≤ `k` flips
- **Edges:** `k = 0`; all ones; all zeros with `k < n`

**Prerequisite note:** Variable window on two pointers: invariant is “zeros in `[left,right] ≤ k`.” Same skeleton as longest repeating character replacement.

## 2. Intuition
A valid stretch is a contiguous window with ≤ `k` zeros. Expand right; when zeros exceed `k`, shrink left until valid again; track max width.

## 3. Brute Force → Optimal
- **Brute:** try every subarray and count zeros — O(N²).
- **Optimal:** sliding window — O(N).

## 4. Data Structure / Approach Justification
Two pointers + zero counter. Same pattern as “longest subarray with at most K replacements.”

| Alternative | Why it loses here |
|-------------|-------------------|
| Prefix of zero counts + binary search | O(N log N), more code |
| DP | Unnecessary for contiguous constraint |

## 5. Logic Walkthrough
1. Expand `right`; if `nums[right]==0`, `++zeros`.
2. While `zeros > k`, if `nums[left]==0` decrement zeros, `++left`.
3. Update `best = max(best, right-left+1)`.

## 6. Dry Run
`[1,1,1,0,0,0,1,1,1,1,0]`, `k=2`: window covering indices 3–10 needs 3 zeros → shrink until 2 zeros → length **6** (indices 4–9 or 5–10 depending on shrink path; max is 6).

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: each index enters/leaves the window once.

## 8. Trade-offs & Alternatives
`atMost(k)` framing matches fruit baskets / binary subarrays with sum. Fixed-size window does not apply because max length varies.

## 9. Common Mistakes / Edge Cases
Shrinking too aggressively (lose max); treating ones as flippable; `k` larger than total zeros (answer is `n`).

## 10. Interview Follow-ups / Variations
Max consecutive ones II (487, k=1); longest repeating character replacement (424).

## 11. Tags
`sliding-window`, `two-pointers`, `binary-array`, `leetcode-1004`, `medium`
