# Reverse Prefix of Word

## 1. Problem Statement
[LeetCode 2000](https://leetcode.com/problems/reverse-prefix-of-word/) — Reverse the prefix of `word` that ends at the **first** occurrence of `ch`. If `ch` is absent, return `word` unchanged.

- **Inputs:** `string word`, `char ch`.
- **Output:** Modified string.
- **Edges:** `ch` at index 0; `ch` missing; `ch` at the end.

## 2. Intuition
Find the first index of `ch`, then reverse the closed range `[0, idx]`.

## 3. Brute Force → Optimal
Manual two-index swap on that range equals `std::reverse` — same O(L) where L is prefix length.

## 4. Data Structure / Approach Justification
**Chosen:** `find` + `reverse` on a half-open iterator range.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| Explicit `L`/`R` swap loop named “two pointers” | Same work; vocabulary is topic 7 |

This can look like a two-pointer solution, and a two-pointer formulation also works (and may even be more idiomatic once that pattern is formal). We solve it here via **direct position arithmetic / index scans** on purpose: this topic builds string scan-and-build fluency before the formal two-pointer pattern is introduced in topic 7.

## 5. Logic Walkthrough
1. `pos = first index of ch` (or npos).
2. If missing, return `word`.
3. Reverse `[0, pos]` inclusive.
4. Return `word`.

## 6. Dry Run
`abcdefd`, `ch='d'` → first `d` at 3 → reverse `abcd` → `dcbaefd`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra

## 8. Trade-offs & Alternatives
Building a new string from reversed prefix + suffix is clearer to some; uses O(N) space.

## 9. Common Mistakes / Edge Cases
Reversing past the first `ch`; off-by-one on inclusive end; mutating when `ch` absent.

## 10. Interview Follow-ups / Variations
Reverse every prefix ending at `ch`; reverse suffix instead.

## 11. Tags
`string`, `reverse`, `leetcode-2000`, `difficulty:easy`
