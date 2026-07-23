# Postfix Evaluation

## Problem Statement
Evaluate a postfix (RPN) expression of single digits and `+ - * /` with no spaces.

- **Inputs:** string like `"234*+"` meaning `2 + 3*4`.
- **Output:** integer result (C++ truncating division).
- **Valid answer:** unique value for a well-formed expression.
- **Edges:** single digit; division truncates toward zero; operand order for `-`/`/`.

## Intuition
Postfix needs no precedence rules: operands wait on a stack until an operator consumes the top two.

## Brute Force → Optimal
- **Brute:** convert to infix then evaluate with precedence — more code, same math.
- **Optimal:** one stack scan — O(N) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** `stack<int>` of intermediate values.

- **vs recursive descent:** overkill for pure postfix.
- **vs infix + shunting-yard:** needed only if input is infix.

## Logic Walkthrough
Digit → push. Operator → pop `b`, pop `a`, push `a op b`. Final top is the answer.

## Dry Run
`"234*+"`: push 2,3,4 → `*` → push 12 → `+` → push 14. `"321*-"`: 3,2,1 → `*` → 2 → `-` → 1.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: one pass; stack holds pending operands (section 4).

## Trade-offs & Alternatives
Same pattern as LeetCode 150 (token strings). Multi-digit needs tokenization, not char-by-char digits.

## Common Mistakes / Edge Cases
Wrong operand order (`b` then `a`); empty stack on operator; assuming floor division.

## Interview Follow-ups / Variations
Multi-digit tokens; infix→postfix (shunting-yard); prefix evaluation.

## Tags
`stack`, `postfix`, `rpn`, `expression`, `difficulty:easy`
