# Practice — Two Sum (Sorted)

## 1. Problem Statement
Practice drill: given a **sorted** array, return indices of two numbers summing to `target`.

- **Input:** ascending `nums`, `target`
- **Output:** `{L,R}` or empty
- **Edges:** no solution; pair at ends

## 2. Intuition
Same as Two Sum II: move the pointer that corrects the sum.

## 3. Brute Force → Optimal
- **Brute:** all pairs.
- **This drill:** two pointers O(N).

## 4. Data Structure / Approach Justification
Sorted vector + opposite indices (see `two_sum_ii.md`).

| Alternative | Why it loses here |
|-------------|-------------------|
| Hash map | Extra space; sorting already assumed |

## 5. Logic Walkthrough
L/R converge; adjust by sum vs target.

## 6. Dry Run
`[1,2,3,4,6]`, target 6 → `2+4` at indices `[1,3]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Identical to LC 167 pattern without 1-based indexing.

## 9. Common Mistakes / Edge Cases
Unsorted input; empty return not checked in main.

## 10. Interview Follow-ups / Variations
Count pairs; 3Sum practice next.

## 11. Tags
`practice`, `two-pointers`, `two-sum`, `sorted-array`
