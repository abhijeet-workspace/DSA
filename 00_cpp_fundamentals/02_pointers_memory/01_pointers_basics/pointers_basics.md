# Pointers Basics

## Problem Statement
Demonstrate C++ pointers: take the address of an `int`, store it in `int*`, then print the value via dereference and the address itself.

**Decode**
- Inputs: local `int a = 10`.
- Goal: show `&` (address-of) and `*` (dereference).
- Valid answer: printed value equals `10`; printed address is `&a`.
- Edge cases: dangling/null pointers are out of scope here (covered conceptually in notes).

## Intuition
A pointer is a typed variable that stores a memory address. When you need to observe or mutate an object without copying it—or reason about where it lives—you keep its address and dereference later.

## Brute Force → Optimal
Naive alternative: always copy values. That fails when you need shared mutation, large objects, or dynamic lifetime.

Optimal teaching path: one stack `int`, one pointer to it, then print `*pA` and `pA` so address vs value are visible.

## Data Structure / Approach Justification
**Chosen:** stack `int` + raw `int*`.

Why: the smallest model that shows address storage and dereference without heap noise.

**Alternatives**
1. `std::reference_wrapper` / references — hide the address; worse for teaching `&`/`*`.
2. Heap `new`/`delete` — mixes lifetime rules; save for dynamic memory lesson.

Trade-off: raw pointers do not own memory; fine for pointing at stack locals.

## Logic Walkthrough
1. `a` holds `10` on the stack.
2. `pA = &a` stores `a`'s address.
3. `*pA` loads the `int` at that address → `10`.
4. Streaming `pA` prints the address value.

## Dry Run
| Step | `a` | `pA` | `*pA` |
|------|-----|------|-------|
| init | 10 | — | — |
| `pA = &a` | 10 | &a | 10 |
| print | 10 | &a | 10 |

## Time & Space Complexity
- Time: O(1) for assign/dereference.
- Space: O(1) for one int + one pointer.
Why: fixed-size locals; no loops or allocations.

## Trade-offs & Alternatives
- Prefer references when null is illegal and reseating is not needed.
- Prefer smart pointers when ownership is involved.
- Raw non-owning pointers remain valid for observing stack/heap objects you do not own.

## Common Mistakes / Edge Cases
- Dereferencing uninitialized or null pointers (UB).
- Confusing `*pA` (value) with `pA` (address).
- Returning address of a local that goes out of scope.

## Interview Follow-ups / Variations
- What is pointer arithmetic on `int*`?
- Difference between `const int*` and `int* const`?
- When is `nullptr` check required?

## Tags
`cpp-fundamentals`, `pointers`, `memory`, `difficulty:easy`
