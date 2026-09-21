# Function Parameters

## 1. Problem Statement
Contrast pass-by-value, pass-by-reference, and `const` reference parameters; also show a default argument.

- **Input:** none
- **Output:** `a` unchanged after `byValue`, mutated after `byRef`; default `scale(7)==14`
- **Valid answer:** value copies; reference aliases; `const&` avoids copy without allowing writes
- **Edges:** cannot bind non-const ref to a temporary (`byRef(5)` fails)

## 2. Intuition
Choose the parameter mode by intent: isolate changes (value), share mutation (ref), or cheaply observe (const-ref).

## 3. Brute Force → Optimal
- **Naive:** always pass by value (expensive for large objects) or always by non-const ref (accidental mutation).
- **This approach:** value for tiny types; `const T&` for read-only large objects; `T&` only when mutation is required.

## 4. Data Structure / Approach Justification
`int` for mutation demo; `std::string` for const-ref.

| Alternative | Why it loses here |
|-------------|-------------------|
| Pointers for out-params | Valid; references are cleaner when null is illegal |
| Overloading instead of defaults | Also fine; defaults reduce call-site noise |

## 5. Logic Walkthrough
1. `byValue` adds 10 to a copy — caller `a` stays 5.
2. `byRef` adds 10 through an alias — `a` becomes 15.
3. `byConstRef` reads string size without copying.
4. `scale(7)` uses default factor 2; `scale(7,3)` overrides.

## 6. Dry Run
| Call | `a` before | `a` after |
|------|------------|-----------|
| `byValue(a)` | 5 | 5 |
| `byRef(a)` | 5 | 15 |
| `scale(7)` | — | returns 14 |

## 7. Time & Space Complexity
- **Time:** O(1) here; const-ref avoids O(N) string copy
- **Space:** O(1) extras for these demos
- Why: no containers grown

## 8. Trade-offs & Alternatives
- Prefer `const T&` for large read-only args.
- Prefer return values over out-params when possible.
- Put defaulted parameters last in the parameter list.

## 9. Common Mistakes / Edge Cases
- Expecting pass-by-value to mutate the caller
- Binding non-const ref to temporary
- Putting a non-defaulted parameter after a defaulted one

## 10. Interview Follow-ups / Variations
- Pass-by-pointer vs pass-by-reference?
- When pass `unique_ptr` by value vs reference?
- Perfect forwarding (`T&&`) — when later?

## 11. Tags
`cpp-basics`, `functions`, `references`, `beginner`
