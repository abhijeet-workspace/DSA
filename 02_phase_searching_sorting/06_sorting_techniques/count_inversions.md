# Count Inversions

## Problem Statement
Count pairs `(i, j)` with `i < j` and `arr[i] > arr[j]` (merge-sort variant).

- **Inputs:** `vector<int> arr`.
- **Output:** `long long` inversion count.
- **Valid answer:** number of such pairs.
- **Edges:** sorted (0); reverse sorted (N(N-1)/2); duplicates (`<=` does not invert).

## Intuition
During merge, when `arr[j]` from the right half is smaller, all remaining left-half elements `i..mid-1` form inversions with `j`.

## Brute Force → Optimal
- **Brute:** all pairs — O(N²).
- **Optimal:** modified merge sort — O(N log N).

## Data Structure / Approach Justification
**Chosen:** `mergeSort` + `merge` accumulating `invCount += (mid - i)`.

- **vs Fenwick/segment tree on ranks:** also O(N log N); heavier setup.
- **vs pair scan:** too slow for large N.

## Logic Walkthrough
Recurse left/right; on merge, if left value ≤ right, take left; else take right and add remaining left count. Copy `temp` back.

## Dry Run
`[2,4,1,3,5]`:
- inversions `(2,1),(4,1),(4,3)` → 3

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)** temp. Why: merge-sort tree of merges (section 4).

## Trade-offs & Alternatives
Mutates the array (sorts it). Copy first if original order must stay.

## Common Mistakes / Edge Cases
Using `int` for count (overflow); wrong mid in merge call (`mid+1`); treating equals as inversions.

## Interview Follow-ups / Variations
Count reverse pairs (LC 493); smaller elements after self.

## Tags
`sorting`, `merge-sort`, `divide-conquer`, `difficulty:medium`
