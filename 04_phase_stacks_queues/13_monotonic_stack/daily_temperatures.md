# Daily Temperatures

## Problem Statement
[LeetCode 739](https://leetcode.com/problems/daily-temperatures/) — for each day, how many days until a strictly warmer temperature (0 if none).

- **Inputs:** `vector<int> temperatures`.
- **Output:** `vector<int>` same length; `answer[i]` = wait days.
- **Edges:** strictly decreasing (all zeros); strictly increasing (all ones except last); duplicates.

## Intuition
Unresolved cooler days wait on a stack. When a warmer day arrives, it resolves all colder days on top — classic next-greater-element.

## Brute Force → Optimal
- **Brute:** for each `i`, scan right until warmer — O(N²).
- **Optimal:** monotonic decreasing stack of indices — O(N) time/space.

## Data Structure / Approach Justification
**Chosen:** stack of indices with decreasing temperatures toward the top.

- **vs nested scan:** same answer, quadratic.
- **vs segment tree / sparse table:** heavier for interview next-greater.

## Logic Walkthrough
For each `i`, while stack top is colder than `temps[i]`, pop and set `res[prev] = i - prev`. Push `i`. Leftovers stay `0`.

## Dry Run
`temps=[73,74,75,71,69,72,76,73]`:
- `74` resolves `73` → `1`; `75` resolves `74` → `1`; `72` resolves `69,71`; `76` resolves `72,75` → final `1 1 4 2 1 1 0 0`

## Time & Space Complexity
Time **O(N)** (each index pushed/popped ≤ once). Space **O(N)** stack. Why: next-greater via monotonic stack (section 4).

## Trade-offs & Alternatives
Right-to-left with stack of candidates also works. Array as explicit stack can shave constants.

## Common Mistakes / Edge Cases
Using `<=` instead of `<` (equal is not warmer); storing values not indices; forgetting last days stay `0`.

## Interview Follow-ups / Variations
Next greater element I/II; online queries; days until colder; circular array.

## Tags
`stack`, `monotonic-stack`, `next-greater`, `difficulty:medium`
