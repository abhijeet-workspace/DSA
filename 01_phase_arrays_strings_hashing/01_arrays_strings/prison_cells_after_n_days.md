# Prison Cells After N Days

## Problem Statement
[LeetCode 957](https://leetcode.com/problems/prison-cells-after-n-days/) — 8 cells evolve: ends become 0; middle is 1 iff left==right neighbor. Return state after `n` days.

- **Inputs:** `cells[8]`, day count `n` (up to 1e9).
- **Output:** cells after `n` transitions.
- **Valid answer:** deterministic next-state rule.
- **Edges:** n=1; already cyclic; all zeros.

## Intuition
Only 2^8=256 states → must cycle. Detect cycle and jump remainder.

## Brute Force → Optimal
- **Brute:** simulate n steps — TLE for 1e9.
- **Optimal:** map mask→day; on revisit, `remain = (n-day) % cycle`.

## Data Structure / Approach Justification
**Chosen:** bitmask + `unordered_map`.

- **vs find period 14 empirically:** works for this problem but cycle map is general.

## Logic Walkthrough
Each day hash state; if seen, recurse/simulate remaining mod cycle length; else advance.

## Dry Run
`[0,1,0,1,1,0,1,0]` → day1 `[0,1,1,0,0,1,1,0]`; period 7 returns to start. Large `n` reduces via `(n-day)%cycle`.

## Time & Space Complexity
Time **O(2^8 · 8)**. Space **O(2^8)**. Why: bounded state space.

## Trade-offs & Alternatives
Hardcode period-14 after first day (ends always 0) — shorter but less explanatory.

## Common Mistakes / Edge Cases
Forgetting ends are always 0 next day; off-by-one on cycle length.

## Interview Follow-ups / Variations
General cellular automata with cycle detection.

## Tags
`array`, `simulation`, `cycle-detection`, `leetcode-957`, `difficulty:medium`
