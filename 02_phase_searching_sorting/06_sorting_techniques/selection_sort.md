# Selection Sort

## 1. Problem Statement
Classic algorithm — sort by repeatedly selecting the minimum of the unsorted suffix and swapping it into place.

- **Inputs:** `vector<int> arr` (mutated in place).
- **Output:** `arr` sorted ascending.
- **Valid answer:** non-decreasing order.
- **Edges:** empty; duplicates; already sorted.

## 2. Intuition
At index `i`, scan `i..n-1` for the minimum and swap it into `arr[i]`. Prefix `arr[0..i]` becomes the `i+1` smallest elements.

## 3. Brute Force → Optimal
- **Brute / this algo:** nested min-scan — always Θ(N²) compares.
- **Write-optimal angle:** exactly ≤ N−1 swaps (useful when writes are costly).

## 4. Data Structure / Approach Justification
**Chosen:** in-place min-index tracking + one swap per outer step.

- **vs heap sort:** same "extract min/max" idea with O(N log N) via heap.
- **vs insertion:** selection always Θ(N²); insertion adaptive on nearly sorted.

## 5. Logic Walkthrough
For each `i`, set `minIdx = i`, scan right for smaller values, then `swap(arr[i], arr[minIdx])`.

## 6. Dry Run
`[5,2,4,1]`:
- `i=0`: min at 3 → swap → `[1,2,4,5]`
- further passes leave order intact

## 7. Time & Space Complexity
Time **O(N²)** always. Space **O(1)**. Why: N outer steps × O(N) scans (section 4).

## 8. Trade-offs & Alternatives
Few swaps, not stable, never adaptive. Prefer heap sort for guaranteed O(N log N) in-place.

## 9. Common Mistakes / Edge Cases
Claiming stability (swaps can reorder equal keys); swapping when `minIdx == i` unnecessarily (harmless).

## 10. Interview Follow-ups / Variations
When prefer selection over insertion? (Expensive writes.) Stable selection via shifting instead of swap.

## 11. Tags
`sorting`, `selection-sort`, `in-place`, `unstable`, `difficulty:easy`
