# Structure Basics

## Problem Statement
Introduce `struct Student` with fields and a member function; create two students (assignment vs brace init) and print them.

**Decode**
- Inputs: hard-coded ids/names/marks.
- Goal: group heterogeneous fields; show member access and member functions.
- Valid: both students print correctly; `sumOfTwo(20,22)` → 42.
- Edges: uninitialized members if you skip assignment.

## Intuition
When several related values travel together (id, name, marks), bundle them into one named type instead of parallel variables.

## Brute Force → Optimal
Brute: separate variables `id1`, `name1`, … — does not scale to arrays/functions.

Optimal: one `struct` type reused for many instances.

## Data Structure / Approach Justification
**Chosen:** C++ `struct` (public-by-default aggregate + member function).

Why: lightest user-defined type for grouped data; brace-init works for aggregates.

**Alternatives**
1. `class` with private fields — better encapsulation; heavier for first exposure.
2. `std::tuple` — anonymous fields; worse readability for named domain data.

Trade-off: public fields are flexible but unprotected.

## Logic Walkthrough
1. Define `Student` layout: `id`, `name`, `marks`, plus `sumOfTwo`.
2. `s1`: default construct, assign fields.
3. `s2`: aggregate initialize in one brace list.
4. Print members; call `s1.sumOfTwo(20, 22)`.

## Dry Run
| Object | id | name | marks |
|--------|----|------|-------|
| s1 | 101 | Rahul | 87.5 |
| s2 | 102 | Amit | 92.0 |
| sumOfTwo(20,22) | — | — | returns 42 |

## Time & Space Complexity
- Time: O(1) field access; string assign O(length).
- Space: O(1) per Student (plus string heap).
Why: fixed fields; no dynamic resizing of the struct itself.

## Trade-offs & Alternatives
- Prefer `class` when invariants must be enforced.
- Prefer `struct` for plain data aggregates (POD-like).
- Nested structs / arrays of structs are natural next steps.

## Common Mistakes / Edge Cases
- Forgetting to initialize all members.
- Assuming C structs cannot have methods (C++ can).
- Padding/alignment surprises with `sizeof`.

## Interview Follow-ups / Variations
- Difference between `struct` and `class` default access?
- When is aggregate initialization allowed?
- Pass struct by value vs const reference?

## Tags
`cpp-fundamentals`, `struct`, `aggregate`, `difficulty:easy`
