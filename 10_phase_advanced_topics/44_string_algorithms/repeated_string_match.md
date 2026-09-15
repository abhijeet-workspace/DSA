# Repeated String Match

## 1. Problem Statement
[LeetCode 686](https://leetcode.com/problems/repeated-string-match/) — minimum times to repeat `a` so `b` is a substring; else `-1`.

- **Inputs:** strings `a`, `b`.
- **Output:** min repeats or `-1`.
- **Valid answer:** smallest k ≥ 1.
- **Edges:** `b` already in `a`; `b` longer than `a`.

## 2. Intuition
Need at most `ceil(|b|/|a|)+1` repeats for a wrapping match. Build `a*k` and KMP/search for `b`.

## 3. Brute Force → Optimal
- **Brute:** grow until length huge.
- **Optimal:** bound k ≤ |b|/|a|+2; KMP search.

## 4. Data Structure / Approach Justification
**Chosen:** construct `S=a*(need)` then KMP.

- **vs Rabin–Karp:** same bound.

## 5. Logic Walkthrough
Let `need = ceil(|b|/|a|)`; try `need` and `need+1` concatenations.

## 6. Dry Run
`a="abcd"`, `b="cdabcdab"` → **3**.

## 7. Time & Space Complexity
Time **O(|a|+|b|)**. Space **O(|a|+|b|)** for concatenation.

## 8. Trade-offs & Alternatives
Can stream KMP without full concat using modular indices.

## 9. Common Mistakes / Edge Cases
Stopping at `need` only (miss wrapping); empty strings.

## 10. Interview Follow-ups / Variations
Repeated Substring Pattern; strStr.

## 11. Tags
`kmp`, `string`, `leetcode-686`, `difficulty:medium`
