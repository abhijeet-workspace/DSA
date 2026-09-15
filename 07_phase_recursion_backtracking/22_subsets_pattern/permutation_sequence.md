# Permutation Sequence

## 1. Problem Statement
[LeetCode 60](https://leetcode.com/problems/permutation-sequence/) — given `n` and `k`, return the `k`-th permutation of `[1,2,...,n]` in lexicographic order (1-indexed).

- **Inputs:** `int n`, `int k`.
- **Output:** string of the permutation.
- **Valid answer:** exactly the k-th of n! ordered perms.
- **Edges:** `k=1` first; `k=n!` last; `n=1`.

## 2. Intuition
Factorial number system: for position, group size is `(n-1)!`; choose digit by `k / (n-1)!`, shrink `k`, remove used digit.

## 3. Brute Force → Optimal
- **Brute:** generate all n! permutations — too slow for n≤9 but wasteful.
- **Optimal:** O(n²) digit selection with factorial indexing.

## 4. Data Structure / Approach Justification
**Chosen:** list of remaining digits + precomputed factorials.

- **vs next_permutation k times:** slower and less instructional for cascade.
- **vs full backtracking:** unnecessary when only one answer needed.

## 5. Logic Walkthrough
Build `fact`. Convert `k` to 0-based. For each length `i=n..1`: pick `idx=k/fact[i-1]`, append that digit, erase it, `k%=fact[i-1]`.

## 6. Dry Run
`n=3`, `k=3`: digits `[1,2,3]`, `2!=2` → idx=1 → `2`, remain `[1,3]`, k=0 → `1` then `3` → `"213"`.

## 7. Time & Space Complexity
Time **O(n²)** (erase from vector). Space **O(n)**. Why: n picks with linear erase (section 4).

## 8. Trade-offs & Alternatives
Linked list erase is O(n) too. Math-only without erase needs careful indexing.

## 9. Common Mistakes / Edge Cases
Forgetting 1-index → 0-index; off-by-one on factorial; mutating wrong digit list.

## 10. Interview Follow-ups / Variations
Next permutation; k-th combination; generate all perms.

## 11. Tags
`math`, `factorial-number-system`, `leetcode-60`, `difficulty:hard`
