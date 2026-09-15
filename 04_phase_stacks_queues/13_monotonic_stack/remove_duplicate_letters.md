# Remove Duplicate Letters

## 1. Problem Statement
[LeetCode 316](https://leetcode.com/problems/remove-duplicate-letters/) — return the lexicographically **smallest** subsequence of `s` that contains each distinct character exactly once. (Same as LC 1081.)

- **Inputs:** lowercase string `s`.
- **Output:** unique-letter subsequence string.
- **Edges:** already unique sorted; reverse sorted with duplicates; single character.

## 2. Intuition
Greedy stack: keep letters increasing when possible. Pop a larger letter only if it appears again later (safe to pick later for a smaller prefix). Skip letters already chosen.

## 3. Brute Force → Optimal
- **Brute:** generate all unique-letter subsequences — exponential.
- **Optimal:** last-occurrence array + monotonic increasing stack — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** stack of chars + `in_stack[26]` + `last[26]`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Sort unique letters | Order must remain a subsequence |
| Recursion / backtracking | Too slow; stack greedy is optimal |

## 5. Logic Walkthrough
1. Record last index of each letter.
2. For each `c` at `i`: if already in stack, skip.
3. While top `> c` and top still appears after `i`, pop top.
4. Push `c` and mark present.

## 6. Dry Run
`s="bcabc"`:
- build `b,c`; at `a`, pop `c` then `b` (both recur later) → push `a` → then `b,c` → `"abc"`.

## 7. Time & Space Complexity
- **Time:** O(N) — each char enters/leaves stack ≤ once.
- **Space:** O(1) alphabet auxiliaries + O(σ) stack (σ ≤ 26).

## 8. Trade-offs & Alternatives
Same as “smallest subsequence of distinct characters.” Remove K digits is the digit analog without the “must keep every letter” constraint.

## 9. Common Mistakes / Edge Cases
Popping when letter does not appear later; pushing duplicates; forgetting `in_stack` so duplicates re-enter; treating uppercase / non-letters.

## 10. Interview Follow-ups / Variations
Remove k digits; create maximum number; lexicographically smallest string after removals with different constraints.

## 11. Tags
`stack`, `greedy`, `monotonic-stack`, `string`, `leetcode-316`, `difficulty:medium`
