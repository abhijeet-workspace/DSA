# Modern C++ Features (Overview Demo)

## Problem Statement
Tour C++11/14/17 features used heavily in DSA: structured bindings, lambdas as comparators, move semantics, `unique_ptr` trees, `optional`, `string_view`, and `if constexpr`.

**Inputs:** demo data embedded in each helper.  
**Valid answer:** printed demonstrations matching each feature’s semantics.  
**Edges:** moved-from objects usable only in valid empty state; empty `optional`; `string_view` lifetime.

## Intuition
Modern C++ removes ceremony (typed iterators, sentinel `-1`, manual `delete`) and costly copies so algorithmic code stays clear and fast.

## Brute Force → Optimal
| Feature | Old/brute | Modern |
|---|---|---|
| Map walk | verbose iterator types | `const auto& [k,v]` |
| Comparator | named functor struct | lambda |
| Return large buffer | deep copy | move / RVO |
| Tree nodes | raw `new`/`delete` | `unique_ptr` |
| Not found | `-1` sentinel | `optional` |
| Substring param | `string` copy | `string_view` |

## Data Structure / Approach Justification (REQUIRED)
Each demo picks the DS matching ownership/access needs:
- Intervals in `vector` + lambda sort (random access).
- Min-heap `priority_queue` with lambda cmp (Dijkstra-style).
- Tree via `unique_ptr` children (exclusive ownership, no cycles).
- **vs raw pointers:** leaks on exceptions; **vs `shared_ptr` for trees:** unnecessary atomic refcount when parent uniquely owns children.

## Logic Walkthrough
`demoStructuredBindings` unpacks pair/tuple/map; `demoLambdas` sorts intervals and drains a min-heap; `demoMoveSemantics` contrasts copy vs `std::move` on `LargeBuffer`; `demoSmartPointers` builds a 3-node tree; `findFirstEven` returns `optional`; `printPrefix` slices with `string_view`; `printValueInfo` uses `if constexpr`.

## Dry Run
Intervals `{{5,8},{1,4},{3,6}}` → sorted by start `1,3,5`. Heap pushes `{10,2},{3,1},{7,3}` → extract order distances 3,7,10. `findFirstEven({1,3,5,8,9})` → `8`; odd-only → `value_or(-1)`.

## Time & Space Complexity
Feature overhead: lambdas ~ zero; move O(1) vs copy O(N); `unique_ptr` same size as raw pointer; `string_view` substr O(1). Demo itself is O(small constants). Tied to section 4 choices.

## Trade-offs & Alternatives
Prefer RVO over explicit `move` on locals being returned; `shared_ptr` when ownership is genuinely shared; owning `string` when you need to mutate or outlive the source.

## Common Mistakes / Edge Cases
Dangling `string_view`; using moved-from object as if still full; `priority_queue` comparator polarity (min vs max); forgetting `decltype(cmp)` on pq.

## Interview Follow-ups / Variations
Custom allocators; `weak_ptr` cycles; C++20 ranges/`span`; `expected` for errors.

## Tags
`modern-cpp`, `cpp17`, `dsa`, `intermediate`
