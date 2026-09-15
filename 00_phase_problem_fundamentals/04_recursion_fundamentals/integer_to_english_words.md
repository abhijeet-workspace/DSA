# Integer to English Words

## 1. Problem Statement
[LeetCode 273](https://leetcode.com/problems/integer-to-english-words/) — Convert a non-negative integer to its English words representation.

- **Inputs:** `int num` (`0 .. 2³¹-1`).
- **Output:** English words string (LC spacing/capitalization).
- **Edges:** `0` → `Zero`; exact thousands; trailing zero chunks (e.g. `1000000`).

## 2. Intuition
Recursively spell under-1000 blocks; scale by Thousand/Million/Billion.

## 3. Brute Force → Optimal
Giant lookup — unmaintainable. Hierarchical recursive construction matches English grammar.

## 4. Data Structure / Approach Justification
**Chosen:** recursive helpers `under1000` + scale breakdown.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly. Hard because of edge-case phrasing, not asymptotic difficulty.

## 5. Logic Walkthrough
1. Map `<20`, tens, hundreds recursively inside a 3-digit block.
2. Peel billion/million/thousand chunks and recurse on remainders.
3. Skip empty chunks; special-case `0`.

## 6. Dry Run
`12345` → `Twelve Thousand` + `Three Hundred Forty Five`.

## 7. Time & Space Complexity
- **Time:** O(1) (bounded digits)
- **Space:** O(1) recursion depth

## 8. Trade-offs & Alternatives
Iterative chunk loop is equivalent; recursion mirrors English nesting.

## 9. Common Mistakes / Edge Cases
Extra spaces; saying “Zero Thousand”; wrong Teen handling.

## 10. Interview Follow-ups / Variations
Roman numerals; money formatting.

## 11. Tags
`recursion`, `math`, `string`, `leetcode-273`, `difficulty:hard`
