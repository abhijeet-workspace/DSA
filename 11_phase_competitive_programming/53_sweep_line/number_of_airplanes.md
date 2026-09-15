# Number of Airplanes

## 1. Problem Statement
Teaching/classic — max airplanes in sky; same sweep as Meeting Rooms II.

## 2. Intuition
+1 takeoff −1 landing.

## 3. Brute Force → Optimal
- Identical to meeting rooms.

## 4. Data Structure / Approach Justification
**Chosen:** event sweep.

**Pedagogy:** framed as **line sweep / timeline events**. Intervals topic may solve the same LC with sorting/greedy; here ±delta events and active structures.

## 5. Logic Walkthrough
Sort; track cur.

## 6. Dry Run
Max 3.

## 7. Time & Space Complexity
**O(n log n)**.

## 8. Trade-offs & Alternatives
Alias of LC 253 pattern.

## 9. Common Mistakes / Edge Cases
Landing before takeoff same time.

## 10. Interview Follow-ups / Variations
Car pooling.

## 11. Tags
`sweep-line`, `classic`, `difficulty:medium`

