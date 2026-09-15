# Rotate String

## 1. Problem Statement
[LeetCode 796](https://leetcode.com/problems/rotate-string/) — true iff `s` can become `goal` after some rotations.

- **Inputs:** `s`, `goal`.
- **Output:** bool.
- **Valid answer:** exact.
- **Edges:** different lengths; identical.

## 2. Intuition
Rotation means `goal` is a substring of `s+s` (same length).

## 3. Brute Force → Optimal
- **Brute:** try all rotations.
- **Optimal:** substring search in `s+s` — O(N) with KMP.

## 4. Data Structure / Approach Justification
**Chosen:** length check + `(s+s).find(goal)`.

## 5. Logic Walkthrough
If sizes differ false; else search goal in s+s.

## 6. Dry Run
`s="abcde"`, `goal="cdeab"` → true.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
KMP avoids relying on STL find internals.

## 9. Common Mistakes / Edge Cases
Skipping length check; empty strings.

## 10. Interview Follow-ups / Variations
Repeated substring; strStr.

## 11. Tags
`string`, `kmp`, `leetcode-796`, `difficulty:easy`
