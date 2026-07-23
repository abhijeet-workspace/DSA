# Templates

## Problem Statement
Show generic programming: function templates, class templates with non-type params, full specialization, C++17 fold expressions, and `if constexpr` type branching.

**Inputs:** ints/chars/doubles, pack of numbers, mixed types for `printTypeInfo`.  
**Valid answer:** max results, `StaticArray` get, fold sums, type messages.  
**Edges:** empty fold pack (not used); out-of-range `StaticArray` index → default `T()`.

## Intuition
Templates generate typed code at compile time — write once, use for any comparable/`+`-able type without runtime polymorphism overhead.

## Brute Force → Optimal
- **Brute:** overload `findMax` per type; recursive variadic helpers pre-C++17.
- **Optimal:** one template + specialization where needed; fold `(args + ...)`; `if constexpr` discards bad branches.

## Data Structure / Approach Justification (REQUIRED)
`StaticArray<T, Size>` — fixed stack array with compile-time size (like `std::array`).
- **vs `std::vector`:** heap + runtime size; not needed for fixed teaching demo.
- **vs macros:** templates are typed and scoped; macros are not.
Specialization for `double` documents “same interface, different body” without runtime checks.

## Logic Walkthrough
`findMax` deduced; specialized path for doubles; `StaticArray` set/get; `sumAll` fold; `printTypeInfo` picks integral/float/other at compile time.

## Dry Run
`findMax(10,20)=20`; `findMax('a','z')='z'`; double path prints specialization. `sumAll(1..5)=15`; `sumAll(1.5,2.5,3.5)=7.5`. `100` → Integral; `3.14` → Floating; C-string → other.

## Time & Space Complexity
Runtime of demos **O(1)** / **O(k)** for k pack args. Templates cost **compile time**, not runtime indirection. `StaticArray` is **O(1)** access, Size×sizeof(T) stack. Why: section 4 stack array.

## Trade-offs & Alternatives
Concepts (C++20) instead of `if constexpr` + traits; `std::array` in production; SFINAE/`requires` for constraints.

## Common Mistakes / Edge Cases
Missing `#include <type_traits>`; fold with heterogeneous types that don’t share `+`; ODR issues with specialization across TUs.

## Interview Follow-ups / Variations
Partial specialization; CRTP; expression templates; `std::tuple` via recursion.

## Tags
`templates`, `generic-programming`, `cpp17`, `intermediate`
