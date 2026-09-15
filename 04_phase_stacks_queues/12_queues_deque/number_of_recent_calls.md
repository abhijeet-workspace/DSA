# Number of Recent Calls

## 1. Problem Statement
[LeetCode 933](https://leetcode.com/problems/number-of-recent-calls/) — `ping(t)` records a call at time `t`; return how many calls occurred in `[t-3000, t]`.

- **Inputs:** strictly increasing `t`.
- **Output:** count of pings in the last 3000 ms inclusive.
- **Edges:** first ping; window exactly 3000; many pings clustered.

## 2. Intuition
Only the sliding window of recent timestamps matters — drop anything older than `t-3000` from the front of a queue.

## 3. Brute Force → Optimal
- **Brute:** store all times and binary-search each ping — O(N log N) total.
- **Optimal:** queue eviction — amortized O(1) per ping.

## 4. Data Structure / Approach Justification
**Chosen:** `queue` of timestamps; front = oldest in window.

| Alternative | Why not |
|-------------|---------|
| Vector + lower_bound | Extra log factor; overkill |
| Circular fixed buffer | Window length unbounded by count |

## 5. Logic Walkthrough
1. Push `t`.
2. While `front < t - 3000`, pop.
3. Return `size`.

## 6. Dry Run
`ping(1)`→1; `ping(100)`→2; `ping(3001)`→3; `ping(3002)` drops 1 → 3.

## 7. Time & Space Complexity
- **Time:** amortized O(1) per `ping`
- **Space:** O(W) calls in the 3000 ms window

## 8. Trade-offs & Alternatives
Same pattern as hit counter with unit counts per timestamp.

## 9. Common Mistakes / Edge Cases
Exclusive vs inclusive bound (`t-3000`); assuming non-increasing times.

## 10. Interview Follow-ups / Variations
Hit counter (362); moving average; concurrent pings.

## 11. Tags
`queue`, `design`, `sliding-window`, `leetcode-933`, `difficulty:easy`
