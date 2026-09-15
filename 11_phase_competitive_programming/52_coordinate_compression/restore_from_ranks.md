# Restore From Ranks

## 1. Problem Statement
Teaching-lab — inverse of compression via `coords[rank-1]` (pairs with `compress_ranks`).

## 2. Intuition
Bijection unique values ↔ ranks.

## 3. Brute Force → Optimal
- Keep sorted unique vector.

## 4. Data Structure / Approach Justification
**Chosen:** explicit restore.

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Index into coords.

## 6. Dry Run
Matches originals.

## 7. Time & Space Complexity
**O(n)**.

## 8. Trade-offs & Alternatives
0-based vs 1-based.

## 9. Common Mistakes / Edge Cases
Wrong index base.

## 10. Interview Follow-ups / Variations
Offline decoding.

## 11. Tags
`coordinate-compression`, `teaching-lab`, `difficulty:easy`

