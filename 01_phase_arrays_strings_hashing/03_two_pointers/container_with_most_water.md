# Container With Most Water

## 1. Problem Statement
Vertical lines at `height[i]`; choose two indices maximizing water area `min(h[i],h[j]) * (j-i)`.

- **Input:** `height` length ≥ 2
- **Output:** max area (int)
- **Edges:** length 2; strictly decreasing; equal heights

## 2. Intuition
Width shrinks as pointers meet. Only a taller replacement for the shorter side can beat current area for that width class — so move the shorter pointer.

## 3. Brute Force → Optimal
- **Brute:** all pairs — O(N²).
- **Optimal:** opposite two pointers — O(N).

## 4. Data Structure / Approach Justification
Two indices on a random-access array; area depends only on endpoints.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested loops | Same answer, O(N²) |
| Stack “next greater” | Overkill; not needed for max rectangle between bars |

## 5. Logic Walkthrough
1. Start at ends; track `best`.
2. Area with current `L,R`.
3. Advance the side with smaller height (tie: either).
4. Until `L >= R`.

## 6. Dry Run
`[1,8,6,2,5,4,8,3,7]`:
`L=0,R=8` → area 8; move L.
`L=1,R=8` → min(8,7)*7=49 best; move R (shorter).
Continue → answer 49.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Moving the taller side never helps for that width; greedy choice is optimal.

## 9. Common Mistakes / Edge Cases
Always moving both pointers; using `R-L+1` for width; forgetting tie case still converges.

## 10. Interview Follow-ups / Variations
Trapping Rain Water (LC 42); max rectangle in histogram.

## 11. Tags
`two-pointers`, `greedy`, `geometry`, `leetcode-11`
