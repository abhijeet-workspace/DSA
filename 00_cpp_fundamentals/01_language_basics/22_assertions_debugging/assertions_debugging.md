# Assertions & Basic Debugging

## 1. Problem Statement
Demonstrate `assert` for programmer invariants versus an explicit runtime check that remains in release builds (`NDEBUG` strips asserts).

- **Input:** none
- **Output:** successful divide; error message from `checkedDivide(10,0)`
- **Valid answer:** assert documents “this must never happen”; runtime checks handle expected failures
- **Edges:** asserting user input is the wrong tool — validate instead

## 2. Intuition
Asserts catch logic bugs during development. User-facing errors need graceful handling that still exists in optimized builds.

## 3. Brute Force → Optimal
- **Naive:** only print debugging when something breaks.
- **This approach:** encode invariants with `assert`; keep user validation as normal control flow.

## 4. Data Structure / Approach Justification
Two divide helpers — same math, different failure policy.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Exceptions | Better for recoverable errors across layers |
| Logging frameworks | Better at scale; heavier for fundamentals |

## 5. Logic Walkthrough
1. `dividePositive(10,2)` passes assert and returns 5.
2. `checkedDivide(10,0)` prints to `cerr` and returns 0.
3. Note that enabling `dividePositive(10,0)` aborts in debug.

## 6. Dry Run
| Call | Path |
|------|------|
| `dividePositive(10,2)` | assert ok → 5 |
| `checkedDivide(10,0)` | branch → cerr → 0 |
| `dividePositive(10,0)` (debug) | assert fails → abort |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: scalar checks

## 8. Trade-offs & Alternatives
- Prefer assert for internal invariants.
- Prefer validation/errors for external input.
- Prefer a debugger + breakpoints for stateful bugs.

## 9. Common Mistakes / Edge Cases
- Putting required production checks only in `assert`
- Asserting expressions with side effects (`assert(i++ > 0)`)
- Ignoring compiler warnings that often point to the real bug

## 10. Interview Follow-ups / Variations
- What does `-DNDEBUG` change?
- Assert vs `static_assert`?
- How do you bisect a heisenbug?

## 11. Tags
`cpp-basics`, `assert`, `debugging`, `beginner`
