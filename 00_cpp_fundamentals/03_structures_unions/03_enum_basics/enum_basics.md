# Enum Basics

## Problem Statement
Introduce an unscoped `enum Color { RED, GREEN, BLUE }` and print the integer value of `GREEN`.

**Decode**
- Inputs: assign `c = GREEN`.
- Goal: replace magic numbers with named constants.
- Valid: prints `1` (RED=0, GREEN=1, BLUE=2).
- Edges: unscoped enums pollute enclosing scope; prefer `enum class` in modern code.

## Intuition
States and categories should be named. Enumerations map readable labels to consecutive integers by default.

## Brute Force → Optimal
Brute: raw ints `0/1/2` — unclear and error-prone.

Optimal teaching step: classic `enum`; then graduate to `enum class` for scoping/type safety.

## Data Structure / Approach Justification
**Chosen:** unscoped `enum Color`.

Why: minimal syntax; shows default underlying values and implicit conversion to `int` for printing.

**Alternatives**
1. `enum class Color` — scoped, no silent int conversion; preferred in production.
2. `constexpr int` constants — no distinct type.

Trade-off: unscoped enums convert to int easily (handy for demo, weaker type safety).

## Logic Walkthrough
1. Compiler assigns RED=0, GREEN=1, BLUE=2.
2. `Color c = GREEN` stores enumerator 1.
3. Streaming `c` promotes to int → prints `1`.

## Dry Run
| Enumerator | Value |
|------------|-------|
| RED | 0 |
| GREEN | 1 |
| BLUE | 2 |
| `c` printed | 1 |

## Time & Space Complexity
- Time: O(1).
- Space: O(1) (typically underlying `int`).
Why: compile-time constants; no dynamic structures.

## Trade-offs & Alternatives
- Prefer `enum class` to avoid name clashes and accidental int mixing.
- Assign explicit values when protocol/ABI requires gaps.
- Use enums for finite state machines and flags (with care).

## Common Mistakes / Edge Cases
- Forgetting default starts at 0.
- Name collisions with unscoped enums.
- Comparing unrelated enum types via int.

## Interview Follow-ups / Variations
- Rewrite as `enum class` and print with `static_cast<int>`.
- Underlying type: `enum Color : uint8_t`?
- Bitmask enums vs `std::bitset`?

## Tags
`cpp-fundamentals`, `enum`, `named-constants`, `difficulty:easy`
