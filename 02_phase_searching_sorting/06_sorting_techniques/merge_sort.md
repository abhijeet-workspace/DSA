# Merge Sort

## 1. Problem Statement
Classic algorithm — sort by dividing in half, sorting each half, then merging sorted runs.

- **Inputs:** `vector<int> arr`, range `[lo, hi]`.
- **Output:** `arr[lo..hi]` sorted ascending.
- **Valid answer:** non-decreasing; equal keys keep relative order (stable).
- **Edges:** empty; odd length; duplicates.

## 2. Intuition
Two sorted halves merge in O(N). Recurse until size 1, then merge upward — T(n)=2T(n/2)+O(n).

## 3. Brute Force → Optimal
- **Brute:** poorly structured recursive combines without balanced split — wasteful.
- **Optimal:** balanced divide-and-conquer → Θ(N log N) always.

## 4. Data Structure / Approach Justification
**Chosen:** temp left/right buffers per merge (clear, stable).

- **vs quick sort:** merge is stable + predictable; needs O(N) aux.
- **vs TimSort:** adaptive on natural runs; still merge-based.

## 5. Logic Walkthrough
If `lo >= hi` return. `mid = lo+(hi-lo)/2`; sort left, sort right; merge with `<=` for stability; copy leftovers.

## 6. Dry Run
`[4,1,3,2]` → `[4,1]|[3,2]` → `[1,4]|[2,3]` → merge `[1,2,3,4]`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: log N levels × O(N) merge work (section 4).

## 8. Trade-offs & Alternatives
Stable and predictable; aux memory. Prefer quick/introsort when in-place speed matters; merge for linked lists / external sort.

## 9. Common Mistakes / Edge Cases
Midpoint overflow (`(lo+hi)/2`); forgetting leftover copy; using `<` and losing stability.

## 10. Interview Follow-ups / Variations
External sort; linked-list merge sort (O(1) extra); count inversions during merge.

## 11. Tags
`sorting`, `merge-sort`, `divide-and-conquer`, `stable`, `difficulty:medium`
