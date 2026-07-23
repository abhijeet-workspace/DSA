# Longest Consecutive Sequence

## 1. Problem Statement
Return the length of the longest consecutive elements sequence in unsorted `nums`.

- **Input:** `vector<int> nums`
- **Output:** int length
- **Valid answer:** max run of consecutive integers (order in array irrelevant)
- **Edges:** empty; duplicates; negatives; single element

## 2. Intuition
Only start a streak from a number with no predecessor (`x-1` missing). Expand upward.

## 3. Brute Force → Optimal
- **Brute:** sort unique then scan runs — O(N log N).
- **Optimal:** hash set + start-only expansion — O(N) average.

## 4. Data Structure / Approach Justification
`unordered_set` for O(1) avg membership and dedup.

| Alternative | Why it loses here |
|-------------|-------------------|
| Sort | O(N log N) |
| Expand from every x | Degenerates to O(N²) |

## 5. Logic Walkthrough
1. Insert all into set.
2. For each `x`, skip if `x-1` exists.
3. Else walk `x, x+1, ...` counting length; track max.

## 6. Dry Run
`nums=[100,4,200,1,3,2]`
- starts: 100, 200, 1
- from 1: 1→2→3→4 length **4**

## 7. Time & Space Complexity
- **Time:** O(N) average
- **Space:** O(N)
- Why: each number visited at most twice (set + streak walk).

## 8. Trade-offs & Alternatives
Set uses O(N) memory. Sort uses less extra space if in-place allowed. Union-Find on neighbors also works.

## 9. Common Mistakes / Edge Cases
Expanding from every number; forgetting duplicates; empty → 0.

## 10. Interview Follow-ups / Variations
Return the sequence itself? Online insertions?

## 11. Tags
`hash-set`, `sequence`, `leetcode-128`, `medium`
