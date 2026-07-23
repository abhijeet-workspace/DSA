# Aggressive Cows

## Problem Statement
Classic SPOJ / GFG — place `k` cows in stalls so the **minimum** distance between any two is maximized.

- **Inputs:** stall positions `vector<int> stalls`, cow count `k`.
- **Output:** maximum achievable minimum distance.
- **Valid answer:** largest `minDist` with `isPossible` true.
- **Edges:** `k = 2` (answer = max−min); stalls unsorted; dense stalls.

## Intuition
Larger required distance is harder → monotonic. Binary search distance; greedily place cows left-to-right.

## Brute Force → Optimal
- **Brute:** try all placements — exponential / high poly.
- **Optimal:** sort + search-on-answer — O(N log N + N log D).

## Data Structure / Approach Justification
**Chosen:** sort stalls; BS `minDist` in `[1, max-min]`; greedy place if gap ≥ mid.

- **vs DP placements:** heavier; unnecessary under 1D stalls.
- **vs only sort + heuristics:** not optimal without search.

## Logic Walkthrough
`isPossible`: place first cow at `stalls[0]`; place next when gap ≥ `minDist`. If mid works, try larger (`low = mid+1`); else shrink.

## Dry Run
`stalls = [1,2,8,4,9]` → sorted `[1,2,4,8,9]`, `k = 3`:
- distance 3 feasible (cows at 1,4,9); 4 not → answer 3

## Time & Space Complexity
Time **O(N log N + N log D)** (sort + BS). Space **O(1)** extra if sorting in place. Why: monotonic check (section 4).

## Trade-offs & Alternatives
Same family as Koko / book allocation / magnetic force between balls (LC 1552).

## Common Mistakes / Edge Cases
Forgetting to sort; placing `k` cows with `k > n`; off-by-one on distance bounds.

## Interview Follow-ups / Variations
Minimize max load (opposite monotonic direction).

## Tags
`binary-search`, `search-on-answer`, `greedy`, `difficulty:medium`
