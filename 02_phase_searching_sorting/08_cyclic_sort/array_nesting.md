# Array Nesting

## 1. Problem Statement
[LeetCode 565](https://leetcode.com/problems/array-nesting/) — `nums` is a permutation of `0..n-1`. A set `S` starts at `S = {nums[k]}` and repeatedly inserts `nums[i]` for the last inserted `i`. Return the size of the largest such set.

- **Inputs:** `vector<int> nums` (permutation of `0..n-1`).
- **Output:** length of longest nest.
- **Edges:** identity; one big cycle; `n = 1`.

## 2. Intuition
`i → nums[i]` is a functional graph of disjoint cycles (permutation). Nest size from any start equals the length of its cycle. Follow index cycles; mark visited to avoid rework.

## 3. Brute Force → Optimal
- **Brute:** start from every index, follow until repeat — O(N²) worst.
- **Optimal:** each index belongs to one cycle — visit once, O(N) total.

## 4. Data Structure / Approach Justification
**Chosen:** cycle following with in-place visit marks (set `nums[i] = -1` or use a bool array).

- **vs bool visited:** clearer, O(N) space.
- **vs mutating:** O(1) extra if allowed.

## 5. Logic Walkthrough
1. For each unvisited `i`, walk `j = nums[j]` counting length until a visited node.
2. Track global max length.
3. Mark nodes visited as you traverse.

## 6. Dry Run
`[5,4,0,3,1,6,2]`:
- cycle `0→5→6→2→0` length 4 (max);
- cycle `1→4→1` length 2;
- `3→3` length 1 → answer `4`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) if mutate / O(N) with visited flags

## 8. Trade-offs & Alternatives
Same cycle idea as rotate-array following, but you measure length instead of writing values.

## 9. Common Mistakes / Edge Cases
Recounting the same cycle from every member; infinite loop without visit marks; assuming one cycle only.

## 10. Interview Follow-ups / Variations
Circular Array Loop (457); Couples Holding Hands (765); longest cycle in a directed graph.

## 11. Tags
`cyclic-sort`, `array`, `cycle-following`, `leetcode-565`, `difficulty:medium`
