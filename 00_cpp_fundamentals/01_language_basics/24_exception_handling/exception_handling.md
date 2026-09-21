# Exception Handling

## 1. Problem Statement
Demonstrate throwing `std::invalid_argument`, catching by `const` reference, and resuming after the handler.

- **Input:** none
- **Output:** successful divide, then catch message, then continuation line
- **Valid answer:** code after the throw inside `try` does not run; after `catch` it does
- **Edges:** catching by value slices; order of catch clauses matters (specific before base)

## 2. Intuition
Exceptions separate “happy path” from error propagation when errors are rare and cross layers.

## 3. Brute Force → Optimal
- **Naive:** error codes returned and ignored.
- **This approach:** throw typed errors; catch where you can recover or report.

## 4. Data Structure / Approach Justification
Standard `<stdexcept>` types — portable and recognizable.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Error codes / `optional` | Better for expected failures in APIs |
| `abort` | Fine for unrecoverable; no recovery |

## 5. Logic Walkthrough
1. `safeDivide(10,2)` returns normally.
2. `safeDivide(10,0)` throws.
3. Matching `catch` prints `what()`.
4. Execution continues after the try/catch.

## 6. Dry Run
| Step | Control |
|------|---------|
| enter try | — |
| 10/2 | prints 5 |
| 10/0 | throw → first catch |
| after catch | prints continues |

## 7. Time & Space Complexity
- **Time:** success path roughly O(1); throw path is expensive
- **Space:** O(1) for this demo
- Why: exceptions optimize the non-throwing path on most ABIs

## 8. Trade-offs & Alternatives
- Prefer exceptions for truly exceptional conditions.
- Prefer expected/optional for predictable failure.
- Prefer RAII so throws still release resources.

## 9. Common Mistakes / Edge Cases
- Catching by value (slicing)
- Catching `std::exception` before a derived type
- Throwing raw pointers / strings without a type hierarchy

## 10. Interview Follow-ups / Variations
- What is stack unwinding?
- `noexcept` and move operations?
- Exception safety levels (basic/strong/nothrow)?

## 11. Tags
`cpp-basics`, `exceptions`, `try-catch`, `beginner`
