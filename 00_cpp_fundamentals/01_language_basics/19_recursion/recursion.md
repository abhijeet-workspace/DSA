# Recursion

## 1. Problem Statement
Implement recursive `factorial` and naive `fib`, and contrast with an iterative `sumTo`.

- **Input:** none (hardcoded demos)
- **Output:** `120`, `8`, `15`
- **Valid answer:** each recursive function has a clear base case
- **Edges:** deep recursion can overflow the stack; naive fib is exponential

## 2. Intuition
A recursive function solves a smaller instance of the same problem and stops at a base case. The call stack remembers pending work.

## 3. Brute Force → Optimal
- **Naive fib recursion:** correct but O(φⁿ) time.
- **Better later:** memoization / iteration for fib; recursion still great for trees/divide-and-conquer.

## 4. Data Structure / Approach Justification
Call stack only — no explicit container.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Iteration for factorial | Same result; often clearer/safer |
| Recursion for tree DFS | Natural fit |

## 5. Logic Walkthrough
1. `factorial(5)` → 5×4×3×2×1.
2. `fib(6)` expands into overlapping subcalls until base cases.
3. `sumTo(5)` loops 1..5 as the iterative baseline.

## 6. Dry Run
| Call | Expansion | Result |
|------|-----------|--------|
| `factorial(3)` | 3×factorial(2)→2×factorial(1)→1 | 6 |
| `fib(4)` | fib(3)+fib(2) | 3 |
| `sumTo(3)` | 1+2+3 | 6 |

## 7. Time & Space Complexity
- **factorial:** time O(n), stack space O(n)
- **naive fib:** time O(2ⁿ), stack O(n)
- **sumTo:** time O(n), space O(1)
- Why: recursion depth / branching

## 8. Trade-offs & Alternatives
- Prefer iteration when the state is a simple accumulator.
- Prefer recursion for naturally recursive structures.
- Prefer memoized recursion when overlapping subproblems appear.

## 9. Common Mistakes / Edge Cases
- Missing base case → infinite recursion
- Off-by-one in base case (`n==0` vs `n<=1`)
- Stack overflow on large `n`

## 10. Interview Follow-ups / Variations
- Convert factorial to iteration / tail recursion
- Memoize fib
- Recursion vs divide-and-conquer (merge sort)

## 11. Tags
`cpp-basics`, `recursion`, `call-stack`, `beginner`
