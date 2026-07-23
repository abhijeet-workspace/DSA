# Last Stone Weight

## Problem Statement
[LeetCode 1046](https://leetcode.com/problems/last-stone-weight/) — repeatedly smash the two heaviest stones; return the last remaining weight (or 0).

- **Inputs:** `vector<int> stones` (positive weights).
- **Output:** weight of the final stone, or `0` if none.
- **Valid answer:** smash `x ≥ y`: if equal both destroyed; else insert `x - y`.
- **Edges:** one stone; all equal; already empty after last equal smash.

## Intuition
Always need the current two maxima → max-heap. Each smash is pop-pop-(maybe push).

## Brute Force → Optimal
- **Brute:** each step scan for two maxes — O(N²).
- **Optimal:** max-heap — O(N log N) for up to N-1 smash rounds.

## Data Structure / Approach Justification
**Chosen:** `priority_queue<int>` max-heap seeded from `stones`.

- **vs sorted array / multiset:** similar asymptotics; heap matches “always take heaviest” cleanly.
- **vs repeated linear scan:** too slow for interview constraints.

## Logic Walkthrough
While heap size > 1: pop `a`, pop `b`; if `a != b`, push `a - b`. Return `0` if empty else top.

## Dry Run
`stones=[2,7,4,1,8,1]`:
- smash 8,7 → push 1 → `{4,2,1,1,1}`
- smash 4,2 → push 2 → `{2,1,1,1}`
- smash 2,1 → push 1 → `{1,1,1}`
- smash 1,1 → destroy → `{1}` → **1**

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)** for the heap. Why: ≤ N-1 rounds, each O(log N) heap ops (section 4).

## Trade-offs & Alternatives
`multiset` also works; slightly heavier API. Sorting each round is worse constant/clarity. Simulation is the intended approach — no closed form needed.

## Common Mistakes / Edge Cases
Pushing `b - a` when assuming order; forgetting equal stones destroy both; returning heap top without empty check.

## Interview Follow-ups / Variations
Last stone weight II (partition / knapsack flavor); minimize leftover with different smash rules.

## Tags
`heap`, `max-heap`, `simulation`, `leetcode-1046`, `difficulty:easy`
