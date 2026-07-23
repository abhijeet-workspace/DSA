# Cyclic Sort

## Problem Statement
Sort an array that is a permutation of `1..N` in-place by placing each value `v` at index `v - 1`.

- **Inputs:** `vector<int> arr` containing each of `1..N` once.
- **Output:** same array sorted ascending.
- **Valid answer:** `arr[i] == i + 1` for all `i`.
- **Edges:** already sorted; reverse order; `N = 1`.

## Intuition
Every value knows its home index (`v - 1`). Swap until the current slot holds the right value, then advance.

## Brute Force → Optimal
- **Brute:** comparison sort — O(N log N) time, O(1)–O(N) space.
- **Optimal:** cyclic placement — O(N) time, O(1) extra space.

## Data Structure / Approach Justification
**Chosen:** in-place index swaps using the value-as-index invariant.

- **vs `std::sort`:** slower asymptotically when range is known.
- **vs counting sort:** same idea but cyclic sort needs no extra buffer for permutations.

## Logic Walkthrough
While `i < n`: let `correct = arr[i] - 1`. If `arr[i] != arr[correct]`, swap; else `++i`.

## Dry Run
`arr = [5,4,2,3,1]`:
- `i=0`, `5` ↔ `arr[4]` → `[1,4,2,3,5]`
- continue until `[1,2,3,4,5]`

## Time & Space Complexity
Time **O(N)** (each element swapped to place at most once). Space **O(1)** auxiliary. Why: finite swaps into fixed homes (section 4).

## Trade-offs & Alternatives
Requires known contiguous range / permutation. Outside that, fall back to comparison or hash-based sorts.

## Common Mistakes / Edge Cases
Off-by-one on `correct = v - 1`; infinite swap when duplicates exist; applying when values are not in `1..N`.

## Interview Follow-ups / Variations
Missing number; find duplicate; first missing positive — all reuse this placement pattern.

## Tags
`cyclic-sort`, `in-place`, `array`, `difficulty:easy`
