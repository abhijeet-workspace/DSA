# Concatenation of Array

## 1. Problem Statement
[LeetCode 1929](https://leetcode.com/problems/concatenation-of-array/) — Given `nums` of length `n`, return an array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n`.

- **Inputs:** `vector<int> nums` (length `n ≥ 1`).
- **Output:** `vector<int>` of length `2n`.
- **Edges:** `n = 1`; all equal elements.

## 2. Intuition
Two sequential copies of the same values — write each `nums[i]` into both slot `i` and slot `i + n`.

## 3. Brute Force → Optimal
Allocate `2n`, copy with repeated `push_back` — same O(N) work. Pre-sized index writes avoid realloc churn and make the doubling explicit.

## 4. Data Structure / Approach Justification
**Chosen:** pre-sized `vector<int>` of length `2n` and a single index loop.

| Alternative | Why it loses here |
|-------------|-------------------|
| Two `push_back` passes without `reserve` | Same asymptotics; more realloc risk |
| STL `copy` twice | Fine in production; index loop is clearer for this topic |

We stay on plain indexing because this topic trains single-pass index fluency before STL helpers become the default habit.

## 5. Logic Walkthrough
1. Let `n = nums.size()`; allocate `ans(2n)`.
2. For each `i` in `[0, n)`: `ans[i] = nums[i]`, `ans[i + n] = nums[i]`.
3. Return `ans`.

## 6. Dry Run
`nums = [1,2,1]`, `n = 3` → write `(0→1, 3→1)`, `(1→2, 4→2)`, `(2→1, 5→1)` → `[1,2,1,1,2,1]`.

## 7. Time & Space Complexity
- **Time:** O(N) — one pass over `n` elements, constant work each.
- **Space:** O(N) for the output (O(1) extra beyond `ans`).

## 8. Trade-offs & Alternatives
Could return a view/lazy concatenation in other languages; here we materialize because the problem asks for a concrete array.

## 9. Common Mistakes / Edge Cases
Off-by-one when sizing `2n`; writing only into `[0,n)` and forgetting the second copy.

## 10. Interview Follow-ups / Variations
Concatenation `k` times; in-place growth when capacity allows.

## 11. Tags
`array`, `simulation`, `indexing`, `leetcode-1929`, `difficulty:easy`
