# Rotate Array

## 1. Problem Statement
[LeetCode 189](https://leetcode.com/problems/rotate-array/) — Rotate `nums` to the right by `k` steps in-place.

- **Inputs:** `vector<int>& nums`, `int k`.
- **Output:** None (rotated in place).
- **Edges:** `k = 0`; `k ≥ n` (use `k %= n`); `n = 1`.

## 2. Intuition
Right rotate by `k` moves the suffix of length `k` to the front. Three reverses achieve that with O(1) extra memory: reverse all, reverse first `k`, reverse the rest.

## 3. Brute Force → Optimal
- **Brute:** rotate by 1, `k` times — O(Nk).
- **Extra array:** place `nums[i]` at `(i+k) % n` — O(N) time/space.
- **Optimal in-place:** triple reverse — O(N) time, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** in-place triple reverse via index ranges.

| Alternative | Why it loses here / when to use |
|-------------|----------------------------------|
| Extra buffer with `(i+k)%n` | Clearest index formula; uses O(N) space |
| Cycle-following swaps | O(1) space; harder to get right; closer to cyclic thinking |

We lead with reverses because they are still “block index ranges,” not a new named pattern. The modular placement formula is a fine alternative once `%` indexing is comfortable.

## 5. Logic Walkthrough
1. `k %= n`.
2. Reverse entire array.
3. Reverse `[0, k)`.
4. Reverse `[k, n)`.

## 6. Dry Run
`[1,2,3,4,5,6,7]`, `k=3` → reverse all `[7,6,5,4,3,2,1]` → reverse 3 `[5,6,7,4,3,2,1]` → reverse rest `[5,6,7,1,2,3,4]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra

## 8. Trade-offs & Alternatives
Extra-array modular write is easier to narrate under time pressure; reverse method wins the in-place follow-up.

## 9. Common Mistakes / Edge Cases
Forgetting `k %= n`; reversing wrong segment; left vs right rotate confusion.

## 10. Interview Follow-ups / Variations
Rotate left; rotate a matrix 90° (related 2D indexing later); block-swap algorithm.

## 11. Tags
`array`, `in-place`, `reverse`, `leetcode-189`, `difficulty:medium`
