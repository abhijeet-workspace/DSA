# std::array

## 1. Problem Statement
Demonstrate `std::array<T,N>`: fixed size known at compile time, `.size()`, `at()`, iteration/sort, and copy assignment versus decay-prone C arrays.

- **Input:** none
- **Output:** size/front/back, sorted elements, independent copy mutation
- **Valid answer:** `array` copies like a value; size is part of the type
- **Edges:** `at(i)` throws on bad index; `operator[]` does not check

## 2. Intuition
When the length is fixed, `std::array` keeps stack allocation and adds container APIs without array-to-pointer decay in the same way C arrays do.

## 3. Brute Force → Optimal
- **Naive:** raw `T arr[N]` everywhere and pass pointer+length.
- **This approach:** `std::array` for fixed N; `vector` when N varies.

## 4. Data Structure / Approach Justification
**Chosen:** `std::array<int,4>`.

| Alternative | Why it loses here |
|-------------|-------------------|
| C array | No `.size()`, decays, not copy-assignable as a value |
| `vector` | Heap + runtime size; overkill for fixed tiny buffers |

## 5. Logic Walkthrough
1. Construct brace-initialized array.
2. Print size/front/back and elements.
3. Sort via iterators.
4. Copy to `b` and mutate `b[0]` to show value semantics.

## 6. Dry Run
| Step | `a` |
|------|-----|
| init | 4 1 3 2 |
| sort | 1 2 3 4 |
| copy to b; b[0]=99 | a unchanged first element 1 |

## 7. Time & Space Complexity
- **Access:** O(1)
- **sort:** O(n log n)
- **Space:** O(N) on stack (embedded storage)
- Why: contiguous fixed buffer

## 8. Trade-offs & Alternatives
- Prefer `array` for fixed compile-time sizes.
- Prefer `vector` for dynamic sizes.
- Prefer `span` (C++20) for non-owning views over either.

## 9. Common Mistakes / Edge Cases
- Expecting runtime resize (`array` cannot grow)
- Confusing `array<T,3>` with `array<T,4>` as the same type
- Using unchecked `[]` with untrusted indices

## 10. Interview Follow-ups / Variations
- How is `std::array` laid out vs `T[N]`?
- Zero-length `array<T,0>` support?
- `to_array` in C++20?

## 11. Tags
`stl`, `array`, `containers`, `beginner`
