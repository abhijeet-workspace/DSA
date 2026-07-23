# Next Greater Element

## Problem Statement
For each index, find the nearest greater value strictly to its right (−1 if none).

- **Inputs:** `vector<int> nums`.
- **Output:** same-length vector of next greater values.
- **Valid answer:** first `j > i` with `nums[j] > nums[i]`, else −1.
- **Edges:** strictly decreasing; duplicates; single element; last index always −1.

## Intuition
Indices waiting for a greater value form an increasing stack: when a larger arrives, resolve all smaller tops.

## Brute Force → Optimal
- **Brute:** for each i scan right — O(N²).
- **Optimal:** monotonic stack — O(N).

## Data Structure / Approach Justification
**Chosen:** stack of indices (values also work if distance unused).

- **vs right-to-left value stack:** same asymptotics; this resolves eagerly left→right.
- **vs sparse table RMQ:** heavier for “first greater,” not just max.

## Logic Walkthrough
Scan `i`; while top’s value `< nums[i]`, set `res[top]=nums[i]` and pop; push `i`. Unresolved stay −1.

## Dry Run
`[4,5,2,25]`: 4←5; 2←25; 5←25; 25 unresolved → `[5,25,25,-1]`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: each index pushed/popped at most once (section 4).

## Trade-offs & Alternatives
LeetCode 496 maps nums1→nums2 with a hash after computing NGE on nums2. Circular variant wraps around.

## Common Mistakes / Edge Cases
Using `<=` when equals should not resolve; storing values when indices needed later.

## Interview Follow-ups / Variations
Next greater to the left; circular NGE (503); daily temperatures (739).

## Tags
`stack`, `monotonic-stack`, `next-greater`, `difficulty:medium`
