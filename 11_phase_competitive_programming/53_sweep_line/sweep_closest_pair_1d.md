# Sweep Closest Pair 1D

## Problem Statement
Given intervals on a line, compute the total length of their **union** (1D sweep teaching stand-in; filename is historical).

- **Inputs:** list of half-open-style intervals `[L,R)` with `L < R`.
- **Output:** measure of covered points (sum of lengths of merged coverage).
- **Valid answer:** Lebesgue measure of the union on the real line.
- **Edges:** empty; nested; touching endpoints; zero-length skipped.

## Intuition
Sweep with `+1` at starts and `-1` at ends. Whenever `active > 0`, add `(x - prevX)` to the answer between consecutive events.

## Brute Force → Optimal
- **Brute / merge:** sort & merge intervals then sum `(R-L)` — also `O(N log N)`.
- **Optimal sweep:** same asymptotics; generalizes to “covered by ≥K”.

## Data Structure / Approach Justification
**Chosen:** event array sorted by `x`, ends before starts at ties.

- **vs merge intervals:** shorter for pure union length.
- **vs segment tree coverage:** overkill in 1D static case.

## Logic Walkthrough
Build events; sort; scan updating `active`; add delta-x only while `active > 0`.

## Dry Run
`[1,5],[2,3],[6,8]` → cover `[1,5] ∪ [6,8]` = `4+2=6`.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort dominates; scan is linear (section 4).

## Trade-offs & Alternatives
Merge is shorter for pure union length; sweep generalizes to length covered by ≥`K` intervals by checking `active >= K`.

## Common Mistakes / Edge Cases
Adding length between every event without checking `active`; double-counting overlaps; wrong tie-break at shared endpoints.

## Interview Follow-ups / Variations
Length covered by at least `K` intervals? 2D union area?

## Tags
`sweep-line`, `intervals`, `union-length`, `events`, `difficulty:easy`
