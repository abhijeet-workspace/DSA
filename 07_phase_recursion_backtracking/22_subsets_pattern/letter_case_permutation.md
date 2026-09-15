# Letter Case Permutation

## 1. Problem Statement
[LeetCode 784](https://leetcode.com/problems/letter-case-permutation/) — for string `s`, return all strings we can form by changing the case of letters (digits stay fixed).

- **Inputs:** string `s` (letters + digits).
- **Output:** all distinct case variants.
- **Valid answer:** 2^(#letters) strings.
- **Edges:** all digits; all letters; empty.

## 2. Intuition
Include/exclude style on each letter: branch lowercase and uppercase; digits have one branch.

## 3. Brute Force → Optimal
- **Brute:** same as optimal for small letter counts.
- **Optimal:** DFS/BFS over letter positions — O(n · 2^L).

## 4. Data Structure / Approach Justification
**Chosen:** in-place DFS mutating `s` then restoring via overwrite.

- **vs building new strings:** more copying.
- **vs BFS queue of prefixes:** same complexity, more memory.

## 5. Logic Walkthrough
At index `i`: if digit, advance; else set lower recurse, set upper recurse.

## 6. Dry Run
`"a1b2"` → `a1b2`, `a1B2`, `A1b2`, `A1B2` (4).

## 7. Time & Space Complexity
Time **O(n · 2^L)**. Space **O(n)** recursion (+ output). Why: branch per letter (section 4).

## 8. Trade-offs & Alternatives
Bitmask over letter positions if you collect letter indices first.

## 9. Common Mistakes / Edge Cases
Toggling digits; missing one case branch; locale/ctype unsigned char issues.

## 10. Interview Follow-ups / Variations
Only first letter case; generate with constraints; subsets of toggle positions.

## 11. Tags
`backtracking`, `bit-manipulation`, `leetcode-784`, `difficulty:medium`
