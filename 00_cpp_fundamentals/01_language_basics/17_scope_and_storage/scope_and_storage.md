# Scope and Storage Duration

## 1. Problem Statement
Demonstrate block scope, name shadowing, globals, and `static` locals that persist across calls.

- **Input:** none
- **Output:** outer/inner `x`, three increments of a static call counter
- **Valid answer:** inner `x` does not change outer `x`; static local prints 1,2,3
- **Edges:** using a variable after its block ends is a compile error

## 2. Intuition
**Scope** answers “where is the name visible?” **Storage duration** answers “how long does the object live?”

## 3. Brute Force → Optimal
- **Naive:** put everything in globals.
- **This approach:** prefer tight block scopes; use `static` local only for intentional persistence.

## 4. Data Structure / Approach Justification
Plain ints — enough to show lifetime without containers.

| Alternative | Why it loses here |
|-------------|-------------------|
| Class members | Mixes OOP lifetime with scope basics |
| `thread_local` | Advanced; skip for fundamentals |

## 5. Logic Walkthrough
1. Print global `g`.
2. Enter a nested block that shadows `x` and introduces `y`.
3. Leave the block; outer `x` unchanged; `y` gone.
4. Call `bumpStaticLocal` three times.

## 6. Dry Run
| Step | Visible `x` | static `calls` |
|------|-------------|----------------|
| outer init | 10 | — |
| inner block | 99 | — |
| after block | 10 | — |
| 3rd bump | — | 3 |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: fixed locals + one static int

## 8. Trade-offs & Alternatives
- Prefer locals over globals for testability.
- Prefer function args/return values over hidden static state.
- Prefer RAII objects when lifetime must pair with resources.

## 9. Common Mistakes / Edge Cases
- Returning a reference/pointer to a local automatic variable
- Assuming static locals reset each call
- Accidental shadowing that hides bugs

## 10. Interview Follow-ups / Variations
- Internal vs external linkage (`static` at namespace scope)?
- Difference between static storage and heap storage?
- When is initialization of static locals thread-safe (C++11+)?

## 11. Tags
`cpp-basics`, `scope`, `storage-duration`, `static`, `beginner`
