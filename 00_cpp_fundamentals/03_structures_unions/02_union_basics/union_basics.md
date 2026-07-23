# Union Basics

## Problem Statement
Demonstrate a `union Data` where `int`, `float`, and `char` share memory; show that writing one member overwrites the others.

**Decode**
- Inputs: successive assignments 10, 3.14f, 'A'.
- Goal: observe shared storage / type-punning hazard.
- Valid: active member prints correctly; inactive member is garbage/UB to read.
- Edges: reading inactive member is undefined behavior in strict C++.

## Intuition
If only one of several types is live at a time, overlay them in the same bytes to save space—at the cost of exclusive activation.

## Brute Force → Optimal
Brute: a `struct` holding all three fields — always uses sum of sizes.

Optimal for exclusive variants: `union` (or better, `std::variant` in modern C++).

## Data Structure / Approach Justification
**Chosen:** classic C-style `union`.

Why: clearest demo of shared storage size ≈ max(member sizes).

**Alternatives**
1. `std::variant<int,float,char>` — type-safe active member tracking.
2. `struct` with all fields — simpler but wastes space.

Trade-off: raw unions are easy to misuse; prefer `variant` in new code.

## Logic Walkthrough
1. `sizeof(Data)` ≈ size of largest member (plus padding rules).
2. Write `intVal` → only int is meaningful.
3. Write `floatVal` → same bytes reinterpreted; old int view is invalid.
4. Write `charVal` → float view becomes invalid.

## Dry Run
| Assignment | Active | Safe to read | Unsafe |
|------------|--------|--------------|--------|
| intVal=10 | int | intVal | float/char |
| floatVal=3.14 | float | floatVal | int/char |
| charVal='A' | char | charVal | int/float |

## Time & Space Complexity
- Time: O(1) field write/read.
- Space: O(1), roughly `max(sizeof members)`.
Why: single overlapping storage block.

## Trade-offs & Alternatives
- Prefer `std::variant` for type safety.
- Prefer tagged unions (enum + union) when stuck on older C++.
- Use unions for low-level serialization/hardware maps carefully.

## Common Mistakes / Edge Cases
- Reading inactive member (UB).
- Assuming `sizeof(union)==sum of members`.
- Non-trivial types in unions need C++11+ care.

## Interview Follow-ups / Variations
- How does `std::variant` track the active index?
- What is type punning via `memcpy` vs union?
- Alignment requirements of union members?

## Tags
`cpp-fundamentals`, `union`, `memory-layout`, `difficulty:easy`
