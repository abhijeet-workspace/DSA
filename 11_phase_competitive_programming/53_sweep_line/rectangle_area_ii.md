# Rectangle Area II

## 1. Problem Statement
[LeetCode 850](https://leetcode.com/problems/rectangle-area-ii/) — union area mod 1e9+7.

## 2. Intuition
Vertical sweep; covered y-measure.

## 3. Brute Force → Optimal
- Inclusion-exclusion. Sweep + compress.

## 4. Data Structure / Approach Justification
**Chosen:** same as union-area with modulo.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Events; cover; Δx·ylen.

## 6. Dry Run
LC sample → 6.

## 7. Time & Space Complexity
**O(n²)** / segtree faster.

## 8. Trade-offs & Alternatives
Twin of union-area lab.

## 9. Common Mistakes / Edge Cases
Mod overflow.

## 10. Interview Follow-ups / Variations
3D volume.

## 11. Tags
`sweep-line`, `leetcode-850`, `difficulty:hard`

