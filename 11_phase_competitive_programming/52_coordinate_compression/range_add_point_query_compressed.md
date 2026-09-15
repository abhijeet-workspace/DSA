# Range Add Point Query Compressed

## 1. Problem Statement
Teaching-lab — range add / point query after compressing endpoints.

## 2. Intuition
Diff array needs dense indices.

## 3. Brute Force → Optimal
- BIT online. Diff offline.

## 4. Data Structure / Approach Justification
**Chosen:** compress + difference array.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
±v; prefix; query rank.

## 6. Dry Run
10→4, 50→6, 100→3.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Inclusive R care.

## 9. Common Mistakes / Edge Cases
Open/closed.

## 10. Interview Follow-ups / Variations
Range update range query.

## 11. Tags
`coordinate-compression`, `teaching-lab`, `difficulty:medium`

