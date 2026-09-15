# Time Needed to Buy Tickets

## 1. Problem Statement
[LeetCode 2073](https://leetcode.com/problems/time-needed-to-buy-tickets/) — people in a queue buy one ticket per second then go to the back if they still need more; return seconds until person `k` finishes.

- **Inputs:** `tickets[i]` = tickets person `i` wants; index `k`.
- **Output:** seconds until `k` has bought all their tickets.
- **Edges:** `k` at front; everyone needs 1; `tickets[k]` is unique max.

## 2. Intuition
Simulate the line with a queue of indices, or count without simulation: each person ahead of `k` contributes `min(tickets[i], tickets[k])`, each behind contributes `min(tickets[i], tickets[k]-1)`.

## 3. Brute Force → Optimal
- **Brute:** queue simulation second-by-second — O(N · max(tickets)).
- **Optimal:** closed-form pass — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** O(N) counting formula (queue mental model without explicit queue).

| Alternative | When |
|-------------|------|
| Explicit `queue` simulation | Teaching FIFO / interview warm-up |
| Priority queue | Wrong model — order is circular FIFO |

## 5. Logic Walkthrough
1. Let `need = tickets[k]`.
2. For `i <= k`: add `min(tickets[i], need)`.
3. For `i > k`: add `min(tickets[i], need - 1)`.

## 6. Dry Run
`tickets=[2,3,2]`, `k=2`: ahead+self → 2+2+2=6; none behind → 6.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) formula / O(N) if simulating with queue

## 8. Trade-offs & Alternatives
Simulation is clearer in interviews; formula is faster and avoids overflow of time loops.

## 9. Common Mistakes / Edge Cases
Giving people behind `k` a full `need` tickets; off-by-one when `tickets[k]==1`.

## 10. Interview Follow-ups / Variations
Josephus / circular game; supermarket checkout variants.

## 11. Tags
`queue`, `simulation`, `leetcode-2073`, `difficulty:easy`
