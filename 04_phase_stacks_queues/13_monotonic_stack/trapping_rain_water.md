# Trapping Rain Water

## 1. Problem Statement
[LeetCode 42](https://leetcode.com/problems/trapping-rain-water/) — given bar heights, how much rainwater can be trapped.

- **Inputs:** `vector<int> height` (non-negative).
- **Output:** total trapped units (int).
- **Edges:** empty / single bar; strictly mono heights (0 water); plateaus; tall walls with deep valleys.

## 2. Intuition
Water above an index is bounded by the nearest taller bars on both sides. A monotonic decreasing stack finds the left wall when a taller right wall appears and fills the “basin” layer by layer.

## 3. Brute Force → Optimal
- **Brute:** for each `i`, scan left max and right max — O(N²).
- **Prefix max arrays:** O(N) time/space.
- **Stack / two pointers:** O(N) time; two pointers O(1) extra space.

## 4. Data Structure / Approach Justification
**Chosen:** monotonic decreasing stack of indices (matches this folder’s focus).

| Alternative | Why it loses here |
|-------------|-------------------|
| Two pointers | Same O(N); less memory; often preferred once understood |
| Prefix/suffix max | Clearer intuition; O(N) extra arrays |

## 5. Logic Walkthrough
Push decreasing heights. When `height[i]` exceeds stack top, pop `bottom`; if stack empty, no left wall; else width = `i - left - 1`, height = `min(left,i) - bottom`, add `w * h`.

## 6. Dry Run
`height=[0,1,0,2,1,0,1,3,...]`:
- at `i=2` (0) between 1 and later walls; basins accumulate → total **6**.

## 7. Time & Space Complexity
- **Time:** O(N).
- **Space:** O(N) stack worst case.

## 8. Trade-offs & Alternatives
Two pointers is optimal space. Stack is natural if you already think in next-greater / basins.

## 9. Common Mistakes / Edge Cases
Forgetting empty-stack (no left wall); width off-by-one; using max instead of min of walls; double-counting flat bottoms.

## 10. Interview Follow-ups / Variations
Trapping rain water II (2D); container with most water; largest rectangle in histogram.

## 11. Tags
`stack`, `monotonic-stack`, `two-pointers`, `leetcode-42`, `difficulty:hard`
