# Count of Smaller Numbers After Self

## 1. Problem Statement
[LeetCode 315](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) — for each `nums[i]`, count how many `nums[j]` with `j > i` and `nums[j] < nums[i]`.

- **Inputs:** `vector<int> nums`.
- **Output:** `vector<int>` counts aligned with indices.
- **Valid answer:** exact per-index counts.
- **Edges:** empty; sorted ascending/descending; duplicates.

## 2. Intuition
Process right→left while maintaining a Fenwick/segment tree of frequencies over ranks; query prefix sum of values strictly smaller.

## 3. Brute Force → Optimal
- **Brute:** nested loops — O(N²).
- **Optimal:** coordinate compress + Fenwick — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** Fenwick of frequencies on compressed ranks.

- **vs merge-sort count:** also O(N log N); Fenwick matches this topic.

## 5. Logic Walkthrough
Compress values. From right: `ans[i]=query(rank-1)`; `add(rank,1)`.

## 6. Dry Run
`[5,2,6,1]` → `[2,1,1,0]`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: each update/query log N (section 4).

## 8. Trade-offs & Alternatives
Merge-sort inversion counting avoids trees; Fenwick is reusable for online updates.

## 9. Common Mistakes / Edge Cases
Wrong compression (not unique sorted); querying ≤ instead of <; left-to-right without care.

## 10. Interview Follow-ups / Variations
Count greater after self; reverse pairs (493).

## 11. Tags
`fenwick`, `coordinate-compression`, `leetcode-315`, `difficulty:hard`
