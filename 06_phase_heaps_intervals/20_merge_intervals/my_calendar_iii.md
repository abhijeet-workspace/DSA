# My Calendar III

## 1. Problem Statement
[LeetCode 732](https://leetcode.com/problems/my-calendar-iii/) — `book` always succeeds; return the largest k such that some time is covered by k events (k-booking).

- **Inputs:** stream of bookings `[start,end)`.
- **Output:** current max overlap depth after each book.
- **Valid answer:** sweep-line max concurrent.
- **Edges:** disjoint; nested; many touching ends.

## 2. Intuition
Difference array on a sorted timeline: +1 at start, −1 at end; scan prefixes for max.

## 3. Brute Force → Optimal
- **Brute:** discretize all times each query.
- **Optimal:** `map` deltas; rescan O(N) per book (N≤400).

## 4. Data Structure / Approach Justification
**Chosen:** `std::map<int,int>` difference array.

- **vs segment tree:** overkill under constraints; better if N large.

## 5. Logic Walkthrough
delta[start]++; delta[end]--; scan map in order accumulating cur; track max.

## 6. Dry Run
After book(10,20),(50,60),(10,40),(5,15) max depth **3**.

## 7. Time & Space Complexity
Time **O(N)** per book with map scan (O(N log N) insert). Space **O(N)**. Why: timeline events (section 4).

## 8. Trade-offs & Alternatives
Clean sweep pattern shared with car pooling / meeting rooms II.

## 9. Common Mistakes / Edge Cases
Putting −1 at end−1; not half-open; forgetting to recompute max from scratch (incremental is trickier).

## 10. Interview Follow-ups / Variations
Car Pooling; Meeting Rooms II; Range Module.

## 11. Tags
`intervals`, `sweep-line`, `ordered-map`, `design`, `leetcode-732`, `difficulty:hard`
