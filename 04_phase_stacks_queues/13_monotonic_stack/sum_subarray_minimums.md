# Sum of Subarray Minimums

## Problem Statement
[LeetCode 907](https://leetcode.com/problems/sum-of-subarray-minimums/) — sum `min(b)` over every contiguous subarray `b`, modulo `10^9 + 7`.

- **Inputs:** `vector<int> arr`.
- **Output:** int (modded sum).
- **Edges:** single element; all equal; strictly increasing / decreasing; large `n` (need O(N)).

## Intuition
Each `arr[i]` is the minimum of `left[i] * right[i]` subarrays: how far it can extend left until a strictly smaller element, and right until a smaller-or-equal (asymmetric bounds avoid double-counting ties).

## Brute Force → Optimal
- **Brute:** enumerate all subarrays, track min — O(N²).
- **Optimal:** two monotonic stacks for previous/next smaller spans — O(N).

## Data Structure / Approach Justification
**Chosen:** stacks of `{value, count}` to accumulate how many positions are dominated.

- **vs index-only PSE/NSE arrays:** equivalent; count form is compact.
- **vs contribution DP without stack:** usually still needs next-smaller logic.

## Logic Walkthrough
Left pass: strictly greater tops pop into `count` → `left[i]`. Right pass: `>=` tops pop → `right[i]`. Add `arr[i] * left[i] * right[i] % MOD`.

## Dry Run
`arr=[3,1,2,4]`:
- mins of all subarrays sum to **17** (`3+1+2+4 + min(3,1)+…`).

## Time & Space Complexity
Time **O(N)**. Space **O(N)** for spans and stacks. Why: each index pushed/popped once per pass (section 4).

## Trade-offs & Alternatives
Strict on one side and non-strict on the other is required for duplicates; swapping both sides also works if consistent.

## Common Mistakes / Edge Cases
Same compare on both sides (double-counts or misses ties); 32-bit overflow before mod; off-by-one spans.

## Interview Follow-ups / Variations
Sum of subarray maximums; sum of subarray ranges; largest rectangle in histogram (related stack spans).

## Tags
`stack`, `monotonic-stack`, `contribution`, `difficulty:medium`
