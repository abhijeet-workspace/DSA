# Insert Delete GetRandom O(1)

## Problem Statement
[LeetCode 380](https://leetcode.com/problems/insert-delete-getrandom-o1/) — design a set with `insert`, `remove`, and `getRandom` in average O(1).

- **Inputs:** sequence of operations on integers.
- **Output:** insert/remove bools; random element uniformly from current set.
- **Edges:** remove missing; insert duplicate; single element.

## Intuition
Vector gives O(1) random index; hash map gives O(1) locate. On remove, swap with last then pop.

## Brute Force → Optimal
- **Brute:** `unordered_set` alone — random is O(N).
- **Optimal:** vector + value→index map — all O(1) amortized.

## Data Structure / Approach Justification
**Chosen:** `vals_` + `idx_`.

- **vs linked list:** random access is O(N).
- **vs tree set:** log N ops.

## Logic Walkthrough
`insert`: push and map index. `remove`: swap target with last, update map, pop. `getRandom`: index `rand() % size`.

## Dry Run
insert 1, insert 2, remove 1 → only 2 remains; getRandom → 2.

## Time & Space Complexity
Time **O(1)** amortized per op. Space **O(N)**.

## Trade-offs & Alternatives
Duplicates version needs multiset of indices.

## Common Mistakes / Edge Cases
Forgetting to update swapped element's map index; erase before reading last.

## Interview Follow-ups / Variations
Allow duplicates (381); weighted random.

## Tags
`design`, `hash-map`, `array`, `difficulty:medium`
