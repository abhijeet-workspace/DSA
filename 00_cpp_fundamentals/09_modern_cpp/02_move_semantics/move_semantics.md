# Move Semantics

## Problem Statement
Show lvalue/rvalue transfer for a resource-owning class: copy ctor (deep) vs move ctor / move assignment (steal pointer), leaving sources in a safe empty state.

**Inputs:** `ResourceWrapper` sizes.  
**Valid answer:** console traces of which special member runs; no double-free.  
**Edges:** self-move-assignment; moved-from object destruction.

## Intuition
Heavy buffers should transfer ownership when the source is expiring (`std::move` / temporaries), turning O(N) deep copies into O(1) pointer swaps.

## Brute Force → Optimal
- **Brute (pre-C++11):** always deep copy — returning large vectors was expensive.
- **Optimal:** move ctor/assign + RVO/NRVO for returns → O(1) ownership transfer.

## Data Structure / Approach Justification (REQUIRED)
Custom `ResourceWrapper` owning `int* data` + `size` — mirrors what `vector` does internally so the steal is visible.
- **vs `std::vector` alone:** hides move; teaching needs explicit `new[]`/`delete[]`.
- **vs copy-only rule of three:** correct but slow for temporaries; rule of five adds moves.

## Logic Walkthrough
Construct `res1`; copy to `res2`; `std::move(res1)` → `res3` (steal); move-assign `res2` into `res3`; destructors free only non-null buffers.

## Dry Run
`res1(100)` allocates. Copy → second buffer of 100. Move ctor → `res3` holds pointer, `res1.data=nullptr`. Move assign → free `res3`’s old buffer, steal `res2`’s, null `res2`. Three destructor lines: free once for remaining owner(s), “stolen state” for emptied ones.

## Time & Space Complexity
Copy: **O(N)** time/space. Move: **O(1)** time, no new allocation. Why: pointer steal vs element-wise copy (section 4).

## Trade-offs & Alternatives
`= default` moves when members are movable; `noexcept` moves enable strong STL optimizations (vector reallocation).

## Common Mistakes / Edge Cases
Thinking `std::move` moves by itself (it’s a cast); forgetting to null source → double-free; omitting `noexcept` on moves.

## Interview Follow-ups / Variations
Implement `MyVector` with growth + moves; perfect forwarding `T&&`; move-only types (`unique_ptr`).

## Tags
`move-semantics`, `raii`, `cpp11`, `intermediate`
