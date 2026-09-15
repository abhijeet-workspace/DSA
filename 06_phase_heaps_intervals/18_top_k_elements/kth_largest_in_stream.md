# Kth Largest Element in a Stream

## Problem Statement
[LeetCode 703](https://leetcode.com/problems/kth-largest-element-in-a-stream/) — design a class that, after each `add`, returns the kth largest element in the stream (including initial nums).

- **Inputs:** `k`, initial `nums`, then `add(val)` calls.
- **Output:** kth largest after each add.
- **Valid answer:** sorted descending, index `k-1` (1-based k).
- **Edges:** `nums` shorter than `k`; duplicates; adding smaller than current kth.

## Intuition
Maintain a min-heap of size exactly `k`. The heap root is the smallest among the top `k` → the kth largest overall.

## Brute Force → Optimal
- **Brute:** keep all values, sort on each add — O(N log N) per add.
- **Optimal:** size-`k` min-heap — O(log k) per add.

## Data Structure / Approach Justification
**Chosen:** `priority_queue` min-heap capped at `k`.

- **vs max-heap of all:** wastes memory; finding kth needs extra work.
- **vs sorted multiset:** also O(log N) but stores everything.

## Logic Walkthrough
Constructor: push each num, pop if size > k. `add`: same push/trim, return `top()`.

## Dry Run
`k=3`, nums `[4,5,8,2]` → heap `{4,5,8}`. `add(3)` → still `{4,5,8}` → 4. `add(5)` → `{5,5,8}` → 5. `add(10)` → `{5,8,10}` → 5.

## Time & Space Complexity
Each add **O(log k)**. Space **O(k)**. Why: heap ops on fixed window (section 4).

## Trade-offs & Alternatives
If `k` ≈ N, sorting once may be simpler for offline queries. Stream setting favors the heap.

## Common Mistakes / Edge Cases
Max-heap confusion; not trimming below size k before returning; empty heap when `nums` empty and no add yet (LC guarantees enough adds).

## Interview Follow-ups / Variations
Kth largest in array (215); sliding window median; dynamic k.

## Tags
`heap`, `design`, `stream`, `leetcode-703`, `difficulty:easy`
