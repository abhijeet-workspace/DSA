# Closest Pair 2D Sweep

## 1. Problem Statement
Teaching-lab — 2D closest pair via x-sort + active y-window (1D version already in folder).

## 2. Intuition
Keep points within best in x; probe y-neighbors.

## 3. Brute Force → Optimal
- Brute O(n²). Sweep O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** sweep + set on y.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Prune left; query band; update.

## 6. Dry Run
Matches brute.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
D&C textbook variant.

## 9. Common Mistakes / Edge Cases
Float eps; set keys.

## 10. Interview Follow-ups / Variations
1D closest.

## 11. Tags
`sweep-line`, `geometry`, `teaching-lab`, `difficulty:hard`

