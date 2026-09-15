# Flatten Nested List Iterator

## Problem Statement
[LeetCode 341](https://leetcode.com/problems/flatten-nested-list-iterator/) — design iterator over nested list of integers with `next` / `hasNext`.

- **Inputs:** nested structure of ints and lists.
- **Output:** flattened stream of integers in order.
- **Valid answer:** DFS order left-to-right.
- **Edges:** empty lists; deeply nested; single int.

## Intuition
Stack of NestedInteger; expand lists on demand so `next` is always an integer on top.

## Brute Force → Optimal
- **Brute:** fully flatten into vector up front — O(N) memory always.
- **Optimal:** lazy stack expansion — same worst-case, better when iteration stops early.

## Data Structure / Approach Justification
**Chosen:** stack; push list elements in reverse.

- **vs recursion flatten:** loses laziness.

## Logic Walkthrough
Init push reversed top-level. `skipToInteger` pops lists and pushes children reversed until top is int.

## Dry Run
`[[1,1],2]` → expand first list → stream `1,1,2`.

## Time & Space Complexity
Amortized **O(1)** per next over all elements. Space **O(depth + breadth)**.

## Trade-offs & Alternatives
Eager flatten simplifies code for small inputs.

## Common Mistakes / Edge Cases
Empty nested lists left on stack; wrong child push order.

## Interview Follow-ups / Variations
Nested List Weight Sum (339/364); BST iterator.

## Tags
`stack`, `iterator`, `design`, `leetcode-341`, `difficulty:medium`
