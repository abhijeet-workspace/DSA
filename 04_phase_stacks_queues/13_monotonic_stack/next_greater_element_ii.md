# Next Greater Element II

## 1. Problem Statement
[LeetCode 503](https://leetcode.com/problems/next-greater-element-ii/) — circular array: for each index, next strictly greater element to the right (wrapping around), or `-1`.

- **Inputs:** `vector<int> nums`.
- **Output:** `vector<int>` same length.
- **Edges:** all equal; strictly decreasing; single element; wrap-around is the only greater.

## 2. Intuition
Same monotonic decreasing index stack as NGE I, but simulate two passes over the array so indices near the end can see values at the front.

## 3. Brute Force → Optimal
- **Brute:** from each `i`, walk up to `n` steps circularly — O(N²).
- **Optimal:** process `2N` virtual indices with one stack — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** stack of indices; loop `k = 0 .. 2n-1`, `i = k % n`; push only on first pass.

| Alternative | Why it loses here |
|-------------|-------------------|
| Concatenate copy of array | Extra O(N) memory for values |
| Right-to-left only | Harder to express wrap without second pass |

## 5. Logic Walkthrough
1. `res` init to `-1`.
2. For `k` in `[0, 2n)`, `i = k % n`.
3. While `nums[st.top()] < nums[i]`, pop and set `res[top] = nums[i]`.
4. If `k < n`, push `i` (avoid duplicate pushes on second pass).

## 6. Dry Run
`nums=[1,2,1]`:
- first pass: `2` resolves index `0` → `2`; second pass: `2` resolves index `2` → `2`; index `1` stays `-1`.

## 7. Time & Space Complexity
- **Time:** O(N) — each index pushed once, popped ≤ once.
- **Space:** O(N) stack + answer.

## 8. Trade-offs & Alternatives
Pushing on both passes works if you guard against overwriting already-set answers. Explicit duplication of `nums` is clearer but uses more memory.

## 9. Common Mistakes / Edge Cases
Pushing every `k` (duplicate indices); `<=` vs `<`; forgetting wrap so last elements stay `-1` incorrectly when a greater exists at front.

## 10. Interview Follow-ups / Variations
NGE I (subset queries); daily temperatures (distance not value); online next-greater stream.

## 11. Tags
`stack`, `monotonic-stack`, `circular-array`, `leetcode-503`, `difficulty:medium`
