# Falling Squares

## 1. Problem Statement
[LeetCode 699](https://leetcode.com/problems/falling-squares/) — squares fall onto the x-axis; each lands atop the max height overlapping its interval. Return heights after each drop.

- **Inputs:** positions `[left, sideLength]`.
- **Output:** height of the tallest square after each drop.
- **Valid answer:** running global max height after each square.
- **Edges:** adjacent touching; nested; identical intervals.

## 2. Intuition
Each square queries max height on `[L,R)` then updates that range to `max+side`. Segment tree with lazy range update / range max.

## 3. Brute Force → Optimal
- **Brute:** keep list of intervals — O(N²).
- **Optimal:** compress coords + segtree lazy — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** coordinate compress endpoints; lazy segtree range-max assign + query.

- **vs sorted map of intervals:** shorter; segtree fits this topic.

## 5. Logic Walkthrough
Compress. For each square: `h = query(L,R-1)+side`; `update(L,R-1,h)`; push h.

## 6. Dry Run
`[[1,2],[2,3],[6,1]]` → `[2,5,5]`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
Interval tree / map merge is fine for interviews if segtree lazy is rusty.

## 9. Common Mistakes / Edge Cases
Inclusive vs exclusive right; forgetting compression of `pos+len`; lazy push bugs.

## 10. Interview Follow-ups / Variations
Skyline; Range Module.

## 11. Tags
`segment-tree`, `lazy`, `leetcode-699`, `difficulty:hard`
