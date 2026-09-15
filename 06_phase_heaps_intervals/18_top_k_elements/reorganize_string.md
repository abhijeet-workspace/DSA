# Reorganize String

## 1. Problem Statement
[LeetCode 767](https://leetcode.com/problems/reorganize-string/) — rearrange `s` so no two adjacent characters are equal. Return `""` if impossible.

- **Inputs:** lowercase string `s`.
- **Output:** any valid rearrangement or empty string.
- **Valid answer:** adjacent chars differ; same multiset of characters.
- **Edges:** all unique; one char dominates; length 1; impossible majority.

## 2. Intuition
Always emit the currently most frequent remaining character that is not equal to the last emitted. Max-heap by count; hold the previous pick out for one turn so it is not adjacent to itself.

## 3. Brute Force → Optimal
- **Brute:** try all permutations — factorial.
- **Optimal:** greedy max-heap (or place most frequent on even slots) — O(N log A), A=26.

## 4. Data Structure / Approach Justification
**Chosen:** frequency array + max-heap of `(count, char)`.

- **vs even-index fill:** also O(N); heap is the general “task scheduler” style pattern.
- **vs backtracking:** too slow for interview constraints.

## 5. Logic Walkthrough
Count letters. Heap them. While heap non-empty: pop top, append, decrement; push previous leftover if count > 0; set previous to current leftover. If result length < |s|, impossible.

## 6. Dry Run
`aab`: heap `(2,a),(1,b)` → place a → hold a → place b → reinsert a → `aba`.

`aaab`: after placing a,b,a leftover a must sit next to a → result short → `""`.

## 7. Time & Space Complexity
Time **O(N log A)**. Space **O(A)**. Why: N heap ops over alphabet size (section 4).

## 8. Trade-offs & Alternatives
Even-slot method is O(N) and simpler for alphabet-26. Heap generalizes to “reorganize with distance k”.

## 9. Common Mistakes / Edge Cases
Not detecting impossibility when max freq > (n+1)/2; forgetting to reinsert previous; using min-heap.

## 10. Interview Follow-ups / Variations
Task Scheduler (621); rearrange string k distance apart; reorganize with constraints on groups.

## 11. Tags
`heap`, `greedy`, `string`, `leetcode-767`, `difficulty:medium`
