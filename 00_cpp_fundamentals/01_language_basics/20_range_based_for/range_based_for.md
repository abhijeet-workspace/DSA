# Range-based for

## 1. Problem Statement
Demonstrate C++11 range-based `for` over a C array, `std::vector`, and `std::string`, including mutation via reference and `const auto&`.

- **Input:** none
- **Output:** printed elements; vector values become 11 21 31
- **Valid answer:** `for (T x : c)` copies; `for (T& x : c)` mutates; `const auto&` observes
- **Edges:** range-for needs `begin`/`end` (or array bounds); do not invalidate iterators mid-loop carelessly

## 2. Intuition
When you need every element and do not need the index, range-for removes boilerplate and index bugs.

## 3. Brute Force → Optimal
- **Naive:** classic index loops everywhere.
- **This approach:** range-for for whole-container traversals; index loops when the index matters.

## 4. Data Structure / Approach Justification
Array + vector + string — three common range sources.

| Alternative | Why it loses here |
|-------------|-------------------|
| Index `for` | Needed for random access by position |
| Iterators explicitly | More control; more verbose (see STL iterators lesson) |

## 5. Logic Walkthrough
1. Print array by value copies.
2. Add 1 to each vector element through `int&`.
3. Walk string characters.
4. Re-print vector with `const auto&`.

## 6. Dry Run
| Container | Mode | Effect |
|-----------|------|--------|
| `arr` | `int x` | prints 1 2 3 4 |
| `v` | `int& x` | becomes 11 21 31 |
| `s` | `char c` | prints h i |

## 7. Time & Space Complexity
- **Time:** O(n)
- **Space:** O(1) extras (unless copying large `T` by value)
- Why: single pass

## 8. Trade-offs & Alternatives
- Prefer `const auto&` for large elements.
- Prefer index loops when you need `i` or strides.
- Prefer algorithms (`for_each`, ranges) in modern codebases.

## 9. Common Mistakes / Edge Cases
- `for (auto x : bigObjects)` causing expensive copies
- Modifying a container in ways that invalidate the range
- Expecting range-for on raw pointers without extent

## 10. Interview Follow-ups / Variations
- How does range-for expand in terms of `begin`/`end`?
- Structured bindings in range-for over maps?
- C++20 ranges views?

## 11. Tags
`cpp-basics`, `range-for`, `auto`, `beginner`
