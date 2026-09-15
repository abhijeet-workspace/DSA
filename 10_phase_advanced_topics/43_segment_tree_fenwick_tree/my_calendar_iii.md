# My Calendar III

## 1. Problem Statement
[LeetCode 732](https://leetcode.com/problems/my-calendar-iii/) — book `[start, end)`; return the max number of overlapping events after each booking (k-booking).

- **Inputs:** stream of bookings.
- **Output:** current max overlap after each `book`.
- **Valid answer:** maximum concurrent events.
- **Edges:** touching intervals (no overlap); nested; identical.

## 2. Intuition
Sweep difference map: +1 at start, −1 at end; scan keys for running sum max. Equivalent to a segment tree of range adds + global max.

## 3. Brute Force → Optimal
- **Brute:** check all pairs each time.
- **Optimal:** ordered difference map — O(N) scan per book, or segtree O(log C).

## 4. Data Structure / Approach Justification
**Chosen:** `map<int,int>` difference array.

- **vs segtree:** map is enough for interview constraints.

## 5. Logic Walkthrough
On book: `diff[start]++`; `diff[end]--`; scan running sum for max.

## 6. Dry Run
book(10,20)→1; book(50,60)→1; book(10,40)→2; book(5,15)→3.

## 7. Time & Space Complexity
Time **O(N)** per book (scan). Space **O(N)**.

## 8. Trade-offs & Alternatives
Segment tree with lazy range add + max query is O(log) with compression.

## 9. Common Mistakes / Edge Cases
Treating touching as overlap; forgetting end decrement.

## 10. Interview Follow-ups / Variations
My Calendar I/II; Range Module.

## 11. Tags
`sweep-line`, `difference-array`, `leetcode-732`, `difficulty:hard`
