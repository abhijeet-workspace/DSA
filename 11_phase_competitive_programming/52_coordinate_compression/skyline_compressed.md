# Skyline Compressed

## 1. Problem Statement
Teaching-lab — [LC 218](https://leetcode.com/problems/the-skyline-problem/) via compressed x + segment paint. Sweep version in topic 53.

## 2. Intuition
Atomic x-segments store max height.

## 3. Brute Force → Optimal
- Multiset sweep O(n log n). Paint O(n·U) demo.

## 4. Data Structure / Approach Justification
**Chosen:** compress + paint.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Cover segments; emit changes.

## 6. Dry Run
Critical points match sample fragment.

## 7. Time & Space Complexity
**O(n·U)** / segtree better.

## 8. Trade-offs & Alternatives
Prefer sweep interviews.

## 9. Common Mistakes / Edge Cases
Half-open [L,R).

## 10. Interview Follow-ups / Variations
Lazy segtree.

## 11. Tags
`coordinate-compression`, `skyline`, `teaching-lab`, `difficulty:medium`

