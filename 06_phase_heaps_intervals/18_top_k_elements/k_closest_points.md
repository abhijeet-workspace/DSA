# K Closest Points to Origin

## Problem Statement
[LeetCode 973](https://leetcode.com/problems/k-closest-points-to-origin/) — return the k points closest to the origin `(0, 0)`.

- **Inputs:** `vector<vector<int>> points` where each point is `[xi, yi]`, `int k`.
- **Output:** any order of the k closest points (ties broken arbitrarily).
- **Valid answer:** Euclidean distance; squared distance is fine for comparisons.
- **Edges:** k = 1; k = n; ties; points on axes; negatives.

## Intuition
“K closest” = keep a bounded set of candidates. A max-heap of size k keyed by distance² drops the farthest whenever size exceeds k.

## Brute Force → Optimal
- **Brute:** compute all distances, sort, take first k — O(N log N).
- **Optimal:** size-k max-heap — O(N log K).
- **Also:** Quickselect on distance — O(N) average.

## Data Structure / Approach Justification
**Chosen:** `priority_queue<pair<int,int>>` max-heap of `{dist², index}`, size ≤ k.

- **vs sort all:** unnecessary when K ≪ N.
- **vs min-heap of all N then pop k:** O(N + K log N); size-k max-heap wins for small K.
- **vs Quickselect:** faster average but mutates and harder to code under time pressure.

## Logic Walkthrough
For each point `i`, compute `dist = x*x + y*y`, push `{dist, i}`. If heap size > k, pop. Drain heap into `result` (order may differ from sorted).

## Dry Run
`points=[[1,3],[-2,2]]`, `k=1`:
- `[1,3]` → dist²=10 → heap `{(10,0)}`
- `[-2,2]` → dist²=8 → push → size 2 → pop `(10,0)` → heap `{(8,1)}`
- result = **[-2,2]**

## Time & Space Complexity
Time **O(N log K)**. Space **O(K)** for the heap (+ O(K) output). Why: N bounded heap ops (section 4).

## Trade-offs & Alternatives
Squared distance avoids `sqrt` and preserves order. Prefer Quickselect for tight time limits; prefer full sort when you also need ranking of all points.

## Common Mistakes / Edge Cases
Using Euclidean without squaring (precision); min-heap of size k (keeps farthest); returning indices instead of points; k = n.

## Interview Follow-ups / Variations
K farthest points; weighted distance; streaming points; return sorted by distance.

## Tags
`heap`, `top-k`, `geometry`, `max-heap`, `leetcode-973`, `difficulty:medium`
