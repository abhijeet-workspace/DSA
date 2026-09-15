# Count of Range Sum Compressed

## 1. Problem Statement
[LeetCode 327](https://leetcode.com/problems/count-of-range-sum/) — count subarrays with sum in `[lower,upper]` via compressed prefixes + BIT.

## 2. Intuition
pref[r]-pref[l] in range ⇔ prior pref in a window.

## 3. Brute Force → Optimal
- Brute O(n²). Compressed BIT O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** compress prefixes + Fenwick (compression focus vs Fenwick-topic twin).

**Pedagogy:** framed for **coordinate compression** (dense ranks for tree indices). Fenwick/SegTree topic owns tree ops; here the skill is sparse→`1..U`.

## 5. Logic Walkthrough
Build prefs; compress; query window; insert.

## 6. Dry Run
LC sample → 3.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Merge-sort count alternative.

## 9. Common Mistakes / Edge Cases
Inclusive bound off-by-ones.

## 10. Interview Follow-ups / Variations
Reverse pairs; count smaller.

## 11. Tags
`coordinate-compression`, `fenwick`, `leetcode-327`, `difficulty:hard`

