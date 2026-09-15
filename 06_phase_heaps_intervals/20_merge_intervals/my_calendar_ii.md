# My Calendar II

## 1. Problem Statement
[LeetCode 731](https://leetcode.com/problems/my-calendar-ii/) — book `[start,end)` if it does not cause a triple booking (overlap of three events).

- **Inputs:** sequence of `book(start,end)`.
- **Output:** true if accepted.
- **Valid answer:** allow double overlaps; reject triple.
- **Edges:** touching OK; nested double; attempt triple.

## 2. Intuition
Keep all bookings and the regions that are already double-booked. Reject if new interval hits any double region.

## 3. Brute Force → Optimal
- **Brute:** store all and count overlap depth each query — O(N²).
- **Optimal enough:** explicit overlap list — O(N) per book (N≤1000).

## 4. Data Structure / Approach Justification
**Chosen:** vector of bookings + vector of overlap intervals.

- **vs sweep / tree of deltas:** better asymptotics for III.

## 5. Logic Walkthrough
If intersects any overlap → false. Else for each booking intersection, record overlap segment; append booking.

## 6. Dry Run
book(10,20), (50,60), (10,40) OK (double on [10,20)); book(5,15) hits overlap → false.

## 7. Time & Space Complexity
Time **O(N)** per book, **O(N²)** total. Space **O(N)**. Why: scan stored intervals (section 4).

## 8. Trade-offs & Alternatives
Simple for constraints. Calendar III needs segment tree / sweep counts.

## 9. Common Mistakes / Edge Cases
Rejecting all doubles; inclusive end; not storing overlap of new with each booking.

## 10. Interview Follow-ups / Variations
My Calendar I / III; Range Module.

## 11. Tags
`intervals`, `design`, `sweep-line`, `leetcode-731`, `difficulty:medium`
