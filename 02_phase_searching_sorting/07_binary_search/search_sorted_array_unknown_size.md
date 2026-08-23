# Search in a Sorted Array of Unknown Size

## Problem Statement
[LeetCode 702](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/) — sorted secret array accessed only via `ArrayReader.get(i)` (`INT_MAX` if out of range); return index of `target` or `-1`.

- **Inputs:** `ArrayReader`, `int target`. Premium API problem.
- **Output:** `int` index.
- **Valid answer:** classic binary search once a finite window containing target is known.
- **Edges:** target before first; beyond last; length 1.

## Intuition
Without `n`, exponentially grow `hi` until `get(hi) >= target`, then binary search `[hi/2, hi]`.

## Brute Force → Optimal
- **Brute:** scan i=0,1,2,... — O(N).
- **Optimal:** exponential search + binary search — O(log N).

## Data Structure / Approach Justification
**Chosen:** doubling bound then standard BS.

- **vs guessing n=1e4:** works on LC constraints but is not the intended idea
- **vs linear:** wastes get() calls

## Logic Walkthrough
Double `hi` while `get(hi) < target`. Then binary search in that window.

## Dry Run
`[-1,0,3,5,9,12]`, target 9 → hi grows to 8, then BS finds index 4.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: exponential bound is O(log N) gets; BS is another O(log N).

## Trade-offs & Alternatives
Same as unbounded binary search / galloping search.

## Common Mistakes / Edge Cases
Treating INT_MAX as a real value; overflow when doubling hi (LC n is small).

## Interview Follow-ups / Variations
Find the index of the large integer (1533); classic 704.

## Tags
`binary-search`, `exponential-search`, `premium`, `leetcode-702`, `difficulty:medium`
