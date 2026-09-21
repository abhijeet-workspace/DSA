# Dynamic Arrays

## Problem Statement
Allocate a runtime-sized array with `new[]`, fill and print it, then release with `delete[]`. Contrast with scalar `new`/`delete`.

**Decode**
- Inputs: `n=5`.
- Goal: correct array new/delete pairing.
- Valid: prints `10 20 30 40 50`.
- Edges: `delete` on `new[]` memory is UB; forgetting `delete[]` leaks.

## Intuition
Stack arrays need a compile-time size (mostly). Heap `new[]` lets size come from runtime input, but you own the lifetime.

## Brute Force → Optimal
Brute: oversized stack buffers.

Optimal teaching step: raw `new[]`/`delete[]`, then graduate to `std::vector` / smart pointers for ownership.

## Data Structure / Approach Justification
**Chosen:** `int* arr = new int[n]`.

Why: shows the exact ownership pair before RAII hides it.

**Alternatives**
1. `std::vector<int>` — preferred in production.
2. `std::unique_ptr<int[]>` — RAII without full vector features.

## Logic Walkthrough
1. `new int[n]` returns pointer to first element.
2. Fill with a loop.
3. `delete[] arr` destroys each element and frees storage.
4. Show scalar `new`/`delete` for contrast.

## Dry Run
| Step | State |
|------|-------|
| after `new int[5]` | 5 ints on heap |
| after fill | 10..50 |
| after `delete[]` | memory released; pointer dangling until nulled |

## Time & Space Complexity
- Time: O(n) to fill/print.
- Space: O(n) heap.
Why: contiguous array of n ints.

## Trade-offs & Alternatives
- Prefer `vector` for resizable arrays.
- Prefer `unique_ptr<T[]>` when you need a fixed owning buffer.
- Prefer containers that encode size (do not pass raw pointer alone).

## Common Mistakes / Edge Cases
- Mixing `new[]` with `delete`.
- Using after `delete[]` (use-after-free).
- Assuming `new int[n]` zero-initializes (`new int[n]{}` does value-init).

## Interview Follow-ups / Variations
- Placement new for arrays?
- Why vector growth amortizes reallocation?
- Exception safety if filling throws midway?

## Tags
`cpp-fundamentals`, `dynamic-memory`, `new-array`, `difficulty:easy`
