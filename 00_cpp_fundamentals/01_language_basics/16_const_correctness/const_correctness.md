# Const Correctness

## 1. Problem Statement
Show `const` on variables, pointer variants (`const T*` vs `T* const`), `const` reference parameters, and `const` member functions.

- **Input:** none
- **Output:** printed values proving read-only vs mutable paths
- **Valid answer:** const object can call `value()` but not `bump()`
- **Edges:** `const` must be initialized; casting away const is UB if object was truly const

## 2. Intuition
`const` documents and enforces “this path does not modify.” Compilers catch accidental writes early.

## 3. Brute Force → Optimal
- **Naive:** never use `const`; rely on discipline.
- **This approach:** mark read-only APIs `const` so misuse fails at compile time.

## 4. Data Structure / Approach Justification
Tiny `Counter` class to show const methods; string `const&` for cheap read-only params.

| Alternative | Why it loses here |
|-------------|-------------------|
| Pass `string` by value always | Extra copies |
| Mutable globals | Harder to reason about |

## 5. Logic Walkthrough
1. Create `const int maxScore`.
2. Contrast `const int*` (cannot write through) vs `int* const` (cannot reseat).
3. Pass string as `const std::string&`.
4. Call only const methods on a `const Counter`.

## 6. Dry Run
| Object | Allowed | Forbidden |
|--------|---------|-----------|
| `const Counter c(5)` | `c.value()` | `c.bump()` |
| `const int* p` | read `*p` | `*p = ...` |
| `int* const p` | `*p = ...` | `p = other` |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: fixed locals

## 8. Trade-offs & Alternatives
- Prefer `const T&` for large read-only parameters.
- Prefer `const` methods on observers/getters.
- Prefer `std::string_view` (later) for non-owning string reads.

## 9. Common Mistakes / Edge Cases
- Confusing `const T*` with `T* const`
- Forgetting to mark getters `const`
- Mutating through a non-const alias of const data

## 10. Interview Follow-ups / Variations
- What is `mutable` for?
- Can `const` methods return non-const references to members?
- Logical vs bitwise constness?

## 11. Tags
`cpp-basics`, `const`, `pointers`, `beginner`
