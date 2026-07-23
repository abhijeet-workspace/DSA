# Evaluate Reverse Polish Notation

## Problem Statement
[LeetCode 150](https://leetcode.com/problems/evaluate-reverse-polish-notation/) — evaluate an RPN token list of integers and `+ - * /`.

- **Inputs:** `vector<string> tokens`.
- **Output:** expression value as `int`.
- **Valid answer:** unique for valid RPN; division truncates toward zero.
- **Edges:** negatives; single number; multi-digit; division of negatives.

## Intuition
Postfix operators always apply to the two most recently computed values — a stack of intermediates.

## Brute Force → Optimal
- **Brute:** rebuild an AST then evaluate — more structure than needed.
- **Optimal:** one stack pass — O(N) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `stack<long>` for intermediate values (`long` for overflow headroom).

- **vs recursion on token index:** equivalent; stack is the natural model.
- **vs infix conversion first:** unnecessary when input is already RPN.

## Logic Walkthrough
Number → push. Operator → pop `b`, pop `a`, push `a op b`. Final top is the answer.

## Dry Run
`["2","1","+","3","*"]`: push 2,1 → `+` → 3 → push 3 → `*` → 9.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: one pass; stack holds pending values (section 4).

## Trade-offs & Alternatives
Same core as `03_postfix_evaluation` but with string tokens (multi-digit / signs).

## Common Mistakes / Edge Cases
Operand order for `-`/`/`; using floor division; `int` overflow mid-expression.

## Interview Follow-ups / Variations
Infix evaluation; basic calculator II; expression add operators.

## Tags
`stack`, `rpn`, `postfix`, `leetcode-150`, `difficulty:medium`
