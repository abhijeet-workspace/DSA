# Expression Add Operators

## 1. Problem Statement
[LeetCode 282](https://leetcode.com/problems/expression-add-operators/) — given numeric string `num` and `target`, return all ways to insert `+`, `-`, or `*` between digits (operand grouping allowed) so the expression evaluates to `target`.

- **Inputs:** `string num`, `int target`.
- **Output:** list of expression strings.
- **Valid answer:** valid operator placements; no leading zeros in operands.
- **Edges:** single digit; many zeros; overflow risk with large products.

## 2. Intuition
DFS chooses next operand length; for non-first operand try `+`, `-`, `*`. For `*`, adjust using stored `last` multiplicand: `cur - last + last * val`.

## 3. Brute Force → Optimal
- **Brute:** exponential placements — required.
- **Optimal:** prune leading zeros; use long for intermediate values.

## 4. Data Structure / Approach Justification
**Chosen:** backtracking with `curVal` and `last` operand for multiplication precedence.

- **vs full expression parse each time:** slower and messier.
- **vs RPN generation:** heavier.

## 5. Logic Walkthrough
From `pos`, grow `val` digit by digit. First operand sets expr. Else branch `+`, `-`, `*` with value updates; recurse.

## 6. Dry Run
`"123"`, target `6` → `"1+2+3"`, `"1*2*3"`.

## 7. Time & Space Complexity
Time **O(4^n)** roughly (operand splits × ops). Space **O(n)** recursion. Why: expression tree search (section 4).

## 8. Trade-offs & Alternatives
Limit operand length early if value already huge. Memoization rarely helps due to string paths.

## 9. Common Mistakes / Edge Cases
Leading zeros; wrong `*` associativity handling; int overflow; empty num.

## 10. Interview Follow-ups / Variations
Only `+`/`-`; evaluate reverse Polish; different operator set.

## 11. Tags
`backtracking`, `math`, `leetcode-282`, `difficulty:hard`
