# Total Cost to Hire K Workers

## 1. Problem Statement
[LeetCode 2462](https://leetcode.com/problems/total-cost-to-hire-k-workers/) — hire `k` workers. Each session, consider first `candidates` and last `candidates` remaining workers; hire the cheapest (tie → lower index). Return total cost.

## 2. Intuition
Maintain two min-heaps for the left and right candidate windows; refill from the unused middle as workers are hired.

## 3. Brute Force → Optimal
- **Brute:** each hire scan ends — O(k·candidates).
- **Optimal:** two heaps — O((N+k) log candidates).

## 4. Data Structure / Approach Justification
**Chosen:** left/right min-heaps of (cost, index); pointers grow inward.

- **vs one global heap of all:** violates session visibility rules.
- **vs sorting:** order of hiring changes availability.

## 5. Logic Walkthrough
Seed both ends. k times: pick cheaper top (tie left), pop, push next from that side if any.

## 6. Dry Run
`[17,12,10,2,7,2,11,20,8]`, k=3, candidates=4 → **11**.

## 7. Time & Space Complexity
Time **O(N log C)**. Space **O(C)**. Why: classic dual-frontier heaps (section 4).

## 8. Trade-offs & Alternatives
True two-heaps interview problem alongside median stream.

## 9. Common Mistakes / Edge Cases
Overlapping windows when n small; tie-breaking; empty side.

## 10. Interview Follow-ups / Variations
Hire with different candidate sizes per side; online costs.

## 11. Tags
`heap`, `two-heaps`, `greedy`, `leetcode-2462`, `difficulty:medium`
