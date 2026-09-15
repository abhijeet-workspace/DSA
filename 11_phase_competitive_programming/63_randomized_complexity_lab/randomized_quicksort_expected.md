# Randomized Quicksort Expected Complexity

## 1. Problem Statement
Implement randomized quicksort and note expected O(N log N) via random pivots.

- **Inputs:** array of ints.
- **Output:** sorted array.
- **Edges:** duplicates; already sorted; n≤1.

## 2. Intuition
Random pivot makes adversary order irrelevant; expected comparisons ~ 2N ln N.

## 3. Brute Force → Optimal
- **Deterministic quicksort:** O(N²) worst.
- **Randomized:** expected O(N log N); heapsort worst O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** random pivot partition + recurse.

| Alternative | Note |
|-------------|------|
| `std::sort` | Introsort |
| Merge sort | Guaranteed |

## 5. Logic Walkthrough
1. Pick random pivot index.
2. Partition.
3. Recurse sides.

## 6. Dry Run
`[3,1,4,1,5]` → `[1,1,3,4,5]`.

## 7. Time & Space Complexity
Expected **O(N log N)** time; **O(log N)** stack expected.

## 8. Trade-offs & Alternatives
Simple; worst case still O(N²) with tiny probability.

## 9. Common Mistakes / Edge Cases
Not randomizing; bad partition on duplicates.

## 10. Interview Follow-ups / Variations
3-way partition; compare to merge.

## 11. Tags
`quicksort`, `randomized`, `expected-complexity`, `difficulty:medium`
