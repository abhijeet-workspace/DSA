# Line Sweep Max Cover

## 1. Problem Statement
Teaching-lab — longest segment where coverage ≥ K.

## 2. Intuition
Sweep depth; gaps under depth≥K.

## 3. Brute Force → Optimal
- Discretize brute. Sweep O(n log n).

## 4. Data Structure / Approach Justification
**Chosen:** ±1 events.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Sort; track max gap.

## 6. Dry Run
K=2 → longest event-gap length 2 (`[3,5)`).

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Total length ≥K variant.

## 9. Common Mistakes / Edge Cases
Closed interval bugs.

## 10. Interview Follow-ups / Variations
Meeting rooms.

## 11. Tags
`sweep-line`, `teaching-lab`, `difficulty:medium`

