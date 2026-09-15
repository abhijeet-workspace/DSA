# Furthest Building You Can Reach

## 1. Problem Statement
[LeetCode 1642](https://leetcode.com/problems/furthest-building-you-can-reach/) — given `heights`, `bricks`, and `ladders`, climb as far as possible. Uphill costs bricks equal to the height difference or one ladder. Return the furthest index reachable.

## 2. Intuition
Ladders should cover the largest climbs. Keep ladder-assigned diffs in a min-heap; when you exceed `ladders`, convert the smallest ladder climb into bricks.

## 3. Brute Force → Optimal
- **Brute:** try every assignment of ladders to climbs — exponential.
- **Optimal:** online min-heap reallocation — O(N log L).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of diffs currently covered by ladders; overflow pops onto brick budget.

- **vs sorting all diffs upfront:** decisions are path-order constrained.
- **vs DP on (index, ladders):** too heavy for interview constraints.

## 5. Logic Walkthrough
For each positive climb, push into ladder heap. If size > ladders, add popped min to bricks. If bricks exceed budget, return current index.

## 6. Dry Run
`[4,2,7,6,9,14,12]`, bricks=5, ladders=1 → furthest index **4**.

## 7. Time & Space Complexity
Time **O(N log L)**. Space **O(L)**. Why: bounded heap of ladder climbs (section 4).

## 8. Trade-offs & Alternatives
Equivalent dual: max-heap of brick climbs. Both are O(N log N)-class greedy.

## 9. Common Mistakes / Edge Cases
Charging downhill; not reallocating ladders; overflowing 32-bit brick sums.

## 10. Interview Follow-ups / Variations
Min ladders to finish; streaming heights; with jump constraints.

## 11. Tags
`heap`, `greedy`, `leetcode-1642`, `difficulty:medium`
