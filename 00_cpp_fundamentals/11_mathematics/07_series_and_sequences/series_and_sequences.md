# Series & Sequences

## 1. Problem Statement
Implement classic series used in interviews and CP warmups:

1. nth Fibonacci (iterative)
2. Sum of AP: `a, a+d, …` for `n` terms
3. nth term / sum of GP
4. Factorial (iterative, `unsigned long long`)
5. Sum of squares formula vs loop

- **Input:** demo parameters
- **Output:** sequence values / sums
- **Edges:** n=0/1; d=0 AP; r=1 GP; factorial overflow

## 2. Intuition
Closed forms beat loops when available: AP sum `n/2 * (2a+(n-1)d)`, GP sum `a(r^n-1)/(r-1)`, sum of squares `n(n+1)(2n+1)/6`. Fibonacci recurrence needs O(n) or matrix exp O(log n).

## 3. Brute Force → Optimal
- Fib loop O(n) vs matrix / fast doubling O(log n) — loop first here.
- Prefer formulas for AP/GP/squares when numerically safe.

## 4. Data Structure / Approach Justification
Two rolling fib variables; `long long` / `unsigned long long` accumulators.

| Alternative | Notes |
|-------------|-------|
| Recursion fib | Exponential without memo |
| DP array | Fine; unnecessary for single nth |

## 5. Logic Walkthrough
Fib: `a=0,b=1`; step `c=a+b`. AP/GP apply formulas. Factorial multiply 2..n.

## 6. Dry Run
Fib(10)=55. AP a=2,d=3,n=4 → 2+5+8+11=26. `5!=120`. Sum squares 1..5=55.

## 7. Time & Space Complexity
Fib / factorial O(n); AP/GP/squares formulas O(1) (plus O(log n) if using binary pow for GP).

## 8. Trade-offs & Alternatives
Matrix fib for huge n under mod — see modular + advanced math. Catalan numbers in advanced phase.

## 9. Common Mistakes / Edge Cases
Off-by-one on fib indexing; integer division order in formulas; GP when `r=1`.

## 10. Interview Follow-ups / Variations
Climbing stairs (fib); sum of GP mod p; factorial trailing zeros.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `fibonacci`, `series`, `beginner-intermediate`

## 12. Next Steps
`08_combinatorics_basics`. Catalan: `41_mathematical_algorithms/catalan_numbers`.
