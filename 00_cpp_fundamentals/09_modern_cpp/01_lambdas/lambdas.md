# Lambdas

## Problem Statement
Demonstrate lambda syntax: no-capture callables, by-value/by-reference captures, `mutable`, C++14 generic (`auto`) parameters, and use as `std::sort` comparator.

**Inputs:** local ints + a small `vector<int>`.  
**Valid answer:** printed capture behavior and descending-sorted vector.  
**Edges:** reference capture outliving scope (not shown — dangling risk).

## Intuition
A lambda is an anonymous functor: capture = member fields, body = `operator()`. Ideal for one-off STL predicates.

## Brute Force → Optimal
- **Brute:** write a named `struct Cmp { bool operator()(...); };` for every sort.
- **Optimal:** inline lambda at call site — same performance after inlining, less boilerplate.

## Data Structure / Approach Justification (REQUIRED)
`std::vector<int>` for sorting demo (random-access required by `std::sort`).
- **vs hand-written functor class:** same generated code often, worse readability for tiny predicates.
- **vs function pointer:** cannot capture local state without globals.

## Logic Walkthrough
`greet` no capture; `capture_val` freezes `factor`; `capture_ref` mutates `divisor`; `mutable` increments internal copy of `counter`; generic `print_val`; `sort` with `a > b`.

## Dry Run
`factor=2` → `capture_val(5)=10`. `divisor` 5→10 inside ref-lambda; `20/10=2`. Mutable counter prints 1 then 2; outer stays 0. `{4,2,8,5,1}` → `{8,5,4,2,1}`.

## Time & Space Complexity
Call overhead ~ **O(1)** (usually inlined). Sort **O(N log N)**. Capture-by-value copies captured objects once. Why: vector random access (section 4).

## Trade-offs & Alternatives
`std::function` for type-erased storage (heap/alloc cost); generic lambdas vs explicit templates.

## Common Mistakes / Edge Cases
`[&]` in async callbacks dangling; forgetting `mutable` when mutating by-value captures; capturing `this` unintentionally.

## Interview Follow-ups / Variations
Init-capture `[x=std::move(y)]`; `constexpr` lambdas; recursive lambdas via `std::function` or C++23.

## Tags
`lambda`, `stl`, `cpp11`, `beginner`
