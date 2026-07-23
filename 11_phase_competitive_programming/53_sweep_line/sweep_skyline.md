# Sweep Skyline

## Problem Statement
Each building is `[L, R, H]`. Output key points where skyline height changes: `(x, height)`. [LeetCode 218](https://leetcode.com/problems/the-skyline-problem/).

- **Inputs:** list of buildings with left, right, height.
- **Output:** critical points in order of increasing `x`.
- **Valid answer:** height equals max active building (or 0 for ground) at each change.
- **Edges:** single building; nested; adjacent same height; ground height 0.

## Intuition
Events at `L` (enter height) and `R` (leave height). A multiset of active heights; when max changes, emit a critical point.

## Brute Force → Optimal
- **Brute:** discretize all `x`, scan buildings per `x` — `O(N²)`.
- **Optimal:** sort events + multiset — `O(N log N)`.

## Data Structure / Approach Justification
**Chosen:** `multiset` of active heights; start encoded as `-h` for classic sort order.

- **vs segment tree on compressed x:** cleaner for online updates.
- **vs divide & conquer:** alternative classic solution.

## Logic Walkthrough
Sort events. Insert height on start; erase one occurrence on end. If `*rbegin()` ≠ previous max, push `(x, cur)`.

## Dry Run
Buildings `[[2,9,10],[3,7,15],...]` → critical: `(2,10),(3,15),(7,12),(12,0),(15,10),(20,8),(24,0)`.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: skyline height = max active; changes only at enter/leave (section 4).

## Trade-offs & Alternatives
Multiset sweep is classic interview code; segtree handles online updates more cleanly.

## Common Mistakes / Edge Cases
Not removing one occurrence on leave (`erase(value)` wipes all); emitting when max unchanged; wrong start/end order at same `x`.

## Interview Follow-ups / Variations
Merge adjacent same-height segments? 3D skyline?

## Tags
`sweep-line`, `skyline`, `multiset`, `geometry`, `difficulty:hard`
