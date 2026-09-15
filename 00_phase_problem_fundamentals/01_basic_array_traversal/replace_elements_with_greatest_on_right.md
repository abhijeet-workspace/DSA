# Replace Elements with Greatest Element on Right Side

## 1. Problem Statement
[LeetCode 1299](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/) — Replace every `arr[i]` with the greatest element among `arr[i+1..]`. Replace the last element with `-1`.

- **Inputs:** `vector<int> arr`.
- **Output:** Modified array (same length).
- **Edges:** Length 1 → `[-1]`; strictly decreasing; max at the end.

## 2. Intuition
Scanning left → right forces repeated max queries. Scanning right → left keeps a running `maxRight` so each index is O(1) work.

## 3. Brute Force → Optimal
For each `i`, scan `i+1..n-1` for max — O(N²). Right-to-left running max — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** in-place right-to-left scan with one scalar `maxRight`.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Suffix-max array (explicit prefix/suffix topic) | Correct; introduces prefix-sum cousin early (topic 9) |
| Segment tree / sparse table | Absurd overkill |

We stay on a single reverse index pass — direction of traversal is the lesson.

## 5. Logic Walkthrough
1. `maxRight = -1`.
2. For `i = n-1..0`: save `cur = arr[i]`; write `arr[i] = maxRight`; `maxRight = max(maxRight, cur)`.
3. Return `arr`.

## 6. Dry Run
`[17,18,5,4,6,1]` → right-to-left writes `-1`, then `1`, `6`, `6`, `6`, `18` → `[18,6,6,6,1,-1]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra (in-place)

## 8. Trade-offs & Alternatives
Building an explicit suffix array is clearer for some learners but uses O(N) space; same idea as topic 9’s prefix/suffix thinking.

## 9. Common Mistakes / Edge Cases
Updating `maxRight` before writing; forgetting last → `-1`; unsigned index underflow when looping with `size_t`.

## 10. Interview Follow-ups / Variations
Greatest on the left; next greater element (monotonic stack, topic 17).

## 11. Tags
`array`, `suffix-max`, `in-place`, `leetcode-1299`, `difficulty:easy`
