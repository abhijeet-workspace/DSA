# Two Sum — Brute vs Two Pointers (Reference)

## 1. Problem Statement
Teaching contrast: find any two indices summing to `target` via nested loops vs sorted opposite pointers.

- **Input:** `list`, `target`
- **Output:** index pair (semantics differ: original vs sorted array)
- **Edges:** no pair; duplicates; unsorted input for pointer method

## 2. Intuition
Brute searches all pairs. Two pointers need **sorted** order so sum moves monotonically — sort a copy first if the original must stay unsorted.

## 3. Brute Force → Optimal
- **Brute:** O(N²) time, O(1) space; preserves original indices.
- **Sorted two pointers:** O(N log N) sort + O(N); indices refer to sorted array unless you track originals.
- **Hash map (not shown):** O(N) average, preserves original indices — usual LC 1 answer.

## 4. Data Structure / Approach Justification
Contrast only: `vector` + either nested indices or sorted L/R.

| Alternative | Why it loses here |
|-------------|-------------------|
| Hash map | Best for unsorted LC 1; this file teaches pointer vs brute |
| Binary search per i | O(N log N); between the two extremes |

## 5. Logic Walkthrough
1. Brute: for each i, scan j>i.
2. Two-pointer: sort copy; L/R like Two Sum II.

## 6. Dry Run
`[1,5,4,6,7,2,3]`, target 6:
brute finds `(0,5)` → `1+2`.
sorted `[1,2,3,4,5,6,7]` two-ptr finds indices of `1+5` or `2+4`.

## 7. Time & Space Complexity
- **Brute:** Time O(N²), Space O(1)
- **Two-pointer path:** Time O(N log N), Space O(N) for sorted copy (or O(1) if allowed to mutate)

## 8. Trade-offs & Alternatives
Pointer method alone is wrong on unsorted data. Hash map wins when original indices matter and array is unsorted.

## 9. Common Mistakes / Edge Cases
Running two pointers without sorting; confusing sorted indices with original indices.

## 10. Interview Follow-ups / Variations
LC 1 hash map; LC 167 sorted; count all pairs.

## 11. Tags
`two-sum`, `brute-force`, `two-pointers`, `reference`, `teaching`
