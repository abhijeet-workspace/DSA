# Recurrence Relations

## 1. Problem Statement
Implement algorithms whose runtimes match classic recurrences and verify Master Theorem / tree intuition in code.

- **Input:** unsorted array for merge sort; sorted array + target for binary search; array for inversion count
- **Output:** sorted array; index or -1; inversion total
- **Valid answer:** merge sort sorts ascending; inversions count pairs `(i,j)` with `i<j` and `a[i]>a[j]`
- **Edge cases:** empty/single-element ranges; target missing; reverse-sorted array (max inversions)

## 2. Intuition
Recursive algorithms cost `work(this call) + cost(subcalls)`. Writing that as `T(n)` lets you apply substitution, recursion trees, or the Master Theorem instead of hand-waving “it feels like n log n.”

## 3. Brute Force → Optimal
- **Naive inversions:** check all pairs → O(n²).
- **This approach:** same divide-and-conquer merge as merge sort; count split inversions during merge → O(n log n).
- Binary search is already optimal for comparison search on sorted arrays: `T(n)=T(n/2)+O(1)` → O(log n).

## 4. Data Structure / Approach Justification
**Chosen:** recursive merge / merge-and-count on `std::vector` with temporary half buffers.

| Alternative | Why it loses here |
|-------------|-------------------|
| Iterative bottom-up merge | Correct but hides the recurrence tree shape |
| Fenwick/segment tree inversions | Overkill for teaching Master Case 2 |
| Linear scan search | Wrong recurrence class for this lesson |

Trade-off: O(n) auxiliary space for clarity of the merge step.

## 5. Logic Walkthrough
1. `mergeSort` / `merge` — split, recurse, merge → `T(n)=2T(n/2)+O(n)`.
2. `binarySearch` — compare mid, recurse one half → `T(n)=T(n/2)+O(1)`.
3. `countInversions` / `mergeAndCount` — when taking from right half, add remaining left count as split inversions; same recurrence as merge sort.

## 6. Dry Run
Merge sort `{38,27,43,3,9,82,10}` → `{3,9,10,27,38,43,82}`; search `43` → found.

Inversions on `{8,4,2,1}`:
- pairs: (8,4),(8,2),(8,1),(4,2),(4,1),(2,1) → **6**

## 7. Time & Space Complexity
| Algorithm | Recurrence | Time | Extra space |
|-----------|------------|------|-------------|
| Merge sort | 2T(n/2)+O(n) | Θ(n log n) | O(n) |
| Binary search | T(n/2)+O(1) | Θ(log n) | O(log n) stack (recursive) |
| Inversion count | 2T(n/2)+O(n) | Θ(n log n) | O(n) |

Why: Master Theorem Case 2 for the balanced `n^E` combine work (section 4).

## 8. Trade-offs & Alternatives
- Substitution proves a guessed bound; trees help invent the guess; Master applies only to `aT(n/b)+f(n)`.
- Does not apply directly: Fibonacci `T(n)=T(n-1)+T(n-2)`, `T(n)=2T(n/2)+n/log n`, etc.

## 9. Common Mistakes / Edge Cases
- Applying Master when `a`/`b` are not constants or sizes unequal
- Forgetting base cases in induction
- Off-by-one mid calculation causing infinite recursion
- Double-counting inversions across merge stages

## 10. Interview Follow-ups / Variations
- Solve Tower of Hanoi: `T(n)=2T(n-1)+1` → Θ(2ⁿ)
- Strassen: `T(n)=7T(n/2)+O(n²)` → Θ(n^{log₂ 7})
- Convert recursive binary search to iterative — same asymptotics, O(1) stack

## 11. Tags
`recurrence-relations`, `master-theorem`, `merge-sort`, `binary-search`, `inversions`, `difficulty:medium`
