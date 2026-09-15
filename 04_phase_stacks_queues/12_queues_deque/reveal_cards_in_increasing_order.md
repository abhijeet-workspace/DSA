# Reveal Cards In Increasing Order

## 1. Problem Statement
[LeetCode 950](https://leetcode.com/problems/reveal-cards-in-increasing-order/) — deck is revealed by: take top, then move new top to bottom, repeat. Return an ordering of `deck` such that revealed values are sorted ascending.

- **Inputs:** `vector<int> deck` (distinct).
- **Output:** arrangement of the same multiset that reveals in increasing order.
- **Edges:** `n=1`; `n=2`; already sorted.

## 2. Intuition
Simulate the reveal on **indices** with a deque: place the next smallest card into the next revealed index, then rotate the remaining index queue the same way the deck rotates.

## 3. Brute Force → Optimal
- **Brute:** try permutations — factorial.
- **Optimal:** sort cards + deque of indices — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** `deque` of remaining positions mirroring reveal ops.

| Alternative | Note |
|-------------|------|
| Reverse simulation from empty | Also works; similar complexity |
| Linked list of slots | Same idea, more code |

## 5. Logic Walkthrough
1. Sort `deck` ascending.
2. Fill deque with indices `0..n-1`.
3. For each sorted card: assign to `front` index; pop; if deque non-empty, move new front to back.

## 6. Dry Run
`[17,13,11,2,3,5,7]` → sorted; index process yields `[2,13,3,11,5,17,7]`.

## 7. Time & Space Complexity
- **Time:** O(N log N) sort + O(N) placement.
- **Space:** O(N) deque and result.

## 8. Trade-offs & Alternatives
Building the deck by reversing ops (start from last reveal) avoids storing indices but is easier to get wrong.

## 9. Common Mistakes / Edge Cases
Rotating after last card; not sorting first; mutating deck order while simulating reveal on values instead of indices.

## 10. Interview Follow-ups / Variations
Josephus / circular elimination; reconstruct queue by height (406).

## 11. Tags
`queue`, `deque`, `sorting`, `simulation`, `leetcode-950`, `difficulty:medium`
