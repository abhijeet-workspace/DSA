# Remove Stones to Minimize the Total

## 1. Problem Statement
[LeetCode 1962](https://leetcode.com/problems/remove-stones-to-minimize-the-total/) — in one op, choose a pile `x` and remove `floor(x/2)` stones; after `k` ops return remaining sum.

- **Inputs:** `piles`, `k`.
- **Output:** minimum possible total stones left.
- **Valid answer:** always operate on current largest pile.
- **Edges:** k=0; single pile; already small piles.

## 2. Intuition
Largest pile yields the biggest absolute reduction — max-heap greedy.

## 3. Brute Force → Optimal
- **Brute:** explore which pile each step — exponential.
- **Optimal:** max-heap — O(K log N).

## 4. Data Structure / Approach Justification
**Chosen:** max-heap of pile sizes.

- **Adjacent:** same family as halve-array-sum / k operations score.

## 5. Logic Walkthrough
Push all piles. k times: pop max x, push x - x/2. Sum remaining.

## 6. Dry Run
`[5,4,9]`, k=2: 9→5 → piles 5,5,4; 5→3 → sum **12**.

## 7. Time & Space Complexity
Time **O((N+K) log N)**. Space **O(N)**. Why: heap ops (section 4).

## 8. Trade-offs & Alternatives
Simple single-heap practice adjacent to two-heaps scheduling.

## 9. Common Mistakes / Edge Cases
Using ceil instead of floor; integer truncation direction; summing before ops.

## 10. Interview Follow-ups / Variations
Minimum Operations to Halve Array Sum (2208); Maximal Score After K Operations (2530).

## 11. Tags
`heap`, `greedy`, `leetcode-1962`, `difficulty:medium`
