# Trapping Rain Water

## Problem Statement
[LeetCode 42](https://leetcode.com/problems/trapping-rain-water/) — given bar heights, how much rainwater can be trapped.

- **Inputs:** `vector<int> height` (non-negative).
- **Output:** total trapped units (int).
- **Edges:** empty / single bar; strictly mono heights (0 water); plateaus; tall walls with deep valleys.

## Intuition
Water above an index is bounded by the nearest taller bars on both sides. A monotonic decreasing stack finds the left wall when a taller right wall appears and fills the “basin” layer by layer.

## Brute Force → Optimal
- **Brute:** for each `i`, scan left max and right max — O(N²).
- **Prefix max arrays:** O(N) time/space.
- **Stack / two pointers:** O(N) time; two pointers O(1) extra space.

## Data Structure / Approach Justification
**Chosen:** monotonic decreasing stack of indices (matches this folder’s focus).

- **vs two pointers:** same O(N); two pointers uses less memory and is often preferred in interviews once understood.
- **vs prefix/suffix max:** clearer intuition, O(N) extra arrays.

## Logic Walkthrough
Push decreasing heights. When `height[i]` exceeds stack top, pop `bottom`; if stack empty, no left wall; else width = `i - left - 1`, height = `min(left,i) - bottom`, add `w * h`.

## Dry Run
`height=[0,1,0,2,1,0,1,3,...]`:
- at `i=2` (0) between 1 and later walls; basins accumulate → total **6**.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** stack worst case. Why: each index pushed/popped once (section 4).

## Trade-offs & Alternatives
Two pointers is optimal space. Stack is natural if you already think in next-greater / basins.

## Common Mistakes / Edge Cases
Forgetting empty-stack (no left wall); width off-by-one; using max instead of min of walls; double-counting flat bottoms.

## Interview Follow-ups / Variations
Trapping rain water II (2D); container with most water; largest rectangle in histogram.

## Tags
`stack`, `monotonic-stack`, `two-pointers`, `difficulty:hard`
