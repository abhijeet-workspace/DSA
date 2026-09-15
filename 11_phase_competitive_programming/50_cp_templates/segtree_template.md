# SegTree Template

## 1. Problem Statement
Teaching-lab — recursive segment tree: build, point set, range sum.

## 2. Intuition
Complete binary tree over array intervals; parent = combine(children).

## 3. Brute Force → Optimal
- **Brute:** O(n) scan. **Optimal:** O(log n) query/update.

## 4. Data Structure / Approach Justification
**Chosen:** recursive sum segtree.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
Build bottom-up via recursion; query splits at mid; update climbs combine.

## 6. Dry Run
`[1,2,3,4,5]` range[1..3]=9; set index 2→10 → range=16.

## 7. Time & Space Complexity
Build **O(n)**; query/update **O(log n)**. Space **O(n)**.

## 8. Trade-offs & Alternatives
Lazy prop for range updates; iterative segtree for constants.

## 9. Common Mistakes / Edge Cases
Wrong `l>r` base; 4n sizing; forgetting combine on update.

## 10. Interview Follow-ups / Variations
Min/max/GCD combine; lazy add.

## 11. Tags
`segment-tree`, `template`, `range-query`, `difficulty:medium`
