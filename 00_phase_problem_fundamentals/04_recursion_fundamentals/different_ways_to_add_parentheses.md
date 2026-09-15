# Different Ways to Add Parentheses

## 1. Problem Statement
[LeetCode 241](https://leetcode.com/problems/different-ways-to-add-parentheses/) — Given an expression of digits and `+,-,*`, return all possible results from computing all different parenthesizations.

- **Inputs:** `string expression`.
- **Output:** `vector<int>` of possible values (any order).
- **Edges:** Single number; one operator; multi-digit numbers.

## 2. Intuition
Split at each operator; recursively evaluate left and right; combine.

## 3. Brute Force → Optimal
Enumerate all full binary trees of operators — recursion over split points is the natural form.

## 4. Data Structure / Approach Justification
**Chosen:** divide-and-conquer recursion over operator positions.

This topic trains the **recursion mental model** (base case, smaller subproblem, call stack) before subsets/backtracking (topics 26–27) and before treating linked lists / trees / DP as their own units. Where a later pattern also solves the problem, §4 says so explicitly. Memoization on substring ranges is an optional upgrade (Catalan growth).

## 5. Logic Walkthrough
1. For each operator at `i`, compute all left/right results.
2. Combine with that operator.
3. If no operator, parse the number.

## 6. Dry Run
`2-1-1`: `(2-1)-1=0` and `2-(1-1)=2`.

## 7. Time & Space Complexity
- **Time:** Catalan-like in number of operators
- **Space:** output size + recursion depth

## 8. Trade-offs & Alternatives
Memoize substrings to avoid recomputation; DP on intervals equivalent.

## 9. Common Mistakes / Edge Cases
Not handling multi-digit numbers; mutating global state across splits.

## 10. Interview Follow-ups / Variations
Return count only; expression add operators (harder).

## 11. Tags
`recursion`, `divide-and-conquer`, `leetcode-241`, `difficulty:medium`
