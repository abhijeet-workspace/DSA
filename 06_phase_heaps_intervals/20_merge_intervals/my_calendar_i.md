# My Calendar I

## Problem Statement
[LeetCode 729](https://leetcode.com/problems/my-calendar-i/) — implement `MyCalendar` with `book(start, end)`: double-bookings rejected. Half-open intervals `[start, end)`.

- **Inputs:** sequence of `book` calls.
- **Output:** `true` if booked, `false` if overlaps an existing booking.
- **Valid answer:** accept iff no intersection with stored intervals.
- **Edges:** touching endpoints (allowed); nested; identical; single booking.

## Intuition
Keep bookings ordered by start. A new `[start, end)` conflicts with the previous interval (if any) or the next interval (if any). `lower_bound(start)` finds the insertion neighbor pair.

## Brute Force → Optimal
- **Brute:** scan all booked intervals — O(N) per book.
- **Optimal:** ordered map / set — O(log N) per book.

## Data Structure / Approach Justification
**Chosen:** `std::map<int,int>` start → end.

- **vs vector + linear scan:** simpler but O(N²) total.
- **vs set of pairs:** similar; map keys starts cleanly for `lower_bound`.

## Logic Walkthrough
`it = lower_bound(start)`. Fail if `it` exists and `it->first < end`. Fail if previous exists and `prev->second > start`. Else insert.

## Dry Run
`book(10,20)` → empty → true. `book(15,25)` → next start 10? lower_bound(15) finds nothing after; prev ends 20 > 15 → false. `book(20,30)` → touches 20 → true.

## Time & Space Complexity
Each `book` **O(log N)**. Space **O(N)**. Why: tree lookup + insert (section 4).

## Trade-offs & Alternatives
TreeSet of intervals is fine. Segment tree / fenwick for range occupancy is overkill for I.

## Common Mistakes / Edge Cases
Treating `[10,20)` and `[20,30)` as overlap; exclusive vs inclusive ends; forgetting to check both neighbors.

## Interview Follow-ups / Variations
My Calendar II (triple book); III (k-booking count); merge on insert.

## Tags
`intervals`, `ordered-map`, `design`, `leetcode-729`, `difficulty:medium`
