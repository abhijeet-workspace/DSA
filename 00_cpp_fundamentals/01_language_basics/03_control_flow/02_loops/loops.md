# Loops

## 1. Problem Statement
Demonstrate C++ loop forms and jump statements: `for`, `while`, `do-while`, `break`/`continue`, and a minimal `goto` sample (discouraged in real code).

- **Input:** none (hardcoded demos)
- **Output:** counts, digit sums, simulated menu, filtered odds, goto steps
- **Valid answer:** each helper shows the control-flow behavior described in its section header
- **Edges:** `while` on `num == 0` prints sum 0; `do-while` always runs once; `break` exits early

## 2. Intuition
Use `for` when the iteration count is known, `while` when it depends on changing state, and `do-while` when the body must run at least once (menus). `continue` skips the rest of one iteration; `break` leaves the loop.

## 3. Brute Force → Optimal
- **Naive:** copy-paste statements; use `goto` for every branch; forget to update the loop variable (infinite loop).
- **This approach:** one helper per construct, with digit-sum as a natural `while` example and a non-interactive menu simulation for `do-while`.

## 4. Data Structure / Approach Justification
No containers — scalars and loop counters.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Recursion for digit sum | Works; uses O(digits) stack vs O(1) `while` |
| Range-based `for` | Great for containers; not the first lesson for counters |
| Structured loops vs `goto` | Prefer structured loops; `goto` shown only to recognize it |

## 5. Logic Walkthrough
1. `demonstrateForLoop` counts `i` up 1..5 and down 5..1.
2. `demonstrateWhileLoop(num)` peels `lastDigit = num % 10`, adds to `sum`, sets `num /= 10`.
3. `demonstrateDoWhileLoop` uses fixed `choice = 3` so the menu prints once and exits.
4. `demonstrateBreakAndContinue` skips evens and 5, breaks at 9.
5. `demonstrateGoto` increments `steps` via labels until `steps > 3`.

## 6. Dry Run
`demonstrateWhileLoop(12345)`:

| `num` | `lastDigit` | `sum` |
|-------|-------------|-------|
| 12345 | 5 | 5 |
| 1234 | 4 | 9 |
| 123 | 3 | 12 |
| 12 | 2 | 14 |
| 1 | 1 | 15 |
| 0 | — | stop |

Output: `Sum of digits of 12345 is 15`

## 7. Time & Space Complexity
- **for demos:** O(1) fixed bounds
- **digit sum:** O(d) time, O(1) space for d digits
- **goto demo:** O(1) fixed steps
- Why: no input-sized containers; work proportional to digits or fixed counters

## 8. Trade-offs & Alternatives
- Prefer `for` for counted loops; `while` for sentinels/streams.
- Prefer `break`/`return` over `goto`.
- Intentional `while (true)` + `break` is fine for event loops when documented.

## 9. Common Mistakes / Edge Cases
- Off-by-one (`<=` vs `<`)
- Forgetting to update the condition variable
- `do-while` missing trailing semicolon
- `continue` skipping the update in awkward `while` forms
- Using `goto` across initialization in ways that skip constructors (advanced hazard)

## 10. Interview Follow-ups / Variations
- Sum digits recursively vs iteratively
- Replace `goto` with a `while` cleanly
- When is an infinite loop + `break` appropriate?

## 11. Tags
`cpp-basics`, `loops`, `break`, `continue`, `beginner`
