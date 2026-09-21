# Pointer Arithmetic

## Problem Statement
Demonstrate array-to-pointer decay, `p[i]` vs `*(p+i)`, pointer increment by elements, and `const int*` vs `int* const`.

**Decode**
- Inputs: `int arr[] = {10,20,30,40}`.
- Goal: show pointers walk by element size.
- Valid: `*(p+1)==20`; `++p` moves to next int.
- Edges: arithmetic outside the array (or one-past-end misuse) is UB.

## Intuition
A typed pointer knows the size of its pointee. `p+1` advances by `sizeof(*p)` bytes.

## Brute Force → Optimal
Brute: only use index notation and never acknowledge decay.

Optimal teaching path: show equivalence of indexing and pointer arithmetic, then the decay that happens when arrays are passed to functions.

## Data Structure / Approach Justification
**Chosen:** stack array + raw pointers.

Why: teaches the model underneath `vector` iterators.

**Alternatives**
1. `std::array` / `std::span` — safer bounds-aware views later.
2. Index loops only — hide the address model.

## Logic Walkthrough
1. Let `p` point at `arr[0]`.
2. Read via `p[0]` and `*(p+1)`.
3. `++p` points at `arr[1]`.
4. Pass `arr` to `printFirst(const int*, n)` (decay).
5. Contrast pointer-to-const vs const-pointer.

## Dry Run
| Expression | Meaning |
|------------|---------|
| `p = arr` | &arr[0] |
| `*(p+1)` | 20 |
| `++p` | points at 20 |
| `p+1` address | previous + sizeof(int) |

## Time & Space Complexity
- Time: O(n) to print n elements.
- Space: O(1).
Why: single pass; no allocation.

## Trade-offs & Alternatives
- Prefer containers/`span` over raw pointer+length pairs in APIs.
- Prefer indices when clearer; prefer iterators in generic code.
- Prefer `const T*` for read-only traversal.

## Common Mistakes / Edge Cases
- Assuming `p+1` adds one byte.
- Using `sizeof(p)` as element count after decay.
- Walking off the end of the array.

## Interview Follow-ups / Variations
- Why is `arr` not assignable but `p` is?
- Difference between `int (*)[4]` and `int*`?
- How do random-access iterators relate to pointer arithmetic?

## Tags
`cpp-fundamentals`, `pointers`, `arrays`, `difficulty:easy`
