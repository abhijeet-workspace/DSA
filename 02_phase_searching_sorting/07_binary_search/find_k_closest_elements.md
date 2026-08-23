# Find K Closest Elements

## Problem Statement
[LeetCode 658](https://leetcode.com/problems/find-k-closest-elements/) — sorted `arr`; return the k closest integers to `x` in ascending order (ties prefer the smaller value).

- **Inputs:** `arr`, `k`, `x`.
- **Output:** `vector<int>` of length k.
- **Valid answer:** the unique optimal window of length k.
- **Edges:** x left of all; x right of all; ties.

## Intuition
The answer is a contiguous window. Binary search the start index `s` in `[0, n-k]` using distance of `arr[s]` vs `arr[s+k]` to x.

## Brute Force → Optimal
- **Brute:** compute distances and sort — O(N log N).
- **Optimal:** binary search window start — O(log(N-k) + k).

## Data Structure / Approach Justification
**Chosen:** window-start binary search (not two pointers from x).

- **vs two pointers expand from x:** also O(N); BS is log
- **vs heap of k:** O(N log k) and needs a sort at the end

## Logic Walkthrough
If `x - arr[mid] > arr[mid+k] - x`, the window is too far left.

## Dry Run
`[1,2,3,4,5]`, k=4, x=3 → window `[1,2,3,4]`.

## Time & Space Complexity
Time **O(log(N-k) + k)**. Space **O(1)** extra. Why: log candidate starts; copy k answers.

## Trade-offs & Alternatives
Two-pointer shrink from both ends is a common alternative.

## Common Mistakes / Edge Cases
Using abs incorrectly so ties don't prefer left; off-by-one on `mid+k`.

## Interview Follow-ups / Variations
K closest points; search insert then expand.

## Tags
`binary-search`, `two-pointers`, `leetcode-658`, `difficulty:medium`
