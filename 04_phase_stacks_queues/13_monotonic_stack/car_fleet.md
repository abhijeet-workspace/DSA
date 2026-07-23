# Car Fleet

## Problem Statement
[LeetCode 853](https://leetcode.com/problems/car-fleet/) — cars drive toward `target` on a single lane; a faster car behind cannot pass and forms a fleet with a slower car ahead. Return number of fleets that arrive.

- **Inputs:** `int target`, `position[]`, `speed[]` (same length).
- **Output:** fleet count.
- **Edges:** one car; all same arrival time (one fleet); car already at target; no catch-ups.

## Intuition
Sort by position. Scan from closest-to-target backward: a car that needs strictly more time than the fleet ahead starts a new fleet; otherwise it merges.

## Brute Force → Optimal
- **Brute:** simulate steps — messy with floats/ties.
- **Optimal:** sort by position + single reverse pass on arrival times — O(N log N).

## Data Structure / Approach Justification
**Chosen:** `(position, time)` pairs sorted by position; track max time seen from the front.

- **vs stack of times:** equivalent (push when time increases); reverse scan is enough.
- **vs simulation:** harder correctness with continuous speeds.

## Logic Walkthrough
`time = (target - pos) / speed`. Sort ascending position. From right: if `time > cur`, new fleet and `cur = time`; else merges into `cur`.

## Dry Run
`target=12`, `pos=[10,8,0,5,3]`, `speed=[2,4,1,1,3]`:
- times ≈ `[1,1,12,7,3]`; from front: fleets at times `1`, then `3`, then `12` → **3**.

## Time & Space Complexity
Time **O(N log N)** (sort). Space **O(N)** for pairs. Why: catch-up depends only on relative order and times (section 4).

## Trade-offs & Alternatives
Stack of increasing times from the right is the same idea with explicit stack framing.

## Common Mistakes / Edge Cases
Integer division of times; sorting by speed; counting merges as new fleets; floating compare ties (equal time = same fleet).

## Interview Follow-ups / Variations
Car fleet II (collision times); multiple lanes; discrete simulation.

## Tags
`sorting`, `stack`, `greedy`, `difficulty:medium`
