# Count Inversions

## 1. Problem Statement
Classic inversion count (CSES / interview): count pairs `i < j` with `a[i] > a[j]`.

- **Inputs:** array `a`.
- **Output:** inversion count.
- **Valid answer:** exact count.
- **Edges:** sorted; reverse-sorted; duplicates.

## 2. Intuition
Same as counting smaller after self aggregated: Fenwick while scanning right→left, or merge-sort merge counts.

## 3. Brute Force → Optimal
- **Brute:** O(N²).
- **Optimal:** Fenwick / merge-sort — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** Fenwick + coordinate compression (topic-aligned).

- **vs merge-sort:** equally classic.

## 5. Logic Walkthrough
Compress. From right: query `rank-1` (how many smaller already seen to the right… wait: right→left: query count of values already in tree that are `< a[i]`? Actually right→left inserts right elements; for inversions with j>i and a[j]<a[i], query sum(rank(a[i])-1).

## 6. Dry Run
`[2,3,8,6,1]` → **5**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Merge-sort is cache-friendlier; Fenwick generalizes to online.

## 9. Common Mistakes / Edge Cases
Compression ties; scanning left→right without adjusting query.

## 10. Interview Follow-ups / Variations
Reverse pairs; count smaller after self.

## 11. Tags
`fenwick`, `inversions`, `cses-style`, `difficulty:medium`
