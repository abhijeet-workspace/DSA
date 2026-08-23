# Snapshot Array

## Problem Statement
[LeetCode 1146](https://leetcode.com/problems/snapshot-array/) — array with `set`, `snap` (returns snap id), and `get(index, snap_id)` of the value at that snapshot.

- **Inputs:** length n; stream of set/snap/get.
- **Output:** `get` returns the historical value (default 0).
- **Valid answer:** latest `(snap_id, value)` with `snap_id ≤ query`.
- **Edges:** get before any set; multiple sets in the same snap; query old snaps after later sets.

## Intuition
Each index keeps a timeline of (snap_id, value). Timelines are sorted by snap_id → binary search.

## Brute Force → Optimal
- **Brute:** copy the whole array on every snap — O(N) per snap.
- **Optimal:** sparse history + binary search — O(log S) per get.

## Data Structure / Approach Justification
**Chosen:** per-index vector of pairs, same idea as TimeMap.

- **vs full copy:** too much memory when few indices change
- **vs map per index:** vector is faster; snaps are monotonic

## Logic Walkthrough
`set` overwrites if the last record is the current snap. `get` lower-bounds the query snap.

## Dry Run
set(0,5), snap→0, set(0,6), get(0,0)→5.

## Time & Space Complexity
Time **O(log S)** per get. Space **O(N + updates)**. Why: history length S per index is the number of distinct snaps that changed it.

## Trade-offs & Alternatives
Time-based key-value store is the same pattern with string keys.

## Common Mistakes / Edge Cases
Not coalescing same-snap sets; binary searching the wrong field.

## Interview Follow-ups / Variations
TimeMap (981); persistent arrays.

## Tags
`binary-search`, `design`, `leetcode-1146`, `difficulty:medium`
