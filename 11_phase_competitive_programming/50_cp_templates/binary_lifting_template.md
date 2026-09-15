# Binary Lifting Template

## 1. Problem Statement
Teaching-lab — `up[k][v]` = 2^k-th ancestor. Demo kth ancestors on a small tree. Related: [LC 1483](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/).

## 2. Intuition
Any jump k decomposes into bits of k using precomputed doubles.

## 3. Brute Force → Optimal
- **Brute:** climb parent k times. **Optimal:** O(log n) with O(n log n) prep.

## 4. Data Structure / Approach Justification
**Chosen:** parent binary lifting.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

Full LCA binary lifting also in Euler/LCA folder.

## 5. Logic Walkthrough
DFS fills `up[0]`; DP doubles; query walks set bits.

## 6. Dry Run
kth(3,1)=1, kth(3,2)=0, kth(4,1)=2.

## 7. Time & Space Complexity
Prep **O(n log n)**; query **O(log n)**.

## 8. Trade-offs & Alternatives
Extend to LCA by equalizing depth then joint lift.

## 9. Common Mistakes / Edge Cases
Overflow when k > depth; -1 parent handling.

## 10. Interview Follow-ups / Variations
Weighted jumps; functional graphs.

## 11. Tags
`binary-lifting`, `trees`, `template`, `difficulty:medium`
