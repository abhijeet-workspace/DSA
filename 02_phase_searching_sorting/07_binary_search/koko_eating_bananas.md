# Koko Eating Bananas

## Problem Statement
[LeetCode 875](https://leetcode.com/problems/koko-eating-bananas/) — piles of bananas; Koko eats at speed `k` (ceil hours per pile). Find minimum `k` to finish within `h` hours.

- **Inputs:** `vector<int> piles`, `int h`.
- **Output:** minimum integer speed `k`.
- **Valid answer:** smallest `k` with `canEatAll` true.
- **Edges:** `h == piles.size()` (must eat max pile per hour); large piles.

## Intuition
Feasibility is monotonic in `k`: faster always finishes in ≤ hours. Binary search the answer in `[1, max(pile)]`.

## Brute Force → Optimal
- **Brute:** try every `k` from 1..max — O(max · N).
- **Optimal:** search-on-answer — O(N log MaxPile).

## Data Structure / Approach Justification
**Chosen:** `canEatAll` with ceiling `(pile + k - 1) / k` and BS minimizing feasible `k`.

- **vs linear scan of k:** same check, worse asymptotics.
- **vs math closed form:** messy with ceils; BS is clean and general.

## Logic Walkthrough
`low=1`, `high=max pile`. Mid speed feasible → record `ans`, try slower (`high = mid-1`); else `low = mid+1`.

## Dry Run
`piles = [3,6,7,11]`, `h = 8`:
- speed 4 works (hours 1+2+2+3=8); speed 3 fails → answer 4

## Time & Space Complexity
Time **O(N log MaxPile)**. Space **O(1)**. Why: log speeds × linear feasibility (section 4).

## Trade-offs & Alternatives
Same pattern as capacity / ship packages / split array largest sum.

## Common Mistakes / Edge Cases
Integer overflow on hours sum (`long long`); `k = 0`; using floor instead of ceil.

## Interview Follow-ups / Variations
Aggressive cows (maximize min); ship packages within D days.

## Tags
`binary-search`, `search-on-answer`, `difficulty:medium`
