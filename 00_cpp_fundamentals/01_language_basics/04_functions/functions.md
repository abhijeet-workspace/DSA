# Functions

## 1. Problem Statement
Write a tiny function `add(a, b)` that returns the sum of two integers and call it from `main`.

- **Input:** hardcoded demo args `2` and `3`
- **Output:** `Sum: 5`
- **Valid answer:** function returns `a + b`; `main` prints it
- **Edges:** overflow for large ints (not handled in this intro)

## 2. Intuition
Functions package reusable logic. Callers pass arguments; the callee returns a result. This separates “how to add” from “how to print”.

## 3. Brute Force → Optimal
- **Naive:** put `2 + 3` directly in `main` forever.
- **This approach:** extract `add` so the same logic can be reused and tested independently.

## 4. Data Structure / Approach Justification
No data structure — a free function with value parameters.

| Alternative | Why it loses here |
|-------------|-------------------|
| Macros `#define ADD(a,b) ((a)+(b))` | No type checking; harder to debug |
| Lambda in `main` only | Fine later; obscures named-function basics |

## 5. Logic Walkthrough
1. `add` takes `a` and `b` by value and returns `a + b`.
2. `main` calls `add(2, 3)` and streams the return value.

## 6. Dry Run
| Call | `a` | `b` | Return |
|------|-----|-----|--------|
| `add(2, 3)` | 2 | 3 | 5 |

Printed: `Sum: 5`

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1) stack frame for `add`
- Why: fixed arithmetic; no loops

## 8. Trade-offs & Alternatives
- Pass by `const` reference for large objects; by value is fine for `int`.
- Overloading / templates come later for generic add.
- Prefer clear names over one-letter helpers in real code (demo keeps `a`/`b`).

## 9. Common Mistakes / Edge Cases
- Declaring a function after use without a prototype
- Forgetting `return` in a non-void function
- Integer overflow on large sums
- Confusing declaration vs definition

## 10. Interview Follow-ups / Variations
- Pass-by-value vs pass-by-reference?
- What is a function prototype?
- How do default arguments work?

## 11. Tags
`cpp-basics`, `functions`, `beginner`
