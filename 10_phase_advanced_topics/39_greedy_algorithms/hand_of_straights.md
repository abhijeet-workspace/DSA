# Hand of Straights

## Problem Statement
[LeetCode 846](https://leetcode.com/problems/hand-of-straights/) — rearrange cards into groups of `groupSize` consecutive values.

- **Inputs:** `hand` multiset of ints; `groupSize`.
- **Output:** true iff a full partition into straights exists.
- **Valid answer:** any valid grouping implies true.
- **Edges:** length not divisible by `groupSize`; gaps in values; duplicates.

## Intuition
Always start a new group at the smallest remaining card; consume `groupSize` consecutive counts. If any count is missing, fail.

## Brute Force → Optimal
- **Brute:** try all partitions — exponential.
- **Optimal:** ordered frequency map + greedy consume — O(N log N).

## Data Structure / Approach Justification
**Chosen:** `std::map<int,int>` for sorted keys and counts.

- **vs sort + scan:** similar; map makes erase-at-zero easy.
- **vs hash only:** need an external min each time.

## Logic Walkthrough
Reject if `n % groupSize != 0`. Count frequencies. While map non-empty: take min key `start`; for `i in 0..groupSize-1` decrement `start+i` or fail.

## Dry Run
`hand=[1,2,3,6,2,3,4,7,8]`, `groupSize=3` → groups `{1,2,3}`, `{2,3,4}`, `{6,7,8}` → true.

## Time & Space Complexity
Time **O(N log N)** map ops. Space **O(N)**. Why: each card decremented once (section 4).

## Trade-offs & Alternatives
`priority_queue` of unique values works similarly. Hash + sorted unique keys also fine.

## Common Mistakes / Edge Cases
Not checking divisibility; skipping over a missing middle value; leaving zero counts in the map.

## Interview Follow-ups / Variations
LC 1296 Divide Array in Sets of K Consecutive. Allow wrap-around?

## Tags
`greedy`, `hash-map`, `sorting`, `difficulty:medium`
