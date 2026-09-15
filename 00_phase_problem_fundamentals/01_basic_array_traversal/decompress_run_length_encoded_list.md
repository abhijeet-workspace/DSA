# Decompress Run-Length Encoded List

## 1. Problem Statement
[LeetCode 1313](https://leetcode.com/problems/decompress-run-length-encoded-list/) — `nums` stores adjacent pairs `(freq, val)`. Expand each pair into `freq` copies of `val` and concatenate.

- **Inputs:** `vector<int> nums` (even length).
- **Output:** Expanded `vector<int>`.
- **Edges:** All `freq = 1`; one pair; large `freq`.

## 2. Intuition
Walk the input two-at-a-time; for each pair, append `val` exactly `freq` times.

## 3. Brute Force → Optimal
Nested loops are required to emit the output size. Optional: `ans.reserve(total)` after a counting pass — same asymptotics, fewer reallocs.

## 4. Data Structure / Approach Justification
**Chosen:** output `vector` built with index stride `i += 2`.

| Alternative | Why it loses here |
|-------------|-------------------|
| `std::fill_n` / `insert` helpers | Idiomatic C++; index loops teach emission counting first |
| Linked list of runs | Wrong output type; extra indirection |

Plain index stepping (`i`, `i+1`) is the skill under practice.

## 5. Logic Walkthrough
1. Empty `ans`.
2. For `i = 0,2,4,...`: read `freq = nums[i]`, `val = nums[i+1]`.
3. Push `val` `freq` times.
4. Return `ans`.

## 6. Dry Run
`[1,2,3,4]` → one `2`, then three `4`s → `[2,4,4,4]`.

## 7. Time & Space Complexity
- **Time:** O(L) where L is output length (sum of freqs)
- **Space:** O(L) for output

## 8. Trade-offs & Alternatives
A reserve pass improves constants; skip until profiling matters.

## 9. Common Mistakes / Edge Cases
Stepping `i++` instead of `i += 2`; treating odd-length input (problem guarantees even).

## 10. Interview Follow-ups / Variations
Compress back to RLE; streaming decode without storing all pairs.

## 11. Tags
`array`, `simulation`, `leetcode-1313`, `difficulty:easy`
