# Majority Element

## Problem Statement
[LeetCode 169](https://leetcode.com/problems/majority-element/) — return the element that appears more than `⌊n / 2⌋` times. A majority element is guaranteed to exist.

- **Inputs:** `vector<int> nums` of length `n ≥ 1`.
- **Output:** the majority value.
- **Valid answer:** unique element with frequency `> n/2`.
- **Edges:** `n = 1`; all equal; majority at start/end; alternating cancellations.

## Intuition
Different values cancel in pairs. Because majority occurs more often than all others combined, it cannot be fully cancelled and remains the final candidate.

## Brute Force → Optimal
- **Brute:** for each value, count frequency — O(N²).
- **Hash map:** count all frequencies — O(N) time, O(N) space.
- **Sort:** majority sits at index `n/2` — O(N log N) time.
- **Optimal:** Boyer-Moore voting — O(N) time, O(1) space.

## Data Structure / Approach Justification
**Chosen:** Boyer-Moore (`candidate`, `count`) — one pass, constant memory.

- **vs hash map:** same time but uses O(N) memory.
- **vs sort:** slower; mutates or copies the array.

## Logic Walkthrough
Start with `count = 0`. For each `x`: if `count == 0`, set `candidate = x`; then `count += (x == candidate) ? 1 : -1`. Return `candidate`.

## Dry Run
`nums = [2,2,1,1,1,2,2]`:
- 2 → cand=2, count=1
- 2 → count=2
- 1 → count=1
- 1 → count=0
- 1 → cand=1, count=1
- 2 → count=0
- 2 → cand=2, count=1 → return **2**

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one forward scan with two scalars.

## Trade-offs & Alternatives
If majority is *not* guaranteed, add a second pass to verify `candidate`'s frequency. Hash map is simpler when O(N) space is fine.

## Common Mistakes / Edge Cases
Returning early without finishing the pass; using `≥ n/2` instead of `> n/2`; skipping verification when the problem does not guarantee a majority.

## Interview Follow-ups / Variations
Majority Element II (229) — elements appearing `> n/3` (extend to two candidates); streaming / online majority.

## Tags
`array`, `boyer-moore`, `voting`, `difficulty:easy`
