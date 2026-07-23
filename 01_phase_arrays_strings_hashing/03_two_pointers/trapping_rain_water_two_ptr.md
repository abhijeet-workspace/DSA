# Trapping Rain Water (Two Pointers)

## 1. Problem Statement
Elevation bars of width 1; compute total units of trapped rainwater.

- **Input:** non-negative `height`
- **Output:** total trapped water
- **Edges:** empty; strictly increasing; flat

## 2. Intuition
Water above `i` is bounded by the weaker of the best walls to the left and right. Process the side whose current bar is smaller — that side’s bound is known.

## 3. Brute Force → Optimal
- **Brute:** for each i scan left/right max — O(N²).
- **Prefix max arrays:** O(N) time, O(N) space.
- **Optimal here:** two pointers + running max — O(N) time, O(1) space.

## 4. Data Structure / Approach Justification
Opposite pointers with `left_max`/`right_max` scalars — no prefix arrays.

| Alternative | Why it loses here |
|-------------|-------------------|
| Pref/suf max arrays | Extra O(N) memory |
| Monotonic stack | Also O(N); more code for same result |

## 5. Logic Walkthrough
1. Maintain `left_max`, `right_max`.
2. If `h[L] < h[R]`, water from left side using `left_max`, then `++L`; else mirror on right.

## 6. Dry Run
`[0,1,0,2,1,0,1,3,2,1,2,1]` → trapped 6 (classic LC sample).

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
Stack solution also O(N)/O(N); prefer two-pointers when O(1) space is required.

## 9. Common Mistakes / Edge Cases
Adding water when bar equals max (should update max first); off-by-one at ends.

## 10. Interview Follow-ups / Variations
Container With Most Water; histogram largest rectangle.

## 11. Tags
`two-pointers`, `prefix-max`, `leetcode-42`, `hard`
