# Minimum Cost to Hire K Workers

## 1. Problem Statement
[LeetCode 857](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/) — hire exactly `k` workers. Worker `i` has `quality[i]` and `wage[i]`. Pay must be proportional to quality and each worker must get at least their wage. Minimize total pay.

## 2. Intuition
The expensive worker’s wage/quality ratio caps the group. Sort by ratio; for each possible captain ratio, pick the `k` lowest qualities among workers with ratio ≤ captain.

## 3. Brute Force → Optimal
- **Brute:** all subsets of size k — C(N,k).
- **Optimal:** sort by ratio + max-heap of qualities — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sort workers by wage/quality; max-heap keeps the k qualities under current ratio.

- **vs DP:** continuous ratios make DP awkward.
- **vs min-heap of cost:** quality sum × ratio is the closed form.

## 5. Logic Walkthrough
Sort by ratio ascending. Scan, push qualities into max-heap, trim to k, track `ratio * sumQuality`.

## 6. Dry Run
`quality=[10,20,5]`, `wage=[70,50,30]`, k=2 → cost **105**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort + heap of size ≤ k (section 4).

## 8. Trade-offs & Alternatives
Captain-ratio greedy is the standard hard-heap interview pattern.

## 9. Common Mistakes / Edge Cases
Using wage instead of quality in the heap; forgetting float precision; k=1 edge.

## 10. Interview Follow-ups / Variations
Hire at most k; add skill caps; integer-only payment.

## 11. Tags
`heap`, `greedy`, `sorting`, `leetcode-857`, `difficulty:hard`
