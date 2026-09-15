# Logger Rate Limiter

## Problem Statement
[LeetCode 359](https://leetcode.com/problems/logger-rate-limiter/) — allow printing a message only if it was not printed in the previous 10 seconds.

- **Inputs:** `timestamp` (non-decreasing), `message`.
- **Output:** bool whether to print.
- **Edges:** first print; exactly 10 seconds later.

## Intuition
Store last print time per message; reject if `timestamp - last < 10`.

## Brute Force → Optimal
- **Brute:** queue of all prints — cleanup each call.
- **Optimal:** hash map message→last time — O(1).

## Data Structure / Approach Justification
**Chosen:** `unordered_map` of last timestamps.

## Logic Walkthrough
If missing or gap ≥ 10, update map and return true; else false.

## Dry Run
t=1 foo ok; t=3 foo blocked; t=11 foo ok.

## Time & Space Complexity
Time **O(1)** average. Space **O(U)** unique messages.

## Trade-offs & Alternatives
Queue+set for TTL eviction of old keys (memory-bounded).

## Common Mistakes / Edge Cases
Using `<=` vs `<` on the 10-second window.

## Interview Follow-ups / Variations
Hit counter; per-user rate limits.

## Tags
`design`, `hash-map`, `difficulty:easy`
