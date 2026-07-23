# Dynamic Memory Allocation

## Problem Statement
Show heap allocation in C (`malloc`/`free`) and C++ (`new`/`delete`) for a single `int`, including write and release.

**Decode**
- Inputs: none (hard-coded values 10 and 20).
- Goal: allocate, assign/print, deallocate without leaks.
- Valid answer: prints both values; every alloc has a matching free.
- Edges: forgetting `free`/`delete`; mixing `malloc` with `delete`.

## Intuition
Stack lifetime ends with the scope. Heap lets you choose lifetime: allocate when needed, free when done. Pointers hold the heap address until you release it.

## Brute Force → Optimal
Brute: oversized stack arrays or globals — wastes memory and cannot grow at runtime.

Optimal for this demo: one `malloc`/`free` pair and one `new`/`delete` pair to contrast APIs.

## Data Structure / Approach Justification
**Chosen:** raw heap `int*` via `malloc` and `new`.

Why: teaches ownership pairing (`malloc`↔`free`, `new`↔`delete`) before RAII wrappers.

**Alternatives**
1. `std::unique_ptr<int>` — preferred in production; hides pairing rules.
2. `std::vector<int>` — better for arrays; heavier for a single int demo.

Trade-off: raw ownership is error-prone; acceptable only as a teaching step.

## Logic Walkthrough
1. `malloc(sizeof(int))` → untyped bytes; cast to `int*`.
2. `*p = 10` stores value; print; `free(p)`.
3. `new int(20)` allocates and constructs; print; `delete q`.

## Dry Run
| API | After alloc | After write | After free |
|-----|-------------|-------------|------------|
| malloc | p valid | *p=10 | p dangling — do not use |
| new | q valid | *q=20 | q dangling — do not use |

## Time & Space Complexity
- Time: O(1) allocate/free for one int (allocator cost ignored).
- Space: O(1) heap ints + pointers.
Why: fixed single-element allocations.

## Trade-offs & Alternatives
- Production: prefer `unique_ptr`/`shared_ptr` or containers.
- Arrays: use `new[]`/`delete[]` or `vector`.
- Never mix `malloc` with `delete` or `new` with `free`.

## Common Mistakes / Edge Cases
- Leak: allocate without free.
- Double-free / use-after-free.
- `new int` vs `new int(20)` (uninit vs init).
- Forgetting `delete[]` for arrays.

## Interview Follow-ups / Variations
- Implement a leak-safe wrapper around raw `new`.
- When does placement new help?
- Cost of frequent small allocations vs arena/pool.

## Tags
`cpp-fundamentals`, `dynamic-memory`, `heap`, `difficulty:easy`
