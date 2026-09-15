# Dota2 Senate

## 1. Problem Statement
[LeetCode 649](https://leetcode.com/problems/dota2-senate/) — senators act in order; each bans one opposing senator still in the queue. Repeat until one party remains. Return `"Radiant"` or `"Dire"`.

- **Inputs:** string `senate` of `'R'`/`'D'`.
- **Output:** winning party name.
- **Edges:** all one party; alternating; longer streak of one side.

## 2. Intuition
Earlier index bans first. Keep two queues of indices; the earlier senator bans the later and re-enters at `index + n` for the next round.

## 3. Brute Force → Optimal
- **Brute:** repeatedly scan a mutable string marking banned seats — O(N²).
- **Optimal:** two queues of live indices — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** `queue<int>` per party storing positions (plus `+n` for round wrap).

| Alternative | Why not |
|-------------|---------|
| Single deque of chars | Harder to find next opponent quickly |
| Count-only greedy | Misses position-order bans |

## 5. Logic Walkthrough
1. Push each senator’s index into R or D queue.
2. While both non-empty: pop fronts `r`,`d`; smaller index bans the other and pushes `idx+n`.
3. Non-empty queue’s party wins.

## 6. Dry Run
`"RD"`: R(0) bans D(1) → Radiant.  
`"RDD"`: R(0) bans D(1); D(2) bans R(0+3); Dire remains.

## 7. Time & Space Complexity
- **Time:** O(N) — each senator enqueued/dequeued O(1) times amortized.
- **Space:** O(N) queues.

## 8. Trade-offs & Alternatives
Simulation with a circular list is equivalent but heavier. Counting votes alone is incorrect without order.

## 9. Common Mistakes / Edge Cases
Forgetting `+n` re-entry; comparing parties by count not position; infinite loop if banned senator is not removed.

## 10. Interview Follow-ups / Variations
Josephus circle; task scheduling with cooldowns; queue-based voting sims.

## 11. Tags
`queue`, `greedy`, `simulation`, `leetcode-649`, `difficulty:medium`
