# Merge K Sorted Arrays

## 1. Problem Statement
[Interview classic](https://leetcode.com/problems/merge-k-sorted-lists/) (array form of LC 23) — interview classic — merge k sorted arrays into one sorted array (same heap pattern as LC 23).

- **Inputs:** `vector<vector<int>> arrays` each sorted ascending.
- **Output:** single sorted vector of all elements.
- **Valid answer:** min-heap over k frontiers.
- **Edges:** empty arrays; k=1; unequal lengths.

## 2. Intuition
Identical to merge k lists: heap stores current head of each array.

## 3. Brute Force → Optimal
- **Brute:** concatenate + sort — O(N log N).
- **Optimal:** heap — O(N log K).

## 4. Data Structure / Approach Justification
**Chosen:** `{val, arrayIdx, elemIdx}` min-heap.

- **vs pairwise merge:** also O(N log K).

## 5. Logic Walkthrough
Seed with index 0 of each non-empty array. Pop min, push next from same array.

## 6. Dry Run
`[1,4,7],[2,5,8],[3,6,9]` → `1..9`.

## 7. Time & Space Complexity
Time **O(N log K)**. Space **O(K + N)** output. Why: standard k-way (section 4).

## 8. Trade-offs & Alternatives
External sort building block; teach before/with LC 23.

## 9. Common Mistakes / Edge Cases
Not advancing elemIdx; pushing empty arrays; unstable index typing.

## 10. Interview Follow-ups / Variations
Merge k sorted lists (23); smallest range (632).

## 11. Tags
`heap`, `k-way-merge`, `interview`, `interview-classic`, `difficulty:medium`
