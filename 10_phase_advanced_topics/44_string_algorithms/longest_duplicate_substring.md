# Longest Duplicate Substring

## 1. Problem Statement
[LeetCode 1044](https://leetcode.com/problems/longest-duplicate-substring/) — longest substring that occurs at least twice (overlap allowed).

- **Inputs:** string `s`.
- **Output:** that substring (any if ties).
- **Valid answer:** max length duplicate; empty if none.
- **Edges:** all unique; all same char.

## 2. Intuition
Binary search length L; rolling hash checks if any hash of windows of size L repeats.

## 3. Brute Force → Optimal
- **Brute:** all pairs of substrings.
- **Optimal:** binsearch + RK — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** binary search on length + double-ish single MOD hash with start index map.

- **vs suffix array:** O(N) build heavier to code.

## 5. Logic Walkthrough
For mid L: compute window hashes; if collision of equal strings, record. Shrink/expand search.

## 6. Dry Run
`s="banana"` → `"ana"`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Suffix array/automaton is deterministic without hash risk.

## 9. Common Mistakes / Edge Cases
Hash collisions; not verifying string equality on hash hit.

## 10. Interview Follow-ups / Variations
Distinct Echo; Rabin–Karp.

## 11. Tags
`rolling-hash`, `binary-search`, `leetcode-1044`, `difficulty:hard`
