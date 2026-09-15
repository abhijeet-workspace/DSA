# Reverse String (Recursive)

## 1. Problem Statement
[LeetCode 344](https://leetcode.com/problems/reverse-string/) — Reverse a character array in-place.

- **Inputs:** `vector<char>& s`.
- **Output:** In-place reverse.
- **Edges:** Length 0/1; even/odd length.

## 2. Intuition
Swap ends, recurse on the inner segment.

## 3. Brute Force → Optimal
Iterative two indices — standard. Recursion shows stack frames mirroring the swaps.

## 4. Data Structure / Approach Justification
**Chosen:** recursive `dfs(L,R)`.

This **looks like two-pointers** (topic 7), and an iterative two-pointer solution is more idiomatic there. We solve it here via **recursive shrinking bounds** on purpose so the call stack is visible.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly.

## 5. Logic Walkthrough
1. Base: `L >= R`.
2. Swap `s[L]`, `s[R]`; recurse `L+1`, `R-1`.

## 6. Dry Run
`hello` → swap h/o, e/l → `olleh`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) stack (iterative is O(1))

## 8. Trade-offs & Alternatives
Interview preferred answer is iterative; this file is pedagogy.

## 9. Common Mistakes / Edge Cases
Infinite recursion when L/R not moved; copying instead of in-place.

## 10. Interview Follow-ups / Variations
Reverse words; reverse linked list recursively (below).

## 11. Tags
`recursion`, `string`, `leetcode-344`, `difficulty:easy`
