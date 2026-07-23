# Smart Pointers

## Problem Statement
Demonstrate:
1. `unique_ptr` exclusive ownership + move.
2. `shared_ptr` reference counting.
3. Cycle leak with mutual `shared_ptr` links.
4. Breaking cycles with `weak_ptr`.

**Inputs:** named `Node` objects.  
**Valid answer:** construct/destruct logs showing when memory frees (or doesn’t).  
**Edges:** empty `unique_ptr` after move; expired `weak_ptr`.

## Intuition
RAII wrappers automate `delete`. Prefer unique ownership; share only when needed; observe without owning via `weak_ptr` to avoid cycles.

## Brute Force → Optimal
- **Brute:** raw `new`/`delete` — leaks on early returns/exceptions.
- **Optimal:** `make_unique` / `make_shared`; `weak_ptr` for back-edges in graphs.

## Data Structure / Approach Justification (REQUIRED)
`Node` with both `shared_ptr` and `weak_ptr` next links to contrast owning vs observing edges.
- **`unique_ptr`:** trees/DAGs with clear parents — zero overhead vs raw.
- **`shared_ptr`:** shared subgraphs — pays control-block + atomics.
- **`weak_ptr` vs raw observer:** safe `lock()` vs dangling raw pointer.

## Logic Walkthrough
`demoUniquePtr` moves ownership; `demoSharedPtr` shows `use_count`; cycle demo sets A↔B with `nextNode` (leak); safe demo uses `weakNextNode` (destructors run).

## Dry Run
Unique: construct UniqueNode1 → move → destroy at scope end. Shared: count 1→2→1→0 with destroy. Cycle: construct A,B — **no** destructors. Weak: both destructors print.

## Time & Space Complexity
`unique_ptr`: ~raw pointer size, O(1). `shared_ptr`: control block (~16–24B) + atomic increments. Cycle leak: unbounded lifetime (never freed). Why: ownership model in section 4.

## Trade-offs & Alternatives
Intrusive refcounts; arena/pool allocators for graphs; `unique_ptr` + raw non-owning observers when lifetimes are guaranteed.

## Common Mistakes / Edge Cases
Creating two `shared_ptr` from the same raw pointer; cycles; using `weak_ptr` without `lock()`; copying `unique_ptr`.

## Interview Follow-ups / Variations
Implement `MyUniquePtr`; enable_shared_from_this; custom deleters for FILE*/sockets.

## Tags
`smart-pointers`, `raii`, `memory`, `intermediate`
