# Assign Cookies

## 1. Problem Statement
[LeetCode 455](https://leetcode.com/problems/assign-cookies/) — each child has greed factor `g[i]`; each cookie has size `s[j]`. Assign at most one cookie per child; child is content if `s[j] >= g[i]`. Maximize content children.

- **Inputs:** `vector<int> g`, `vector<int> s`.
- **Output:** max number of content children.
- **Edges:** no cookies; all cookies too small; one child; equal sizes.

## 2. Intuition
Satisfy the greediest-capable children with the smallest sufficient cookie — sort both arrays and two-pointer walk.

## 3. Brute Force → Optimal
- **Brute:** try all assignments — exponential.
- **Optimal:** sort + two pointers — O(N log N + M log M).

## 4. Data Structure / Approach Justification
**Chosen:** sort `g` and `s`, advance child only when cookie fits.

| Alternative | Why skip |
|-------------|---------|
| Max-heap of cookies | Extra structure; sort+scan is enough |
| Match largest child first with largest cookie | Also correct; smallest-fit is classic LC solution |

## 5. Logic Walkthrough
1. Sort greed and sizes ascending.
2. `i=0`, `j=0`; while both in range: if `s[j] >= g[i]`, `++i`; always `++j`.
3. Return `i` (content count).

## 6. Dry Run
`g=[1,2,3]`, `s=[1,1]`: cookie 1 feeds child 1; next cookie 1 fails for child 2 → **1**.

## 7. Time & Space Complexity
- **Time:** O(N log N + M log M)
- **Space:** O(1) extra (sort in place) / O(log N) stack depending on sort

## 8. Trade-offs & Alternatives
Largest-first also works; same asymptotics. Sorting dominates.

## 9. Common Mistakes / Edge Cases
Advancing child when cookie is too small; reusing cookies; empty `s`.

## 10. Interview Follow-ups / Variations
Cookies with multiple uses; minimize leftover size under content constraint.

## 11. Tags
`greedy`, `two-pointers`, `sorting`, `leetcode-455`, `difficulty:easy`
