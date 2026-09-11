# Basic Calculator

## Problem Statement
[LeetCode 224](https://leetcode.com/problems/basic-calculator/) — evaluate a valid infix expression with integers, `+`, `-`, `(`, `)`, and spaces (no `*`/`/`).

- **Inputs:** `string s`.
- **Output:** expression value as `int`.
- **Valid answer:** unique for a valid expression; do not use `eval()`.
- **Edges:** multi-digit numbers; spaces; nested parentheses; unary-looking `-` after `(` (e.g. `-(2+3)`); leading zeros not required.

## Intuition
Only `+`/`-` and nesting matter. Treat every number as signed (`sign * num`). On `(`, save the outer running result and outer sign, then evaluate the inside as a fresh expression. On `)`, fold the inside result back with the saved sign/result.

## Brute Force → Optimal
- **Brute:** convert to RPN (shunting-yard) then evaluate — two passes / more machinery.
- **Optimal:** one left-to-right pass with a stack of `(prev_result, prev_sign)` — O(N) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `stack<long>` storing pairs as consecutive pushes: previous `result`, then previous `sign` (`±1`).

- **vs recursive descent on index:** equivalent logic; explicit stack mirrors nested contexts.
- **vs shunting-yard:** overkill when there is no `*`/`/` precedence.

## Logic Walkthrough
Maintain `result`, `num`, `sign` (initially `1`).

1. Digit → build `num = num * 10 + digit`.
2. `+` / `-` → flush `result += sign * num`; reset `num`; set `sign` to `±1`.
3. `(` → push `result`, push `sign`; reset `result = 0`, `sign = 1`, `num = 0`.
4. `)` → flush pending `num`; `result = stack.pop() * result + stack.pop()` (sign then prev result).
5. End → flush any leftover `num`.

Skip spaces.

## Dry Run
`"(1+(4+5+2)-3)+(6+8)"`:

- `(` → push `(0, +1)`, reset; then `1`, `+`, `(`, … inner sums to `11`.
- After first close and `-3`: context yields `1+11-3 = 9`.
- Outer `+(6+8)` → `9+14 = 23`.

`"-(2+3)"`: after `-` and `(`, push `(0, -1)`; inside `5`; on `)` → `-1 * 5 + 0 = -5`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)** worst case (deep nesting). Why: each char once; stack depth = nesting depth.

## Trade-offs & Alternatives
Related to `evaluate_reverse_polish_notation` (postfix) but input is infix with parentheses. Basic Calculator II adds `*`/`/` without parentheses — track last operator/operand instead of nesting stack.

## Common Mistakes / Edge Cases
Forgetting to flush `num` before `)` or at end; pushing sign/result in wrong order; treating `-` only as binary (misses `-(...)`); using `int` when intermediate can need wider range during build (constraints usually fit `int` for result).

## Interview Follow-ups / Variations
Basic Calculator II (227); Basic Calculator III (772); Expression Add Operators (282); shunting-yard for full precedence.

## Tags
`stack`, `math`, `string`, `parentheses`, `leetcode-224`, `difficulty:hard`
