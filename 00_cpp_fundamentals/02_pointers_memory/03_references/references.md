# References

## Problem Statement
Demonstrate C++ references as aliases: binding, mutation through the alias, non-reseating assignment, pass-by-reference, and `const` reference to a temporary.

**Decode**
- Inputs: local `x`, `y`.
- Goal: show `int&` is not a reseatable pointer.
- Valid: changing `ref` changes `x`; `ref = y` copies into `x`.
- Edges: non-const refs cannot bind to temporaries.

## Intuition
A reference is a new name for an existing object. Prefer references when null is illegal and reseating is not needed.

## Brute Force → Optimal
Brute: use pointers everywhere and check for null.

Optimal teaching path: references for required aliases; pointers when optional/reseatable addresses are needed.

## Data Structure / Approach Justification
**Chosen:** stack `int` + `int&` + `const int&`.

Why: smallest model that separates “alias” from “pointer object”.

**Alternatives**
1. Raw pointers — reseatable; may be null.
2. `std::reference_wrapper` — storeable reference-like object in containers.

## Logic Walkthrough
1. Bind `ref` to `x`; assign through `ref`.
2. Assign `ref = y` (writes into `x`).
3. Mutate via `addTen(x)`.
4. Bind `const int&` to temporary `42`.

## Dry Run
| Step | `x` | `ref` bound to |
|------|-----|----------------|
| init | 5 | x |
| `ref=8` | 8 | x |
| `ref=y` (y=100) | 100 | x |
| `addTen(x)` | 110 | x |

## Time & Space Complexity
- Time: O(1).
- Space: O(1).
Why: references typically compile to addresses without a separate user-visible object.

## Trade-offs & Alternatives
- Prefer `T&` for required mutable aliases.
- Prefer `const T&` for cheap read-only params.
- Prefer pointers when “no object” (`nullptr`) is meaningful.

## Common Mistakes / Edge Cases
- Thinking `ref = y` reseats the reference.
- Returning a reference to a local automatic variable.
- Binding non-const ref to an rvalue.

## Interview Follow-ups / Variations
- Reference vs pointer differences checklist?
- When do references extend temporary lifetimes?
- `T&&` forwarding references vs `const T&`?

## Tags
`cpp-fundamentals`, `references`, `aliases`, `difficulty:easy`
